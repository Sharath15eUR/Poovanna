## 1. Use Wireshark to capture and analyze DNS, TCP, UDP traffic and packet header, packet flow, options and flags
	
### DNS

- Can use dig or nslookup to send and receive dns packets.
- Amongst the below 2 captured packets:
	- The first one is a DNS request query
	- The second one is a DNS response
	![](./img/Pasted%20image%2020250316104248.webp)
	
- The header consists of the source,destination address, payload length, checksum etc
	![](./img/Pasted%20image%2020250316104522.webp)
	![](./img/Pasted%20image%2020250316104813.webp)
	![](./img/Pasted%20image%2020250316104740.webp)
	- Here we can see that a pair of DNS request-response were sent: ![](./img/Pasted%20image%2020250316105109.webp)
	1. When we use nslookup, it typically performs multiple queries to get complete information about a domain.
	2. The first query is specifically looking for the IPv4 address (A record) of [www.vit.ac.in](http://www.vit.ac.in)
	3. The second query is looking for the IPv6 address (AAAA record) of the bare domain vit.ac.in
	4. Since there might not be an IPv6 record available, the server returned an SOA (Start of Authority) record instead.
	This dual-query approach is common in modern DNS clients which check for both IPv4 and IPv6 connectivity options.

---

### TCP

- apply filter tcp
- PACKET HEADER : We can see the type of addressing used, the source and destination address , the protocol used 
![](./img/Pasted%20image%2020250316103233.webp)

#### OPTIONS
![](./img/Pasted%20image%2020250316103503.webp)
	
#### FLAGS
![](./img/Pasted%20image%2020250316103432.webp)

- Can right click and select FOLLOW to check packet flow
	![](./img/Pasted%20image%2020250316103059.webp)


---

### UDP

![](./img/Pasted%20image%2020250316103800.webp)
![](./img/Pasted%20image%2020250316103820.webp)

![](./img/Pasted%20image%2020250316103856.webp)

---
