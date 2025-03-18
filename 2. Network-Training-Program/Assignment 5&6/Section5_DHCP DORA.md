
## 1.  Use Wireshark to capture DHCP Discover, Offer, Request, and Acknowledge messages and explain the process.


- Since our network ip are already configured, we can renew it to capture new packets
- We can renew the ip using the following commands
```
sudo dhclient -r <interface_name>
sudo dhclient <interface_name>
```
- This will drop the given IP and will renew it.

- Below are the captured packets
![](./img/Pasted%20image%2020250315181826.webp)


---

# DHCP DORA Process Analysis

## 1. DISCOVER (Packet #1034)

The client device broadcasts from 0.0.0.0 to 255.255.255.255, essentially asking: "I need an IP address. Any DHCP servers available?"

- Contains the client's MAC address
- Includes transaction ID 0x91efd400 to track this specific request
- May include optional preferences like hostname or preferred IP

## 2. OFFER (Packet #1035)

The DHCP server (192.168.171.89) responds to the client saying: "I can assign you 192.168.171.226"

- Uses the same transaction ID for tracking
- Offers specific IP address (192.168.171.226)
- Includes other network settings: subnet mask, gateway, DNS servers
- Specifies how long the device can use this IP (lease duration)

## 3. REQUEST (Packet #1037)

The client broadcasts again to everyone (255.255.255.255): "I accept the IP address 192.168.171.226 from server 192.168.171.89"

- Broadcasting lets any other DHCP servers know this offer was accepted
- Maintains the same transaction ID for continuity
- This is a formal acceptance of the offered address

## 4. ACKNOWLEDGE (Packet #1038)

The DHCP server sends final confirmation: "This IP address is officially yours for the lease period"

- Confirms all configuration parameters
- Finalizes the lease time information
- Completes the transaction using the same ID


---



