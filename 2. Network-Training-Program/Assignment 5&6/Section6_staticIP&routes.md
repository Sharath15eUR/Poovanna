### 1.. Manually configure static IPs on the client devices(like Pc or your mobile phone) and verify connectivity using ping.

#### A. Using ip command

- Delete the current ip
	`sudo ip addr del 192.168.205.226/24 dev wlp0s20f3`
- Add new IP address
	 `sudo ip addr add 192.168.151.227/24 dev wlp0s20f3`
- Can verify the change
	`ip addr show wlp0s20f3`

#### B. Using NetworkManager

- In my current OS, POPOS, it uses `NetworkManager` instead of netplan
- Therefore `cd /etc/NetworkManager/system-connections`
- `ls -la`: To see all the connections my laptop has made so far
- Edit the Respective file, in my case, my hotspot named file using nano
- Under [ipov4] making method=manual,
- we can config the static ip address, gateway, and dns server address.
- Pinged my phone with the new ip
	![[Pasted image 20250318165303.webp]]



---


### 2. Manually configure static routes on a router to direct packets to different subnets.Use the ip route command and verify connectivity using ping and traceroute.

- Created 2 subnets
![[Pasted image 20250318172920.webp]]


- Since packets to destination present in another network is automatically shared to the router,
- in the router0 we can route data packets having destination address 192.168.2.0 to 10.0.0.2 gateway
	`ip route 192.168.2.0 255.255.255.0 10.0.0.2`


- Now we can ping to another subnet
	![[Pasted image 20250318173937.webp]]
	
