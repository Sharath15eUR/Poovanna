### 1. Try Test-Connection and nslookup commands for below websites:
- www.google.com
- www.facebook.com
- www.amazon.com
- www.github.com
- www.cisco.com

	- Test-Connection is a tool present in windows powershell. In linux we can use ping to check connectivity:
	![[Pasted image 20250316095607.webp]]
	
	- `nslookup` (Name Server Lookup) is a command-line tool used to query a DNS (Domain Name System) server to obtain domain name or IP address mappings.
	- Install dnsutils to use tools like nslookup, dns, dig to get DNS query response.
		`$sudo apt install dnsutils -y`
	
	- **`nslookup` starts a DNS query** from your computer.
	- **It checks cache first** (local resolver, then DNS server cache).
	- **If not cached, it queries the full DNS hierarchy** (Root → TLD → Authoritative).
	- **It prints IP addresses or CNAMEs** based on DNS responses.
	
	![[Pasted image 20250316093855.webp|587]]
	![[Pasted image 20250316093912.webp|582]]
	![[Pasted image 20250316093932.webp|581]]


---

### 2. Explore traceroute/tracert for different websites eg:google.com and analyse the parameters in the output and explore different options for traceroute command

OPTIONS
- `-n`: Skip DNS resolution (shows only IP addresses)
- `-w [seconds]`: Set timeout for responses
- `-q [count]`: Set number of queries per hop
- `-m [max_ttl]`: Maximum number of hops (TTL) to probe
- `-p [port]`: Use specified port
- `-I`: Use ICMP ECHO instead of UDP datagrams
- `-T`: Use TCP SYN for probing
- `-z [milliseconds]`: Set minimum time between probes

The output shows a traceroute from my computer to [www.google.com](http://www.google.com) (142.250.195.36) with 30 maximum hops and 60-byte packets:

1. First hop: gateway router (192.168.21.86) with response times of 1.283ms, 2.075ms, 2.351ms
2. Second hop: 10.206.141.10 (likely ISP's first router) with response times around 25-30ms
3. Third hop: * * * (asterisks indicate no response/timeout)
4. Fourth hop: An Airtel Broadband router (125.22.219.81) with response times around 31ms
5. Fifth hop: 182.79.198.20 with response times 36-42ms
6. Sixth hop: * * * (no response)
7. Seventh hop: * * * (no response)
8. Eighth hop: 108.170.231.128 with only one response at 44.319ms
9. Ninth hop: 172.253.71.132 with one response at 50.572ms
10. Tenth hop: Final destination at Google (142.250.195.36) with response times between 29-42ms

The asterisks indicate that those routers are configured not to respond to traceroute packets or are blocked by firewalls, which is common for security reasons.

![[Pasted image 20250316105328.webp]]


---

