### Question No: 01
#### Consider a case, a folder has multiple files and how would copy it to destination machine path (Try using SCP, cp options in Linux)
---

***Installations***
```
sudo apt upgrade
sudo apt install openssh-server openssh-client
```

***To Enable SSH Server***
```
#ANDROID
sshd

#LINUX 
sudo systemctl enable --now ssh
sudo systemctl status ssh
```

***To copy multiple files from a folder to the destination machine***
`$scp -P port username@ip_address:source_addr dest_addr`
![](./images/Pasted%20image%2020250228000944.webp)


### Question No: 02
#### Host a FTP and SFTP server and try PUT and GET operations
---

#### 1. FTP

- Start FTP server
`sudo systemctl enable --now vsftpd`

- Can check the status using  
`systemctl status vsftpd`

- Connect to FTP server using
`ftp ip_addr`

- Use put to upload files and get to download files

#### 2. SFTP

- Enable SSH server to which client needs to be connected
- Connect to the server with the following command
`SFTP kbpoovanna@ip_address`
- Enter the password
- In order to download a file use GET
- In order to upload a file use PUT

![](./images/Pasted%20image%2020250301223054.webp)


Wireshark packet transfer
- SFTP packets are encrypted
![](./images/Pasted%20image%2020250301223507.webp)

- While FTP packets are not encrypted
![](./images/Pasted%20image%2020250301225057.webp)


### Question No: 03
#### Explore with Wireshark/TCP-dump/cisco packet tracer tools and learn about packets filters.
---

#### **1. TCPDUMP**

Network CLI utility in order to sniff network packets

OPTIONS
1. -D: this can be used to check which interfaces are available for capture
	`sudo tcpdump -D`
2. -c numberofpacketstocapture
	this can be used a lot of times in order to limit the number of packets captured
3. -i: this is used to provide in which interface packet capture should be done
4. -dst: can be used to filter packets based on destination ip_address
5. -src: can be used to filter packets based on source ip_address
6. -v: verbose for detailed output


Examples:
1. List available interfaces or NICs
	`sudo tcpdump -D`
2. Limit the number of packets captured
	`sudo tcpdump -c 5`
3. Capture on a specific interface
	`sudo tcpdump -i eth0`
4. Filter packets based on destination IP address
	`sudo tcpdump -dst ip_address`
5. Filter packets based on Source IP address
	`sudo tcpdump -src ip_address`
6. Verbose output
	`sudo tcpdump -v`
7. Capture HTTP packets on port 80
	`sudo tcpdump port 80`
8. Capture ICMP packets
	`sudo tcpdump ICMP`
9. Capture packets which are not UDP
	`suco tcpdump not UDP`
10. Capture traffic from a specific host
	`sudo tcpdump host ip_address`


#### **2. Wireshark**

Inside the *Apply filter option*, we can apply packet filters like:

- `ip_addr == 10.0.0.1 ` to filter packets coming from this ip address
- `ip.addr >= 10.10.50.1 and ip.addr <= 10.10.50.100` to display traffic within this ip range
- `!(ip.addr == 10.10.50.1)` to capture packets not having this ip address
- `ip.addr == 10.0.0.0/24` to show packets to and from any address in the 10.0.0.0/24 subnet
- `ip.addr==10.0.0.1 && ip.addr==10.0.0.2` to set a filter for a conversation between two defined IP addresses
- `tcp.port==4000` to set a filter for any TCP packet with 4000 as a source or destination port
- `tcp. port in {80, 443, 8080}` to display packets with a TCP source or destination port of 80, 443, or 8080
- `tcp.dstport == 23` to filter traffic by the destination port
- `http or dns or icmp or arp` to specify packets using this protocol
- `http.host == "www.google.com”` to filter traffic by a specific URL
- `frame contains traffic` to display all packets that contain the word ‘traffic.’ This is useful when searching for a specific string or user ID. For example, `TCP contains Facebook` to find TCP packets containing the word "Facebook


### Question No: 04
#### Understand linux utility commands like - ping, arp (Understand each params from ifconfig output)
---
#### 1. Ping 

The `ping` command is a network utility used to test the reachability of a host on a network. It sends Internet Control Message Protocol (ICMP) echo requests to a specified host and measures the round-trip time (RTT), which helps determine network latency.
	
 Options that can be used: 
- -c: to specify the number of packets that to be sent
- -i: to specify the wait time between each interval
- -s: to specify packet size
- -I: to specify network interface to be used

Examples: 
- To check connectivity to a remote server: `ping google.com`
- To send only 10 ping requests: `ping -c 10 google.com`
- To specify a network interface: `ping -I eth0 google.com`

#### 2. Arp

The arp command in Linux is a crucial utility for managing the Address Resolution Protocol (ARP) cache, which maps IP addresses to MAC addresses within a local area network (LAN). This mapping is essential for enabling communication between devices on the network.

Basic Usage of the arp Command

The `arp` command allows users to view, add, or delete ARP entries. Here are some common options:

- **`-a`**: Displays the current ARP cache entries.
- **`-d [IP`**: Deletes an entry for the specified IP address.
- **`-s [IP] [MAC]`**: Adds a new ARP entry with the specified IP and MAC address.
- **`-v`**: Provides verbose output.
- **`-n`**: Displays numerical addresses instead of resolving hostnames.
    
 Examples

1. To view all current ARP entries, use:
    `arp -a`
    
2. To manually add an entry mapping an IP address to a MAC address 
    `arp -s 192.168.1.2 00:11:22:33:44:55`
    
3. If you need to remove an entry from the ARP cache, you can do so with:
    `arp -d 192.168.1.2`
    
4. To see more detailed information about the ARP entries, use:
    `arp -va`
    
5. To display entries without resolving hostnames, run: 
    `arp -n`


#### 3. IFCONFIG
this is a cli network utility in order to display and configure all network interfaces both wired and wireless.

The information is given for each of the network interfaces like enp2s0, lo, wlan etc

**Some examples of interfaces are:**
1. **enp2s0** - this is an ethernet interface where, p2s0 is a network port.
2. **lo** - loopback interface signifies the localhost itself
3. **wlp0s20f3** -  This is the name of the wireless network interface (Wi-Fi) on the system

**Network details of each of the interfaces can be like:**

1. **flags** - shows whether the interface is loopback and is active running
2. **MTU**- maximum transmission unit - is the maximum packet size that can be transmitted
3. **inet** - signifies the IPV4 address, also showing its netmask and broadcast address
4. **inet6** - signifies IPV6 address, where there 2, one for local network and other for global
5. **ether** - this shows the MAC address of the interface
6. **txqueuelen** - this is the transmit queue length for the wireless interface
7. **RX & TX** - shows the total packets received and transmitted and in bytes, and its errors and collisions

**OPTIONS to use with ifconfig** 

- `ifconfig -a` - to show a list of network interfaces
- `ifconfig eth0 up` - to enable the network interface
- `ifconfig eth0 down` - to disable the network interface
- `ifconfig eth0 192.168.1.10 netmask 255.255.255.0` - to assign static IP and netmask
- `ifconfig eth0 mtu 1500` - to set max transmission unit
- `ifconfig eth0 promisc -` - to enable the interface to go promiscuous mode in order to enable it to capture all packets in the network
- `ifconfig eth0:0 192.168.1.20` - to assign virtual ip, in order to host multiple services on different ips
- `ifconfig eth0 broadcast 192.168.1.255` - to specify the broadcast address for a interface
- `ifconfig | grep inet` - will display the ip addresses of all active interfaces


### Question No: 05
#### Understand what happens when duplicate ip addresses are assigned
---

The situation of duplicate ip addresses occurs whenever there is a manual configuration errors my assigning similar static ips or DHCP misconfiguration or network device failures

Due to these issues..there will be connectivity issues, like sending packets to the wrong system, or dropping of packets, and in turn making troubleshooting and network management more complicated

In order to prevent or detect duplicate ip addresses
- Just implement automated DHCP to prevent manual errors

- Reserve static IPs, preventing them from manually assigning them

- regular audits of assigned IP addresses can prevent duplication

- **IP Address Pool Management:** The DHCP server maintains a pool of available IP addresses and keeps track of which addresses are currently assigned to devices.
    
- **MAC Address Identification:** Devices are identified by their unique MAC addresses, which helps prevent multiple devices from being assigned the same IP address simultaneously.
    
- **Conflict Resolution:** If there is an attempt to assign an already allocated IP address, the DHCP server can detect this conflict and take appropriate actio


### Question No: 06
#### Understand how to access remote system using (VNC viewer, Anydesk, teamviewer and remote desktop connections)
---

#### 1. VNC Viewer
- **Install VNC Server and Viewer**: On the remote computer, install VNC Server. On the local device, install VNC Viewer.
- **Set Up VNC Server**: Configure the server on the remote PC by creating a password for access and naming the computer.
- **Connect via VNC Viewer**: Open VNC Viewer on your local device, sign in with your RealVNC account, and select the remote computer to connect. Authenticate using the password set during server setup.

#### 2. Anydesk
- **Install Anydesk**: Download and install Anydesk on both the remote and local computers.
- **Share Access Code**: Obtain the unique access code displayed on the remote computer.
- **Connect to Remote Device**: Enter the access code into Anydesk on your local device. Accept the connection request on the remote computer to establish control.

#### 3. TeamViewer
- **Install TeamViewer**: Install TeamViewer on both the remote and local devices.
- **Share ID and Password**: On the remote device, note the unique ID and temporary password displayed in TeamViewer.
- **Connect Remotely**: Enter the ID in TeamViewer on your local device, provide the password when prompted, and start the session.

#### 4. Remote Desktop Connections (RDP)
- **Enable Remote Desktop**: On the remote PC (Windows Pro editions), go to *Settings %3E System > Remote Desktop* and enable it. Note down the PC name.
- **Connect via RDP Client**:
  - On Windows: Search for "Remote Desktop Connection," enter the PC name, and connect.
  - On macOS, iOS, or Android: Download Microsoft Remote Desktop app, add the PC name, and connect.


### Question No: 07
#### Check if default gateway is reachable or not and understand about default gateways
---

The default gateway is a router that allows your computer to access networks outside your local network. It acts as an access point, passing network data from local to remote networks

To check if the gateway is reachable or not:

1. First find the ip address of the default gateway, use
	- `netstat -rn` 
	- `ip route| grep default` 
2. Use ping in order to check if reachable or not
	- `ping ip_addr`

	
### Question No:08
#### Check iwconfig/ifconfig to understand in detail about network interfaces (check about interface speed, MTU and other parameters)
---

**1. iwconfig** - this is a cli network utility in order to display and configure wireless network interfaces

Using this we can check:
- bit rate
- transmission power
- frequency used to transmit data
- Signal level
- link quality
- Access point MAC address

**2. ifconfig** - this is a cli network utility in order to display and configure all network interfaces both wired and wireless.

The information is given for each of the network interfaces like enp2s0, lo, wlan etc

Some examples of interfaces are:
1. **enp2s0** - this is an ethernet interface where, p2s0 is a network port.
2. **lo** - loopback interface signifies the localhost itself
3. **wlp0s20f3** -  This is the name of the wireless network interface (Wi-Fi) on the system

Network details of each of the interfaces can be like:
1. **flags** - shows whether the interface is loopback and is active running
2. **MTU**- maximum transmission unit - is the maximum packet size that can be transmitted
3. **inet** - signifies the IPV4 address, also showing its netmask and broadcast address
4. **inet6** - signifies IPV6 address, where there 2, one for local network and other for global
5. **ether** - this shows the MAC address of the interface
6. **txqueuelen** - this is the transmit queue length for the wireless interface
7. **RX & TX** - shows the total packets received and transmitted and in bytes, and its errors and collisions


### Question No:09
#### Log in to your home router's web interface (usually at 192.168.1.1 or 192.168.0.1) and check the connected devices list.
---
1. Type 192.168.1.1 in any of the web browswer
2. A user interface for wifi network will be shown
3. Enter admin username and password and type the verification code
4. Once logged in click Status->User Information
5. Here we will be able to see the below parameters for each of the connected devices
	- MAC address
	- Tx count
	- Rx Count
	- Tx Rate
	- Power save
	- Lease Time



### Question No: 10
#### Explain how DHCP server assigns IP addresses to devices in your network
---

**DHCP - Dynamic Host Configuration Protocol automates the assignment of IP addresses and network configurations to devices within a network.**

#### Process:

1. **DHCP Discover:**
    - When a device (client) connects to the network, it sends out a broadcast message called a DHCP Discover to locate available DHCP servers.
        
2. **DHCP Offer:**
    - Any DHCP server that receives the Discover message responds with a DHCP Offer. This offer includes:
        - An available IP address from the server's pool.
        - Subnet mask.
        - Default gateway.
        - DNS server addresses.
        
3. **DHCP Request:**
    - The client selects one of the received offers (usually the first) and sends back a DHCP Request message to the chosen server, indicating acceptance of the offered IP address.
        
4. **DHCP Acknowledgment (ACK):**
    - The DHCP server sends a DHCP Acknowledgment message to the client, confirming the IP address assignment and specifying the lease duration for which the address is valid. At this point, the device can start communicating on the network using its assigned IP address.
        

#### Lease Mechanism:

- **Lease Duration:** Each IP address assignment has a lease duration, which dictates how long a device can use that IP address before it must renew it.
- **Renewal Process:** Before the lease expires, the device can send a request to renew its lease, allowing it to continue using the same IP address or potentially receive a new one based on server policies.
    

#### Allocation Methods:

DHCP servers can allocate IP addresses in three main ways:

1. **Dynamic Allocation:**
    - The server assigns IP addresses from a defined pool dynamically. If a device does not renew its lease, the server reclaims and reallocates that IP address to other devices as needed.
        
2. **Automatic Allocation:**
    - The server permanently assigns an IP address to a client based on its MAC address. This means that every time that specific client connects, it receives the same IP address from the server.
        
3. **Manual Allocation:**
    - An administrator manually maps specific MAC addresses to designated IP addresses in the DHCP server configuration. This ensures that certain devices always receive specific IP addresses when they connect.
    

### Question No: 11
##### Using a terminal, connect to a remote machine via SSH and telnet.
---

#### **1. SSH**

***Installations***
```
sudo apt upgrade
sudo apt install openssh-server openssh-client
```

***To Enable SSH Server***
```
#ANDROID
sshd

#LINUX 
sudo systemctl enable --now ssh
sudo systemctl status ssh
```

***To connect to a remote machine type:***
`$ssh username@ip_address`
- and enter the password


#### **2. TELNET**

***Install client - telnet***
`$sudo apt install telnet`

***Install server - telnetd***
`$sudo apt install telnetd`

inetd is a service that listens to all ports used by internet. Check is status if any issues
`$systemctl status inetd`

***Allow Telnet port through firewall***
```
$sudo ufw allow 23/tcp
$sudo ufw reload
```

***Create new user and enter password ***
```
$sudo useradd username
$sudo passwd username
```

***Connect to the server using the syntax:***
`$telnet -l username remote_machne_ip`

![](Pasted%20image%2020250301145546.webp)

___
