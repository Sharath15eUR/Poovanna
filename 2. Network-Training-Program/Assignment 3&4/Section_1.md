# Task
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

## Steps

1. Drag and drop 2 PCs and a switch and connect them through fast-ethernet ports

![](./img/Pasted%20image%2020250305232915.webp)

2. Click the required PC and under config->Fast-Ethernet, configure the
	- MAC address
	- static IP address
	- Subnet mask
 ![](./img/Pasted%20image%2020250305235008.webp)


	***Using Command Line***

	- Configuring static ip address
		`sudo ip addr add 192.168.1.100/24 dev eth0`
	- Deleting previous static ip address
		`sudo ip addr del 192.168.1.x/24 dev eth0`
	- Changing MAC address
 	- disable the interface
		`sudo ip link set dev eth0 down`
 	- Set a new MAC address:
		`sudo ip link set dev eth0 address XX:XX:XX:XX:XX:XX`
 	- enable the interface:
		`sudo ip link set dev eth0 up`
 	- Verify the change
		`ip link show eth0`

3. Do the same for the other PC.
4. Next drag another PC, and use it as a console for the switch.
5. Open terminal of the console and type `enable` to enter privileged execution mode and type `show mac address-table` in order to display mac table.
6. `show version`, in privileged mode shows all the details of switch including MAC

	![](./img/Pasted%20image%2020250305235508.webp)

7. as we can see there is no mac addresses, for which we need to ping from one to another system, for the switch to store MAC address
8. Using Ping 4 packets are sent from 1 and received from other, thus letting the switch store the MAC address. If packets fail to reach, we can use `tracert ip_addr` to check where packet delivery fails.(traceroute in linux)

	![](./img/Pasted%20image%2020250306000115.webp)
9. Now we can view the MAC address table in the console
    
	![](./img/Pasted%20image%2020250306000214.webp)
10. In order to troubleshoot to check for ip address or any details can use ipconfig[windows]
    
	![](./img/Pasted%20image%2020250306000509.webp)
11. Using `show version` in the console terminal of the switch we can get details like MAC address of switch
    
	![](./img/Pasted%20image%2020250306000657.webp)


## Inspecting mac table and basic switch operation using bridge or ip link

Bridge acts as a virtual switch connecting multiple network interfaces in layer 2. 
1. Creating 2 virtual network interfaces for example
	- `sudo ip tuntap add vinterf0 mode tap`
	- `sudo ip tuntap add vinterf1 mode tap`
2. Enabling the virtual interfaces to make them operational
	- `sudo ip link set vinterf0 up`
	- `sudo ip link set vinterf1 up`
3. Creating a bridge
	- `sudo ip link add newBridge type bridge`
4. Enabling the bridge to make it operational
   	-  `sudo ip link set newBridge up`
5. Connecting virtual interfaces to the bridge
	- `sudo ip link set vinterf0 master newBridge`
	- `sudo ip link set vinterf1 master newBridge`
6. To print the MAC table..this displays the devices connected to the virtual switch or bridge that we created
	- `sudo brctl showmacs newBridge`
	
	![](./img/Pasted%20image%2020250310214801.webp)

