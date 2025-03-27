## 1. In which OSL layer the Wi-Fi standard/protocol fits.

The IEEE 802.11 Wi-Fi standard operates at **Layer 1 (Physical)** and **Layer 2 (Data Link)** of the OSI model:
- **Layer 1**: Defines radio frequencies (2.4 GHz, 5 GHz, etc.), modulation, and signal transmission via radio waves.
- **Layer 2**: Manages MAC addresses, BSSIDs, and frame formatting for device communication.
	- BSSID (Basic Service Set Identifier) is a unique 48-bit MAC address used to identify a specific access point (AP) or wireless router

## 2. Can you share the Wi-Fi devices that you are using day to day life, share that device's wireless capability/properties after connecting to network. Match your device to corresponding Wi-Fi Generations based on properties

Devices commonly used are: 
 
#### a. LAPTOP
- Protocol: WIFI 6
- STEPS: 
	- `sudo apt install iw` - iw is a tool to manually configure network interface .
	- `iw dev wlp0s20f3 info` - can check for any particular network interface.
	- we can also use `iwconfig <interface_name>`, to check the respective properties.
	- `lshw -C network` - to see details of the network device.
	  ![](./img/Pasted%20image%2020250327111808.webp)
	
		
	
#### b. PHONE
- Protocol: WIFI 4
- STEPS: 
	- Enable developer options by tapping build number 7 times
	- In Developer options, enable wifi verbose logging
	- Now we can see, the logged wifi details when we tap specific network.


- Here are some details of respective WIFI generations


|                          |                  |                       |                  |                    |
| ------------------------ | ---------------- | --------------------- | ---------------- | ------------------ |
| **IEEE 802.11 Protocol** | **Release Date** | **Frequency Band(s)** | **Bandwidth**    | **Max Throughput** |
| 802.11-1997              | 1997             | 2.4                   | 22               | 2 Mbps             |
| 11b                      | 1999             | 2.4                   | 22               | 11 Mbps            |
| 11a                      | 1999             | 5                     | 20               | 54 Mbps            |
| 11g                      | 2003             | 2.4                   | 20               | 54 Mbps            |
| 11n (Wi-Fi 4)            | 2009             | 2.4/5                 | 20/40            | 600 Mbps           |
| 11ac (Wi-Fi 5)           | 2013             | 5                     | 20/40/80/160     | 6.8 Gbps           |
| 11ax (Wi-Fi 6)           | 2019             | 2.5/5                 | 20/40/80/160     | 9.6 Gbps           |
| 11ax (WiFi 6E)           | 2020             | 2.5/5/6               | 20/40/80/160     | 9.6 Gbps           |
| 11be (WiFi 7)            | 2024 (expected)  | 2.5/5/6               | 20/40/80/160/320 | 46.1 Gbps          |


## 3. What is BSS and ESS?

### BSS (Basic Service Set)
- **BSS** is the smallest unit of a Wi-Fi network, consisting of:
	- **One Access Point (AP)**
	- **Multiple Clients (Stations, STAs)**
- Each **BSS** has a unique **BSSID**, which is usually the **MAC address** of the access point.
- **Example**: If you connect your phone to **"Home_WiFi"**, it joins the BSS managed by your router.


### ESS (Extended Service Set)
- An **ESS** is a collection of multiple BSSs that share the same **SSID** to provide **seamless roaming**.
- **Multiple APs** work together.
- Clients can move between them **without reconnecting**.
- APs are linked via a **Distribution System (Ethernet, Mesh, etc.)**
- **Example**: At an **airport**, multiple APs with the same SSID ("Airport_WiFi") allow you to move around **without dropping connection**.


## 4. What are the basic functionalities of Wi-Fi Accesspoint

Some of the basic functionalities of Wi-Fi access points are:

- It supports differrent standards and provides wifi signals to allow wireless devies to connect to the internet
- Via ethernet cable, it connects to a wired network, and can also extend the network coverage without requireing additional cabling
- Broadcast SSID allowing devices to discover and connect to the internet
- Provides protections by
	- Allowing MAC address filtering 
	- Supporting security protocols like WEP, WPA, WPA2 etc
- Helps prioritise network traffic for critical applications like VOIP, video streaming and gaming
- Can create mulitple SSIDs for different user groups and can segment network traffic using VLANs


## 5. Difference between Bridge mode and Repeater mode

|**Parameter**|**Bridge Mode**|**Repeater Mode**|
|---|---|---|
|**Operation Layer**|Operates at the Data Link Layer (Layer 2) of the OSI model|Operates at the Physical Layer (Layer 1) of the OSI model|
|**Functionality**|Connects multiple LANs, facilitating communication between them|Amplifies and regenerates signals to extend network range|
|**Address Handling**|Uses MAC addresses to make forwarding decisions|Does not analyze or recognize addresses|
|**Packet Understanding**|Understands and processes complete data frames|Does not understand data frames; merely retransmits signals|
|**Collision Management**|Does not forward collisions from one segment to another|Forwards collisions, potentially causing issues on all segments|
|**Filtering Capability**|Can filter packets to reduce unnecessary traffic|Cannot filter packets; simply extends the signal|
|**Network Segmentation**|Can segment networks to improve performance and reliability|Does not segment networks; only extends coverage|
|**Configuration Complexity**|More complex setup due to MAC address tables|Simple setup with minimal configuration requirements|
|**Cost**|Generally more expensive due to advanced features|More cost-effective for extending network coverage|
|**Speed Impact**|Typically maintains network speed|May slightly reduce speed due to signal retransmission|
|**Use Case**|Best for connecting separate networks (e.g., different departments)|Ideal for extending Wi-Fi range in large areas|



## 6. What are the differences between 802.11a and 802.11b.


| Feature                            | 802.11a                                           | 802.11b                                |
| ---------------------------------- | ------------------------------------------------- | -------------------------------------- |
| Release Year                       | 1999                                              | 1999                                   |
| Frequency Band                     | 5 GHz                                             | 2.4 GHz                                |
| Maximum Data Rate                  | 54 Mbps                                           | 11 Mbps                                |
| Modulation                         | OFDM (Orthogonal Frequency Division Multiplexing) | DSSS (Direct Sequence Spread Spectrum) |
| Range                              | Shorter (higher frequency attenuates more)        | Longer                                 |
| Channel Width                      | 20 MHz                                            | 22 MHz                                 |
| Susceptibility to Interference     | Less (fewer devices in 5 GHz)                     | More (crowded 2.4 GHz band)            |
| Number of Non-overlapping Channels | 12 (in US)                                        | 3 (in US)                              |



## 7. Configure your modem/hotspot to operate only in 2.4Ghz and connect your laptop/Wi-Fi device, and capture the capability/properties in your Wi-Fi device. Repeat the same in 5Ghz and tabulate all the differences you observed during this

- Configured 2.4 Ghz and 5Ghz in my mobile hotspot settings. For wifi we can log in to the wifi settings via a web browser 192.168.1.1, and can change the appropriate setttings.
- To check which bands the device supports we can use the command
	- `iw list | grep -A 10 "Frequencies: `
- Next we can either use `iw` or `iwconfig` command in order to check the properties
	- `iwconfig wlp0s20f3`
	- `iw dev wlp0s20f3 link`
 
 ### Comparison: 
 ![](./img/Pasted%20image%2020250327111822.webp)
	


## 8. What is the difference between IEEE and WFA

- **IEEE**: Develops technical standards (e.g., 802.11a/b/g/n/ac/ax)
- **WFA**: Certifies devices for interoperability and brands generations (Wi-Fi 4/5/6)

**IEEE (Institute of Electrical and Electronics Engineers)**:
- Standards development organization
- Defines the technical specifications for 802.11 standards
- Creates the technical foundation for Wi-Fi technology
- Focuses on technical aspects and protocol definitions
- Names standards with 802.11 followed by letters (e.g., 802.11ax)

**WFA (Wi-Fi Alliance)**:
- Industry consortium of companies
- Certifies products for interoperability and compliance
- Markets Wi-Fi technology and creates user-friendly names (Wi-Fi 6 instead of 802.11ax)
- Develops additional specifications beyond IEEE (like WPA3, WMM, etc.)
- Ensures consumers can expect compatibility across certified devices


## 9. List down the type of Wi-Fi internet connectivity backhaul, share your home/college's wireless internet connectivity backhaul name and its properties


### Types of Wi-Fi Internet Connectivity Backhaul

#### a. Wired (Fixed-Line) Backhaul

- **Fiber Optic**: Offers very low latency and high capacity, ideal for meeting growing data demands.
- **Copper**: Previously common for 2G and 3G networks, now largely replaced by fiber.
- **Ethernet**: Used for local connections, allowing access points to connect to the main network.
    
#### b.Wireless Backhaul

- **Microwave**: Utilizes microwave signals for point-to-point or point-to-multipoint connections over medium to long distances.
- **Millimeter Wave (mmW)**: Provides high-capacity links over short distances, often used in 5G networks.
- **Satellite**: Used primarily in remote areas where wired connections are impractical.
- **Wi-Fi Mesh Networks**: Employ multiple access points that connect wirelessly, enhancing coverage and flexibility without requiring extensive cabling.


#### Example of Home/College Wireless Internet Connectivity Backhaul

#### a. Usually in hostels and schools **Wi-Fi mesh network** is the internet connectivity backhaul: 
- **Flexibility**: Easily extendable coverage across campus without significant infrastructure changes.
- **Scalability**: Additional access points can be added as needed to accommodate more users or areas.
- **Cost-Effectiveness**: Reduces the need for extensive cabling, making it a financially viable option for large spaces.
- **Performance**: Capable of supporting high bandwidth demands typical in educational settings.

#### b. At homes, since there is only 1 access point or the router which directly connects to the internet, `Ethernet` is used as the backhaul.



## 10.  List down the Wi-Fi topologies and use cases of each one.

#### a.Infrastructure Mode
- The most common Wi-Fi topology, used in homes, offices, and public networks.
- Components: Includes Wi-Fi clients (laptops, phones) and an Access Point (AP) (e.g., a router).
- Operation: Devices connect to the AP, which manages communication and connects them to the internet or LAN.
- Use case: Home Wi-Fi router providing internet to multiple devices.

#### b. Ad-Hoc Mode (Peer-to-Peer)
- A decentralized network where devices communicate directly without an AP.
- Components: Wi-Fi-enabled devices acting as both clients and routers.
- Operation: Devices form a temporary network for local communication.
- Use case: File sharing between laptops via Wi-Fi Direct.

#### c. Mesh Network
- A decentralized topology where multiple nodes (routers or devices) relay data dynamically.
- Components: Multiple interconnected nodes, where each node acts as a relay.
- Operation: If one node fails, data is rerouted through another, ensuring high reliability.
- Use case: Smart home IoT networks or city-wide public Wi-Fi.

| **Wi-Fi Topology**      | **Description**                                                                                                            | **Use Cases**                                                                                                                                            |
| ----------------------- | -------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Infrastructure Mode** | Involves a central access point (AP) that connects wireless clients to a network. Each client communicates through the AP. | Common in homes and offices, providing reliable connectivity and allowing devices to roam freely within the network coverage area.                       |
| **Ad Hoc (IBSS) Mode**  | A peer-to-peer network where devices connect directly without an AP.                                                       | Useful for temporary networks, such as file sharing between devices in close proximity or during events where quick setup is needed.                     |
| **Mesh Topology**       | Multiple APs interconnect wirelessly to extend coverage and ensure redundancy.                                             | Ideal for large areas requiring extensive coverage, such as campuses, smart cities, or venues where consistent connectivity is needed despite obstacles. |
 
---




