### 1. Use Wireshark to capture and analyze DNS, TCP, UDP traffic and packet header, packet flow, options and flags
	
### DNS

- Can use dig or nslookup to send and receive dns packets.
- Amongst the below 2 captured packets:
	- The first one is a DNS request query
	- The second one is a DNS response
	![[Pasted image 20250316104248.webp|1178]]
	
- The header consists of the source,destination address, payload length, checksum etc
	![[Pasted image 20250316104522.webp]]
	![[Pasted image 20250316104813.webp]]
	![[Pasted image 20250316104740.webp]]- 
	- Here we can see that a pair of DNS request-response were sent: ![[Pasted image 20250316105109.webp]]
	1. When we use nslookup, it typically performs multiple queries to get complete information about a domain.
	2. The first query is specifically looking for the IPv4 address (A record) of [www.vit.ac.in](http://www.vit.ac.in)
	3. The second query is looking for the IPv6 address (AAAA record) of the bare domain vit.ac.in
	4. Since there might not be an IPv6 record available, the server returned an SOA (Start of Authority) record instead.
	This dual-query approach is common in modern DNS clients which check for both IPv4 and IPv6 connectivity options.

---

### TCP

- apply filter tcp
- PACKET HEADER : We can see the type of addressing used, the source and destination address , the protocol used 
	 ![[Pasted image 20250316103233.webp]]
- OPTIONS
	 ![[Pasted image 20250316103503.webp]]
	- 
- FLAGS
	![[Pasted image 20250316103432.webp]]

- Can right click and select FOLLOW to check packet flow
	![[Pasted image 20250316103059.webp]]


---

### UDP

![[Pasted image 20250316103800.webp]]
![[Pasted image 20250316103820.webp]]

![[Pasted image 20250316103856.webp]]

---
