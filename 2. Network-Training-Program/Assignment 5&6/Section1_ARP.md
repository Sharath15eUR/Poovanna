	
## 1. Capture and analyze ARP packets using Wireshark. Inspect the ARP request and reply frames, and discuss the role of the sender's IP and MAC address in these packets.

In L2, communication takes place using MAC address
	- The sender wishes to know the recipient's MAC address.
	- Knowing the recipient's IP address, its sends an ARP request along with sender MAC and IP address.
	- By sending MAC address, it helps the recipient to send back the ARP response with its MAC address.
	- By sending the IP address, it also helps the recipient to update its ARP cache for future use.
	
ARP REQUEST
	![](./img/Pasted%20image%2020250315152941.webp)
	![](./img/Pasted%20image%2020250315153022.webp)

ARP RESPONSE
	![](./img/Pasted%20image%2020250315152953.webp)
	![](./img/Pasted%20image%2020250315153034.webp)


---


## 2. 1. Capture and analyze ARP packets using Wireshark. Inspect the ARP request and reply frames when your device attempts to find the router's MAC address.
    Discuss the importance of ARP in packet forwarding.


- Connected to mobile hotspot
- The difference would be that router's ip address will have 1 or 2 as the host address, like 192.168.184.1
- But the working will be the same.

- In L2, communication takes place using MAC address
- The sender wishes to know the recipient's MAC address.
- Knowing the recipient's IP address, its sends an ARP request along with sender MAC and IP address.
- By sending MAC address, it helps the recipient to send back the ARP response with its MAC address.
- By sending the IP address, it also helps the recipient to update its ARP cache for future use.

ARP REQUEST
	![](./img/Pasted%20image%2020250315152941.webp)
	![](./img/Pasted%20image%2020250315153022.webp)

ARP RESPONSE
	![](./img/Pasted%20image%2020250315152953.webp)
	![](./img/Pasted%20image%2020250315153034.webp)



### Important of ARP in packet forwarding

ARP (Address Resolution Protocol) plays a critical role in packet forwarding by bridging the gap between layer 3 (network layer) and layer 2 (data link layer) of the OSI model. 

1. IP-to-MAC address mapping: ARP resolves IP addresses to MAC addresses, which is essential because while IP addresses route packets between networks, MAC addresses are needed for actual frame delivery on a local network.
2. Local network communication: When a device needs to communicate with another device on the same network, it needs the destination's MAC address. ARP provides this translation.
3. Default gateway communication: When sending packets to devices on different networks, a host must first forward the packet to its default gateway. ARP resolves the gateway's MAC address.
4. Caching: Devices maintain an ARP cache (ARP table) of recently resolved addresses, improving efficiency by reducing the need for repeated ARP requests.
5. Dynamic discovery: ARP enables devices to automatically discover the MAC addresses of other devices on the network without manual configuration.
6. Packet forwarding process:
    - Device checks if destination IP is on local network
    - If local, device uses ARP to find destination MAC address
    - If remote, device uses ARP to find default gateway's MAC address
    - Layer 2 header is created with appropriate MAC addresses
    - Packet can then be forwarded properly

---

