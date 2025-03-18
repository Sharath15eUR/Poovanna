### 1. Using Packet Tracer, simulate an ARP spoofing attack. Analyze the behavior of devices on the network when they receive a malicious ARP response.

- Simulated using 2 subnets
- ![](./img/Pasted%20image%2020250315161624.webp)

ARP-CACHE of VICTIM SYSTEM
- ![](./img/Pasted%20image%2020250315160956.webp)

Here the victim machine is sending packets to the target machine which is in a different subnet
After ping..we can now see the updated arp cache
The MAC address is router's MAC address

- The attacker will send a forged ARP response, which poisons the arp cache of the victim computer making it to think that the attacker's system is the router. 
- This can be done using ettercap or arpspoof tools.
- But due the unavailability in packet tracer, configuring it manually.

- ![](./img/Pasted%20image%2020250315174718.webp)

- Now we can see that the attackers using forged ARP replies, has mapped routers ip address with its own mac address, in victims ARP cache, due to which its poisoned
- Hence any packets being sent outside the network will be sent to the attacker instead

- ![](./img/Pasted%20image%2020250315163058.webp)

- The attacker hence will carry out Man-in-the-middle attack, by sending to and from the VICTIM, acting as the router.
---
