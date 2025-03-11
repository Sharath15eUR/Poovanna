# Linux Kernel Handling of Ethernet devices and network interfaces


## Overview of Ethernet Communication in Linux

The Linux kernel provides a robust framework for managing Ethernet devices and facilitating network communication. Ethernet communication involves several layers, from hardware interaction to protocol handling.

## Network Interface Representation

### 1. struct net_device

- The core representation of a network interface in the Linux kernel is the `struct net_device`.
- This structure contains all the necessary information about the network device, including its name, state, statistics, and pointers to driver-specific functions.
    

### 2. Device Initialization

- When a network driver is loaded, it allocates a `net_device` structure using `alloc_netdev()` or `alloc_netdev_mqs()` (for multi-queue devices).
- Example:
    `struct net_device *dev = alloc_netdev(0, "eth%d", NET_NAME_UNKNOWN, ether_setup);`

## Device Operations

The kernel defines several key operations that drivers must implement to interact with the networking stack:
- **Open/Close**:
    - `ndo_open`: Called to bring the device up.
    - `ndo_stop`: Called to take the device down.
- **Transmit**:
    - `ndo_start_xmit`: Responsible for sending packets.
- **Receive**:
    - Handling incoming packets is typically done through interrupt service routines or polling mechanisms.
        

## Packet Transmission

### 1. Sending Data
When an application wants to send data over a network:
1. **Socket Layer**: The application uses sockets to send data.
2. **Networking Stack**: The data is passed down through various layers (TCP/IP stack) until it reaches the device driver.
    1. **Driver Interaction**:
    - The driver prepares the packet for transmission by filling out descriptors and invoking `ndo_start_xmit`. By invoking this function it is sent to the NIC
    - Example of packet transmission:
        `int result = dev_queue_xmit(skb); // skb is the socket buffer containing data.`
        
### 2. Offloading Features
Modern NICs support offloading features that reduce CPU load:
- **TCP Segmentation Offload (TSO)**: Allows large TCP packets to be sent without fragmentation by the CPU.
- **Generic Segmentation Offload (GSO)**: Similar to TSO but works with various protocols.
    

## Packet Reception

### 1. Packet Transmission Triggered
- When the Linux kernel wants to transmit a packet, it calls the `ndo_start_xmit` function, which is part of the `net_device_ops` structure in the driver. This function is responsible for starting the transmission process at the hardware level
- The packet to be transmitted is encapsulated in a `struct sk_buff` (socket buffer), which contains both the data and metadata about the packet (e.g., protocol type, length).
    

### 2. Queue Management
- Before transmitting, the kernel checks whether the NIC's transmission queue has space available:
    - **Queue Stopped**: If the queue is full, the driver uses `netif_stop_queue()` to stop further enqueueing of packets.
    - **Queue Resumed**: Once space becomes available, `netif_wake_queue()` is called to resume packet transmission.
- If the queue is ready, the driver proceeds with transmission.
    

### 3. Packet Preparation
- The driver prepares the packet for transmission:
    - **DMA Mapping**: The driver maps the packet's memory (from `sk_buff`) to a specific location in physical memory using DMA (Direct Memory Access). This ensures that the NIC can access the data directly without CPU intervention.
    - **Descriptor Setup**: The driver sets up DMA descriptors that point to the mapped memory. These descriptors inform the NIC where to find the data and how much data to transmit.
        

### 4. Adding Packet to TX Ring
- The packet is added to the NIC's TX ring buffer:
    - The TX ring is a circular buffer in hardware or memory where packets are queued for transmission.
    - The driver writes metadata (e.g., packet length, flags) and updates indices in the descriptor ring to track which packets have been queued for transmission.
        

### 5. NIC Transmission Initiation
- After adding packets to the TX ring, the driver notifies the NIC that new data is ready for transmission:
    - This is typically done by writing to a hardware register or triggering an interrupt on the NIC.
    - The NIC begins fetching data from memory using DMA and starts transmitting it on the wire.
        

### 6. Post-Transmission Cleanup
- Once a packet has been successfully transmitted:
    - The NIC generates an interrupt or updates its status registers to notify the driver.
    - The driver processes this notification by freeing up resources associated with the transmitted packet (e.g., unmapping DMA memory and freeing `sk_buff`).
    - The TX ring buffer indices are updated to reflect that space has been freed.
        
### 7. NAPI Polling for Incoming Packets

- When packets arrive at the NIC, they are initially handled by an interrupt-driven mechanism:
    - The NIC generates an interrupt to notify that new packets have arrived.
    - In a NAPI-enabled driver, instead of processing each packet immediately within an interrupt handler (which can overwhelm CPU resources during high traffic), further processing is deferred using polling.
        
NAPI, or New API, is a crucial component of the Linux kernel's networking stack designed to optimize the handling of network packets. It serves as an event handling mechanism for network devices, aiming to enhance performance and efficiency, particularly in high-speed networks. Here’s a detailed overview of NAPI:

1. Inside the interrupt handler, further "packet arrival" interrupts are disabled.
2. The kernel schedules a poll function by calling `napi_schedule()`. This ensures that all pending packets are processed in batches instead of one-by-one.
3. The driver's poll function retrieves packets from hardware buffers or DMA rings and processes them efficiently.
    
### 8. Error Handling
- If an error occurs during transmission (e.g., hardware failure or link down):
    - The driver may reset the TX ring or reinitialize hardware.
    - For transient errors like queue full conditions, `NETDEV_TX_BUSY` may be returned from `ndo_start_xmit`, signaling that transmission should be retried later.
        

## Interface State Management

### 1. Administrative vs Operational State

The Linux kernel maintains two states for network interfaces:
- **Administrative State**: Controlled by user commands (e.g., bringing an interface up or down).
- **Operational State**: Reflects actual connectivity (e.g., whether a cable is plugged in).
    

### 2. State Management Functions

- The kernel uses flags within `net_device` to track these states:
    - `IFF_UP`: Indicates if the interface is administratively up.
    - `IFF_RUNNING`: Indicates if the interface is operationally ready.
        
### 3. State Transition Example

When an interface is brought up:
1. The user executes a command like `ip link set dev eth0 up`.
2. The command invokes the driver's `ndo_open` function.
3. The driver performs initialization tasks (e.g., starting DMA channels) and sets appropriate flags.
   

##  Error Handling and Recovery

If an error occurs (e.g., link failure), drivers can implement recovery mechanisms by resetting hardware or reinitializing interfaces based on specific conditions defined in their error handling routines.





