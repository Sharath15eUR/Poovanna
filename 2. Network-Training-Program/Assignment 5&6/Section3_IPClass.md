 
## 1.You are given three IP addresses: 10.1.1.1, 172.16.5.10, and 192.168.1.5. Task: Identify the class of each IP address (Class A, B, or C). What is the default subnet mask for each class? Provide the range of IP addresses for each class.

- 10.1.1.1    - CLASS A
- 172.16.5.10 - CLASS B
- 192.168.1.5 - CLASS C

	There are 5 classes of IP address
	- ![](./img/Pasted%20image%2020250314214701.webp)


---

### 2. You are given three IP addresses: 192.168.10.5, 172.20.15.1, and 8.8.8.8. Identify the class of each IP address. Determine if it is private or public. Explain how NAT would handle a private IP when accessing the internet.



- 192.168.10.5 - CLASS C - private
- 172.20.15.1 - Class B - private
- 8.8.8.8 - CLASS A - public

	PRIVATE IP RANGE FOR
	CLASS A - 10.0.0.0 to 10.255.255.255
	CLASS B - 172.16.0.0 to 172.31.255.255
	CLASS C - 192.168.0.0 to 192.168.255.255


When a device with a private IP address accesses the internet, Network Address Translation (NAT) acts as an intermediary, allowing multiple private IP addresses to share a single public IP address. Here's how it works:

1. Outbound traffic process:
    
    - A device with a private IP (e.g., 192.168.1.10) sends a request to a public website
    - The request reaches the NAT device (typically a router)
    - The NAT device replaces the source IP address (private) with its own public IP address
    - The NAT device also modifies the source port number and creates an entry in its translation table
    - The modified packet is sent to the internet
2. Translation table tracking:
    
    - The NAT device maintains a table mapping:
        - Original private IP address and port
        - Translated public IP address and port
        - Destination IP address and port
3. Inbound traffic process:
    
    - When the response arrives from the internet
    - The NAT device looks up the destination port in its translation table
    - It identifies which private IP made the original request
    - The NAT device replaces the destination address with the private IP
    - The packet is forwarded to the correct internal device
4. Types of NAT:
    
    - Static NAT: One-to-one mapping between private and public IPs
    - Dynamic NAT: Uses a pool of public IPs assigned as needed
    - PAT (Port Address Translation)/NAT Overload: Most common type, where many private IPs share one public IP by using different ports

This process allows organizations to use private IP addresses internally while maintaining connectivity to the internet through a limited number of public IP addresses, which helps conserve the IPv4 address space.


### Types of NAT

![](./img/Pasted%20image%2020250318163501.webp)
___
