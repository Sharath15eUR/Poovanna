### Capture packets using wireshark to analyze ethernet frames and MAC addressing.Inspect the structure of the frame including destination and source MAC addresses, ethertype, payload and FCS
#



**1. Capturing ICMP packets sent and received during ping operations***
	![](./img/Pasted%20image%2020250309123344.webp)


2. Structure of the Ethernet frame
Meaning of the above Ethernet frame:
	- **`00 00`:** Protocol Type (usually zero for Ethernet)
	- **`00 01`:** Hardware Type (ARPHRD_ETHER)
	- **`00 06`:** Length of MAC address (6 bytes)
	- **`7a 17 84 24 c4 d6`:** Destination MAC address. 
	- **`00 00`:** Ethernet Type/Length Field (Protocol Type).      
	- **`08 00`:** EtherType. `0x0800` indicates IPv4.
- the last selected portion shows the 40 bytes payload
- source MAC address is usually visible just after the MAC size...also can check using:
	`arp -a`
- **FCS - Frame Check Sequence:**
	- This is a 4 byte field located at the end of the ethernet frame. , and is used for error correction. Using Cyclic Redundancy Check ( CRC ), the sender claculates CRC values and places it in this section. The receiver recalculated the CRC of the received payload, and by comparing it with the previous one, will check for errors and integrity of the message.
