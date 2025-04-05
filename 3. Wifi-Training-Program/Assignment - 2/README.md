## 1. Brief about SplitMAC architecture and how it improves the AP's performance

SplitMAC is an architectural approach for wireless networks that improves access point (AP) performance by dividing MAC (Media Access Control) layer functions between the access point and a central controller.

In traditional wireless networks, each AP handles all MAC functions independently. SplitMAC redistributes these responsibilities, with time-sensitive functions remaining on the AP while management and control functions move to a centralized controller.

### Key Components

- **Access Points**: Handle real-time, time-sensitive MAC operations (frame transmission, acknowledgments, retransmissions)
- **Central Controller**: Manages non-time-critical functions (authentication, association, bandwidth allocation)

### Performance Improvements

SplitMAC architecture improves AP performance through:

1. **Reduced Processing Load**: APs focus only on time-critical functions, freeing resources
2. **Centralized Management**: Network-wide decisions are made with global visibility
3. **Simplified APs**: Less complex hardware requirements at the edge
4. **Scalability**: Easier to add APs without management overhead
5. **Consistent Policies**: Security and QoS policies applied uniformly across the network

### Implementation Models

SplitMAC is implemented in various wireless technologies including:

- Cloud-managed Wi-Fi solutions
- Software-Defined Networking (SDN) approaches for wireless
- Enterprise WLAN controllers
- Some 5G small cell deployments

This architecture has become particularly important as wireless networks grow in complexity and density, allowing for more efficient resource utilization and improved coordination across multiple access points.

The SplitMAC architecture divides the traditional MAC (Media Access Control) layer functionality between access points and a central controller in a structured way to optimize network performance. Below is an explanation of how the splitMAC architecture works.

### Physical Architecture

1. **Access Points (APs)**
    
    - Distributed throughout the network coverage area
    - Connected to a central controller via wired backhaul (typically Ethernet)
    - Handle the physical radio transmissions
    - Execute time-sensitive MAC operations
2. **Central Controller**
    
    - Usually a server or specialized network appliance
    - Connected to multiple APs
    - Maintains a global view of the entire wireless network
    - Makes network-wide decisions

### Functional Division

The MAC layer functionality is split based on time sensitivity and scope:

1. **Functions at Access Points**

- Frame transmission/reception: Direct radio interface operations
- Acknowledgments: Immediate packet reception confirmations
- Retransmissions: Quick resending of lost packets
- RTS/CTS handling: Real-time collision avoidance
- Physical carrier sensing: Monitoring the wireless medium
- Immediate power management: Per-frame power control

2. **Functions at Central Controller**

- Authentication and security: User verification and encryption key management
- Association/disassociation: Managing client connections
- Roaming coordination: Seamless handoffs between APs
- Load balancing: Distribution of clients across APs
- Channel allocation: Frequency planning across the network
- Transmit power control: Global RF power optimization
- QoS policy enforcement: Network-wide quality of service
- Interference management: Coordinated interference mitigation



## 2. Describe about CAPWAP , explain the flow between AP and Controller

CAPWAP (Control And Provisioning of Wireless Access Points) is a protocol that enables centralized management of wireless access points (APs) by a WLAN controller. It was standardized by the IETF to address the need for a common protocol for communication between wireless controllers and APs, promoting interoperability between different vendors' equipment.

### Key Characteristics of CAPWAP

- split MAC Architecture: Divides traditional AP functions between the AP (for real-time operations) and the controller (for management and non-real-time operations)
- Tunneling Protocol: Creates tunnels between APs and controllers to transport both control and data traffic
- Standardized Approach: Designed to replace proprietary protocols like LWAPP
- Secure Communications: Provides encryption and authentication between APs and controllers

### CAPWAP Flow Between AP and Controller

The communication flow between an AP and a controller using CAPWAP typically follows these steps:

1. **Discovery Phase**

- The AP begins by trying to locate a controller using one or more discovery methods:

    - DHCP Option 43: The AP receives controller IP addresses from a DHCP server
    - DNS Discovery: The AP performs a DNS lookup for a predefined controller name
    - Static Configuration: Using previously configured controller information
    - Local Broadcast: The AP sends discovery requests on the local subnet
    - Multicast Discovery: The AP sends discovery requests to a multicast address

2. **DTLS Security Establishment**

- Before exchanging sensitive information, the AP and controller establish a secure DTLS (Datagram Transport Layer Security) session
- The controller and AP authenticate each other using X.509 certificates or pre-shared keys

3. **Join Phase**

- The AP sends a Join Request to the selected controller
- The controller evaluates the request based on its configuration and policies
- If accepted, the controller responds with a Join Response
- At this point, the control channel is established (UDP port 5246)

4. **Configuration Phase**

- The controller sends configuration parameters to the AP including:
    - SSID information
    - Security settings
    - Radio parameters (channels, power levels)
    - QoS configurations
    - Management policies

5. **Run Phase**

- The data tunnel is established (UDP port 5247)
- The AP begins normal operation, forwarding traffic and applying policies
- The AP continuously monitors its environment and client connections
- The control channel is used for ongoing management and status updates

6. **Keep-alive and Monitoring**

- Echo Request/Response messages are exchanged periodically to ensure connectivity
- The AP sends status updates, statistics, and event notifications to the controller
- The controller may send updated configurations or commands as needed

7. **Failover Handling**

- If the primary controller fails, the AP may switch to a backup controller
- The AP maintains a list of controllers with priorities for failover scenarios

Throughout this process, the AP and controller maintain both the control and data tunnels, with the control tunnel handling management traffic and the data tunnel carrying encapsulated client data frames.


## 3. Where this CAPWAP fits in OSI model , what are the two tunnels in CAPWAP and its purpose?

CAPWAP (Control And Provisioning of Wireless Access Points) operates primarily across multiple layers of the OSI model, with its main components functioning at Layer 2 (Data Link) and Layer 3 (Network).

In the OSI model, CAPWAP specifically works as follows:
- The CAPWAP control messages operate at Layer 3 (Network layer)
- The CAPWAP data encapsulation occurs at Layer 2 (Data Link layer)

CAPWAP uses two distinct tunnels:

1. **Control Tunnel**:
    
    - Uses UDP port 5246
    - Handles management, control, and configuration of access points
    - Carries commands from the controller to APs and status information from APs to the controller
    - Responsible for AP discovery, configuration, firmware management, and monitoring

2. **Data Tunnel**:
    
    - Uses UDP port 5247
    - Carries the actual user traffic (data frames) between the wireless client and the network
    - Encapsulates 802.11 frames for transport across the IP network
    - Allows centralized data processing at the controller

The purpose of this dual-tunnel architecture is to create a split-MAC architecture that centralizes wireless network management while maintaining efficient data forwarding. This separation allows the system to:

- Centralize control functions at the controller
- Distribute data forwarding functions as needed
- Provide scalable management of multiple access points
- Enable consistent policy enforcement across the wireless network
- Simplify AP deployment through zero-touch provisioning

This architecture is particularly valuable in enterprise networks where centralized management of numerous access points is required.


## 4. Whats the difference between Lightweight APs and Cloud-based APs

### 1. Lightweight Access Points (LAPs)

Lightweight APs are designed to work with on-premises wireless LAN controllers (WLCs) and feature:

**Architecture:**

- Split MAC architecture - control functions run on the controller
- Dependent on local controllers for management and control plane functions
- Typically use CAPWAP protocol to communicate with controllers

**Management:**

- Managed by physical or virtual controllers within your network
- Configuration done via the controller's management interface
- Firmware updates pushed from the controller

**Deployment:**

- Ideal for large, centralized campuses
- Requires significant upfront infrastructure investment
- Lower ongoing subscription costs

**Scalability:**

- Limited by controller capacity and licensing
- Often requires controller redundancy planning
- Scale-out typically requires additional controller hardware


### 2. Cloud-based APs

Cloud-based APs connect to cloud-hosted management platforms and offer:

**Architecture:**

- Management plane in the cloud, control plane can be distributed
- Can operate independently of cloud connection
- Often use secure tunnels (HTTPS/WebSockets) to cloud platforms

**Management:**

- Managed through cloud-based dashboards
- Zero-touch provisioning via cloud registration
- Automatic firmware updates from cloud

**Deployment:**

- Ideal for distributed sites and multi-location businesses
- Minimal on-premises infrastructure required
- Subscription-based pricing model

**Scalability:**

- Virtually unlimited scalability through cloud infrastructure
- No need for local controller upgrades when expanding
- Easily support distributed geographical deployments


### Key Differences

1. **Cost Structure:** Lightweight APs have higher upfront costs but lower recurring costs; Cloud APs have lower initial costs but ongoing subscription fees
2. **Dependency:** Lightweight APs depend on local controllers; Cloud APs rely on internet connectivity for management
3. **Reliability:** Lightweight APs may offer more consistent performance in unstable internet environments
4. **Management Overhead:** Cloud APs generally require less IT expertise and offer simpler management interfaces
5. **Feature Updates:** Cloud platforms typically deliver new features more rapidly than controller-based systems
    


## 5. How the CAPWAP tunnel is maintained between AP and controller

The Control and Provisioning of Wireless Access Points (CAPWAP) protocol establishes and maintains tunnels between wireless access points and their controllers through several mechanisms:

### Initial Establishment

1. **Discovery Phase**:
    
    - AP broadcasts discovery requests or uses DNS/DHCP options to find potential controllers
    - AP sends discovery request to controller(s)
    - Controller(s) respond with discovery response
      
2. **Join Phase**:
    
    - AP selects a controller and sends a join request
    - Controller authenticates the AP (using certificates or pre-shared keys)
    - Upon successful authentication, secure tunnel is established

### Tunnel Maintenance

1. **Heartbeat/Keep-alive Mechanism**:
    
    - CAPWAP maintains tunnel integrity through periodic echo requests/responses
    - Default heartbeat interval is typically 30 seconds
    - If multiple heartbeats are missed (usually 3-5), the tunnel is considered down
      
2. **Dual Tunneling**:
    
    - Control tunnel: UDP port 5246, encrypted with DTLS
    - Data tunnel: UDP port 5247, can be encrypted or unencrypted
    - Both tunnels must be operational for proper functioning
      
3. **Prioritization**:
    
    - Control tunnel traffic is prioritized over data tunnel traffic
    - Control messages use DSCP marking for QoS
      
4. **Failover Handling**:
    
    - If primary tunnel fails, AP attempts to maintain or reestablish connection
    - AP may switch to secondary controller if configured
    - In FlexConnect deployments, AP can operate in standalone mode if tunnel fails
      
5. **MTU Considerations**:
    
    - CAPWAP adjusts for MTU limitations across the network
    - Fragmentation and reassembly mechanisms handle oversized packets
      
6. **NAT Traversal**:
    
    - CAPWAP includes NAT detection and traversal capabilities
    - Maintains connection even through NAT boundaries

The robustness of this tunnel maintenance process ensures that wireless networks remain operational even under challenging network conditions between APs and controllers.


## 6. Whats the difference between Sniffer and monitor mode , use case for each mode

### 1. Sniffer Mode

Sniffer mode configures an access point to capture and forward packets to an external packet analyzer (like Wireshark) running on a specific machine. Some of the key characterisitics include: 
- Forwards all wireless frames to a dedicated packet capture server
- Requires specifying the IP address and port of the packet analyzer
- The AP continues to serve clients while in sniffer mode
- Focused on targeted troubleshooting scenarios

Use cases of sniffer mode include:
- Directed troubleshooting of specific wireless issues
- Security auditing and wireless intrusion detection
- Diagnosing client connectivity problems
- Performance analysis of specific wireless traffic patterns
- When you need to capture packets remotely without being physically present

### 2. Monitor Mode

Monitor mode configures an access point to capture all wireless frames but doesn't forward them to an external analyzer. The AP becomes a passive listener on a specific channel. Some of its characteristics include:
- The AP stops serving clients and dedicates itself to monitoring
- Captures all frames on the configured channel(s)
- No data forwarding functionality while in this mode
- More comprehensive monitoring but requires local analysis

Uses cases of monitor mode include:
- Site surveys and RF environment analysis
- Rogue AP and unauthorized device detection
- Comprehensive wireless spectrum analysis
- Wireless network security research
- When you need a dedicated channel monitoring solution


The key difference of sniffer and monitor mode include: 
1. **Client service**: Sniffer mode can continue serving clients; monitor mode typically cannot
2. **Data handling**: Sniffer mode forwards packets to a remote analyzer; monitor mode requires local collection
3. **Deployment impact**: Sniffer mode has less impact on production network; monitor mode takes the AP offline
4. **Coverage**: Monitor mode is often more thorough in capturing all wireless frames
5. **Ease of implementation**: Sniffer mode is typically easier to configure in enterprise WLCs



## 7. If WLC deployed in WAN, which AP mode is best for local network and how?

When deploying Wireless LAN Controllers (WLC) in a Wide Area Network (WAN) environment, the best Access Point (AP) mode for local network connectivity is typically FlexConnect mode (also known as H-REAP in older systems).

FlexConnect mode is optimal for WAN deployments because:

1. It allows APs to switch client data traffic locally at the branch site, reducing WAN bandwidth consumption
2. It maintains control and management traffic with the central WLC over the WAN link
3. If the WAN link fails, the APs can continue functioning in standalone mode, maintaining local wireless connectivity

To implement FlexConnect mode effectively:

1. Configure FlexConnect groups to manage collections of APs in the same branch
2. Set up local authentication fallback for WAN outages
3. Configure local VLAN mapping appropriate to your branch network architecture
4. Enable efficient QoS settings to prioritize critical traffic across the WAN link


## 8. What are challenges if deploying autonomous APs (more than 50) in large network like university


Deploying a large number of autonomous access points in a university setting presents several significant challenges:

### Scaling Issues

- **Individual Management**: Each autonomous AP requires separate configuration and management, creating administrative overhead
- **Firmware Updates**: Rolling out updates across 50+ devices becomes time-consuming and prone to inconsistencies
- **Configuration Changes**: Policy changes must be applied to each AP individually

### Network Performance

- **Channel Interference**: Without centralized coordination, APs may select overlapping channels, causing co-channel interference
- **Client Roaming**: Poor handoffs between autonomous APs can disrupt connectivity when users move across campus
- **Load Balancing**: Autonomous APs lack built-in capabilities to distribute client loads effectively

### Security Challenges

- **Consistent Policy Enforcement**: Difficult to ensure uniform security policies across all devices
- **Vulnerability Management**: Increased attack surface with each AP potentially becoming a security entry point
- **Rogue AP Detection**: Limited ability to identify unauthorized devices on the network

### Infrastructure Requirements

- **Power Distribution**: Ensuring proper PoE infrastructure for wide deployment
- **Backhaul Connectivity**: Providing adequate wired infrastructure to support all APs
- **Physical Security**: Protecting devices from tampering across large campus environments

An alternative approach to deploying autonomous APs in large university networks is to adopt **centralized wireless network management**. This approach addresses the challenges of scalability, security, and operational efficiency. Below are the key features and benefits of centralized solutions. Technologies usually used are:
- **Wireless LAN Controllers (WLCs):** Devices that centralize the management of multiple APs.
- **Cloud-Based Solutions:** Platforms like Juniper Mist or Cisco Meraki offer advanced analytics, AI-driven insights, and remote control capabilities.
- **Unified Network Architectures:** Systems that combine wired and wireless management for seamless operations.


## 9. What happens on wireless client connected to Lightweight AP in local mode if WLC goes down.

If a Wireless LAN Controller (WLC) goes down while a lightweight access point (AP) is operating in _local mode_, the wireless clients connected to the AP will lose connectivity. This happens because, in local mode, all client traffic is centrally switched through the WLC via a CAPWAP tunnel. The AP relies on the WLC for authentication, association processing, and traffic forwarding. Without the WLC, these functions cannot be performed, and the AP stops transmitting to clients

