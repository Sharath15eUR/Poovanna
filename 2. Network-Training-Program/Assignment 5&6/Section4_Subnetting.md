### 1.  Given an IP address range of 192.168.1.0/24, divide the network into 4 subnets. Task: Manually calculate the new subnet mask and the range of valid IP addresses for each subnet. Assign IP addresses from these subnets to devices in Cisco Packet Tracer and verify connectivity using ping between them.


NETWORK ADDRESS: 192.168.1.0
SUBNET MASK: 255.255.255.0


In order to create 4 subnets, we will borrow 2 bits from the host part of the mask

The 4 subnets are:

New Subnet Mask: 255.255.255.192

1. 192.168.1.0 - 192.168.1.0 to 192.168.1.63
	1. Network address: 192.168.1.0
	2. Broadcast address: 192.168.1.63
	3. Host range: 192.168.1.1 to 192.168.1.62
2. 192.168.1.64 - 192.168.1.64 to 192.168.1.127
	4. Network address: 192.168.1.64
	5. Broadcast address:192.168.1.127
	6. Host range: 192.168.1.65 to 192.168.1.126
3. 192.168.1.128 - 192.168.1.128 to 192.168.1.191
	1. Network address: 192.168.1.128
	2. Broadcast address:192.168.1.191
	3. Host range: 192.168.1.129 to 192.168.1.190
4. 192.168.1.192 - 192.168.1.192 to 192.168.1.255
	4. Network address: 192.168.1.192
	5. Broadcast address:192.168.1.255
	6. Host range: 192.168.1.193 to 192.168.1.254

![[Pasted image 20250318182038.webp]]

![[Pasted image 20250318182030.webp]]

---


### 2. Given a network address of 10.0.0.0/24, divide it into 4 equal subnets.
-  Calculate the new subnet mask.
-  Determine the valid host range for each subnet.
- Assign IP addresses to devices in Packet Tracer and verify connectivity.

	
	IP ADDRESS: 10.0.0.0
	SUBNET MASK: 255.255.255.0

	In order to divide it into 4 equal subnets, we will need to borrow 2 bits from the subnet mask
	 since 
	- from 1 bit we can create 2 subnets
	- from 2 bits we can create 4 subnets
	- and so on...

	There the new subnet mask will be: 255.255.255.192

	There the 4 new subnets: 
	1. 10.0.0.0 - 10.0.0.0 to 10.0.0.63
		1. network address: 10.0.0.0
		2. broadcast address:10.0.0.63
		3. host range:10.0.0.1 to 10.0.0.62
	2. 10.0.0.64 - 10.0.0.64 to 10.0.0.127
		4. network address:10.0.0.64
		5. broadcast address:10.0.0.127
		6. host range:10.0.0.65 to 10.0.0.126
	3. 10.0.0.128 - 10.0.0.128 to 10.0.0.191
		1. network address:10.0.0.128
		2. broadcast address:10.0.0.191
		3. host range:10.0.0.129 to 10.0.0.190
	4. 10.0.0.192 - 10.0.0.192 to 10.0.0.255
		4. network address:10.0.0.192
		5. broadcast address:10.0.0.255
		6. host range:10.0.0.193 to 10.0.0.254



Simulating the above subnet in Cisco Packet Tracer
![[Pasted image 20250315122243.webp]]


Can use show interfaces command to see all the available interfaces
![[Pasted image 20250315122230.webp]]


![[Pasted image 20250315122424.webp]]

