
# You have a Cisco switch and a VoIP phone that needs to be placed in a voice VLAN (VLAN 20). The data for the PC should remain in a separate VLAN (VLAN 10). Configure the switch port to support both voice and data traffic. You configured VLANs 10 and 20 on your switch and assigned ports to each VLAN. However, devices in VLAN 10 cannot communicate with devices in VLAN 20. Troubleshoot the issue. Try Inter VLAN routing with Router


 -  Connect the components in the below manner
 - IP Phone as an internal switch therefore the PC can be connected directly to the it.

	![[Pasted image 20250317203632.webp]]

	- Configured a switch port for voice and data using separate VLANs
	![[Pasted image 20250317201418.webp]]

	- For confirming the connection we can use `show vlan brief`
	![[Pasted image 20250317201503.webp]]
	- For checking the vlan connections made in a particular interface, we can use the below `show interfaces switchport`
	![[Pasted image 20250317201546.webp]]

	- For troubleshooting inter-vlan communication, we will be using a router-on-a-stick, so we need to enable trunking in the respective interface 
	![[Pasted image 20250317203535.webp]]
	![[Pasted image 20250317203508.webp]]

	- To confirm the ip route, we can use the command `show ip route`
	![[Pasted image 20250317203432.webp]]

---

Things we have to do: 

1. Configure a switch port for both voice and data traffic using separate VLANs
2. Troubleshoot VLAN communication issues, by implementing inter-VLAN routing using a router



### 1: Configure Voice and Data VLANs on the Switch

1. **Open Packet Tracer and create your topology**:
    - Add a Cisco switch (like 2960)
    - Connect a VoIP phone to one port (e.g., Fa0/1)
    - Connect a PC to the VoIP phone (many IP phones have a pass-through port)
    - Add other PCs to VLAN 10 and VLAN 20 for testing
    
2. **Access the switch CLI**:
    - Click on the switch and select the CLI tab
    - Enter privileged EXEC mode:
        ```
        enable
        ```
    - Enter configuration mode:
        ```
        configure terminal
		```
		
3. **Create and name the VLANs**:
    ```
    vlan 10
    name Data
    exit
    vlan 20
    name Voice
    exit
    ```
    
4. **Configure the switch port for the VoIP phone**:
    ```
    interface fa0/1
    switchport mode access
    switchport access vlan 10
    switchport voice vlan 20
    no shutdown
    exit
    ```
    
    This configures Fa0/1 for both data (VLAN 10) and voice (VLAN 20) traffic.
    

### 2: Troubleshoot VLAN Communication Issues

The problem stated is that devices in VLAN 10 cannot communicate with devices in VLAN 20, this is simply because VLANs are designed to isolate broadcast domains. To allow inter-VLAN communication, we need to implement inter-VLAN routing.

Troubleshooting steps:

1. **Verify VLAN configuration**:
    ```
    show vlan brief
    ```
    Ensure VLANs 10 and 20 exist and ports are correctly assigned.
    
2. **Verify interface status**:
    ```
    show interfaces status
    ```
    Check that interfaces are up/up.
    
3. **Check voice VLAN configuration**:
    ```
    show interfaces switchport
    ```
    Verify voice VLAN settings on the phone port.
    

### 3: Implement Inter-VLAN Routing

1. **Add a router to the topology** (e.g., Cisco 1841 or 2811)
2. **Connect the router to the switch** using a standard connection
3. **Configure router-on-a-stick** (one physical interface with subinterfaces):
    ```
    enable
    configure terminal
    interface fa0/0
    no shutdown
    exit
    
    interface fa0/0.10
    encapsulation dot1q 10
    ip address 192.168.10.1 255.255.255.0
    exit
    
    interface fa0/0.20
    encapsulation dot1q 20
    ip address 192.168.20.1 255.255.255.0
    exit
    ```
    
4. **Configure the switch port connected to the router as a trunk**:
    ```
    interface fa0/24
    switchport mode trunk
    switchport trunk allowed vlan 10,20
    no shutdown
    exit
    ```
    
5. **Configure IP addresses on the devices**:
    - PCs in VLAN 10: IP in 192.168.10.0/24 range, default gateway 192.168.10.1
    - VoIP phone in VLAN 20: IP in 192.168.20.0/24 range, default gateway 192.168.20.1
6. **Test connectivity**:
    - From a PC in VLAN 10, ping a device in VLAN 20
    - Use the `show ip route` command on the router to verify routing


---
