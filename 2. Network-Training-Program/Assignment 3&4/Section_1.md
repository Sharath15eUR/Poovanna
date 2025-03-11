
1. Using cisco packet tracer - troubleshoot ethernet communication with ping and traceroute
2. Create a simple LAN setup with 2 linux machines connected via a switch
- Configure static IP addresses
- Modify MAC addresses
- Verify network connectivity using ping and ifconfig commands
- Ping from one machine to the other. 
- If it fails
	1. use ifconfig to ensure the IP addresses are configured correctly
	2. use traceroute to identify where the packets are being dropped if the ping fails.
- Use ping to generate and observe the MAC address table of the switch.
3. Use bridge or IP link commands to inspect the MAC table and demonstrate a basic switch's operation

# STEPS:

1. Drag and drop 2 PCs and a switch and connect them through fast-ethernet ports
![[Pasted image 20250305232915.webp|421]]

2. Click the required PC and under config->Fast-Ethernet, configure the
	- MAC address
	- static IP address
	- Subnet mask
 ![[Pasted image 20250305235008.webp|665]]


***Using Command Line***
A. Configuring static ip address
`sudo ip addr add 192.168.1.100/24 dev eth0`

B. Deleting previous static ip address
`sudo ip addr del 192.168.1.x/24 dev eth0`

C. Changing MAC address
 - Bringing down the interface
	`sudo ip link set dev eth0 down`
 - Set a new MAC address:
	`sudo ip link set dev eth0 address XX:XX:XX:XX:XX:XX`
 - Bring up the interface:
	`sudo ip link set dev eth0 up`
 - Verify the change
	`ip link show eth0`

5. Do the same for the other PC.
6. Next drag another PC, and use it as a console for the switch.
7. Open terminal of the console and type `enable` to enter privileged execution mode and type `show mac address-table` in order to display mac table.
8. `show version`, in privileged mode shows all the details of switch including MAC
![[Pasted image 20250305235508.webp]]

9. as we can see there is no mac addresses, for which we need to ping from one to another system, for the switch to store MAC address
10. Using Ping 4 packets are sent from 1 and received from other, thus letting the switch store the MAC address. If packets fail to reach, we can use `tracert ip_addr` to check where packet delivery fails.(traceroute in linux)
![[Pasted image 20250306000115.webp]]
11. Now we can view the MAC address table in the console
![[Pasted image 20250306000214.webp]]
12. In order to troubleshoot to check for ip address or any details can use ipconfig[windows]
![[Pasted image 20250306000509.webp]]
13. Using `show version` in the console terminal of the switch we can get details like MAC address of switch
14. ![[Pasted image 20250306000657.webp]]


# Inspecting mac table and basic switch operation using bridge or ip link

Bridge acts as a virtual switch connecting multiple network interfaces in layer 2. 

1. Creating 2 virtual interfaces for example
	`sudo ip tuntap add vinterf0 mode tap`
	`sudo ip tuntap add vinterf1 mode tap`

2. Bringing up the virtual interfaces to make them operational
	`sudo ip link set vinterf0 up`
	`sudo ip link set vinterf1 up`

3. Creating a bridge
	`sudo ip link add newBridge type bridge`

4. Bringing up the bridge to make it operational
	`sudo ip link set newBridge up`


5. Adding virtual interfaces to the bridge
	`sudo ip link set vinterf0 master newBridge`
	`sudo ip link set vinterf1 master newBridge`

6. To print the MAC table..this displays the devices connected to the virtual switch or bridge that we created
	`sudo brctl showmacs newBridge`
	
	![[Pasted image 20250310214801.webp]]

