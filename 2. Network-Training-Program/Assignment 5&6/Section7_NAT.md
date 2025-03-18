> Combining the answer for both the questions

### 1. In Cisco Packet Tracer, configure NAT on a router to allow internal devices (192.168.1.x) to access the internet.Test connectivity by pinging an external public IP.Capture the traffic in Wireshark and analyze the source IP before and after NAT translation.
---

### 2. In Cisco Packet Tracer, create a small network with multiple devices (e.g., 2 PCs and a router). Use private IP addresses (e.g., 192.168.1.x) on the PCs and configure the router to perform NAT to allow the PCs to access the internet. Task: Test the NAT configuration by pinging an external IP address from the PCs and capture the traffic using Wireshark. What is the source IP address before and after NAT?


- Created a simple setup, and the server which hosts http services will act as the internet
	![[Pasted image 20250318130410.webp]]


	![[Pasted image 20250318130525.webp|443]]
	![[Pasted image 20250318130534.webp|462]]

- After setting up the gateway ip addresses, and the device ip addresses, we can move on to NAT configuration.
- ![[Pasted image 20250318130512.png]]
- This will setup which is the private network and which is the public network
- In the current context, will perform PAT, so that both the PCs will share the same public ip address
- ![[Pasted image 20250318130502.webp]]
- This will basically give the router's gateway address as the public address
	![[Pasted image 20250318130421.webp]]
	![[Pasted image 20250318130404.webp]]


- Using no, we can remove NAT
- Use STATIC NAT
- ![[Pasted image 20250318131048.webp]]
- ![[Pasted image 20250318131122.webp]]

	![[Pasted image 20250318131030.webp]]


---

### PROCEDURE


## 1: Set up the network topology in Packet Tracer

1. Open Cisco Packet Tracer and create a new project
2. Add these devices:
    - 1 Router (e.g., 1841 or 2811)
    - 1 Switch
    - 2 PCs (internal network)
    - 1 Server (to simulate the internet)
3. Connect the devices:
    - Connect the internal PCs to the Switch (using straight-through cables)
    - Connect the Switch to the Router's FastEthernet0/0 (using straight-through cable)
    - Connect the Server (internet) to the Router's FastEthernet0/1 (using straight-through cable)

## 2: Configure IP addresses

### For internal network:
- Router's FastEthernet0/0: 192.168.1.1/24
- PC1: 192.168.1.10/24, Default Gateway: 192.168.1.1
- PC2: 192.168.1.20/24, Default Gateway: 192.168.1.1

### For external network (simulated internet):
- Router's FastEthernet0/1: 203.0.113.2/24
- Server: 203.0.113.10/24, Default Gateway: 203.0.113.2

## Step 3: Configure NAT on the router
1. Click on the Router and go to the CLI tab
2. Enter these commands:

```
Router> enable
Router# configure terminal

! Configure the inside interface
Router(config)# interface FastEthernet0/0
Router(config-if)# ip address 192.168.1.1 255.255.255.0
Router(config-if)# ip nat inside
Router(config-if)# no shutdown
Router(config-if)# exit

! Configure the outside interface
Router(config)# interface FastEthernet0/1
Router(config-if)# ip address 203.0.113.2 255.255.255.0
Router(config-if)# ip nat outside
Router(config-if)# no shutdown
Router(config-if)# exit

! Define which addresses can be translated
Router(config)# access-list 1 permit 192.168.1.0 0.0.0.255

! Configure NAT to use the access list and the outside interface's IP
Router(config)# ip nat inside source list 1 interface FastEthernet0/1 overload

! Add a static route to the internet
Router(config)# ip route 0.0.0.0 0.0.0.0 203.0.113.10

! Save the configuration
Router(config)# end
Router# write memory
```

## Step 4: Configure the server (simulated internet)
1. Click on the Server, go to the Config tab
2. Set the IP address to 203.0.113.10 with subnet mask 255.255.255.0
3. Set the default gateway to 203.0.113.2
4. Go to the Services tab and enable HTTP and PING services

## Step 5: Test connectivity
1. Click on PC1, go to the Desktop tab and open Command Prompt
2. Test internal connectivity first:
    ```
    ping 192.168.1.1ping 192.168.1.20
    ```
3. Test external connectivity:
    ```
    ping 203.0.113.10
    ```
    
---





