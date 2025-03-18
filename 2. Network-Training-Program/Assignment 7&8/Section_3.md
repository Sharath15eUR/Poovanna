### 1. Use Cisco packet tracer for the below:

### a. Set up trunk ports between switches and try ping between different VLANs.
### b. Change the native VLAN on a trunk port. Test for VLAN mismatches and troubleshoot.
### c. Configure a management VLAN and assign an IP address for remote access. Test SSH or Telnet access to the switch.	 

---


- Simulated a scenario of 2 floors having a mix of sales and HR deparment workstations on each floor
- Sales team were connected to VLAN 10
- HR team were connected to VLAN 20

	![[Pasted image 20250317141314.webp|901]]

- Using trunk port, departments were able to ping with each other, withing the same LAN.
	- ![[Pasted image 20250317144037.webp|722]]
	
- Using router on a stick, systems were able to perform inter-VLAN communication.
	- ![[Pasted image 20250317144048.webp]]
	
- Also configured a management VLAN on switch0, so that systems were able to access the switch via SSH.
	![[Pasted image 20250317143914.webp]]
	
- To config ip address, subnet mask and gateway in windows manually:  
	`netsh interface ip set address name="Ethernet" static 192.168.10.2 255.255.255.0 192.168.10.1`

---

### PROCEDURE:  

### a. Set up trunk ports between switches and try ping between different VLANs

### Step 1: Create the topology

1. Add two switches (e.g., 2960) 
2. Add at least two PCs for each VLAN 
3. Connect the switches using a straight-through cable
4. Connect PCs to each switch

## Step 2: Configure VLANs on both switches

1. On Switch1, enter configuration mode:
    ```
    Switch1> enable
    Switch1# configure terminal
    ```
    
2. Create VLANs (e.g., VLAN 10, 20, 30):
    ```
    Switch1(config)# vlan 10
    Switch1(config-vlan)# name Sales
    Switch1(config-vlan)# exit
    Switch1(config)# vlan 20
    Switch1(config-vlan)# name Engineering
    Switch1(config-vlan)# exit
    Switch1(config)# vlan 30
    Switch1(config-vlan)# name Management
    Switch1(config-vlan)# exit
    ```
    
3. Repeat the same VLAN configuration on Switch2

## Step 3: Assign ports to VLANs

1. On Switch1, assign ports to VLANs:
    ```
    Switch1(config)# interface fastEthernet 0/1
    Switch1(config-if)# switchport mode access
    Switch1(config-if)# switchport access vlan 10
    Switch1(config-if)# exit
    Switch1(config)# interface fastEthernet 0/2
    Switch1(config-if)# switchport mode access
    Switch1(config-if)# switchport access vlan 20
    Switch1(config-if)# exit
    ```
    
2. Repeat on Switch2, assigning ports to the same VLANs

## Step 4: Configure trunk ports

1. On Switch1, configure the interface connected to Switch2 as a trunk:
    ```
    Switch1(config)# interface fastEthernet 0/24
    Switch1(config-if)# switchport mode trunk
    Switch1(config-if)# exit
    ```
    
2. On Switch2, configure the interface connected to Switch1 as a trunk:
    ```
    Switch2(config)# interface fastEthernet 0/24
    Switch2(config-if)# switchport mode trunk
    Switch2(config-if)# exit
    ```
    

## Step 5: Configure IP addresses on PCs

1. Assign IP addresses to PCs in VLAN 10:
    - PC1: 192.168.10.1/24
    - PC2: 192.168.10.2/24
2. Assign IP addresses to PCs in VLAN 20:
    - PC3: 192.168.20.1/24
    - PC4: 192.168.20.2/24

## Step 6: Configure inter-VLAN routing

1. Add a router (e.g., 2811) to your topology
2. Connect the router to Switch1 using a straight-through cable
3. Configure router subinterfaces:
    ```
    Router> enable
    Router# configure terminal
    Router(config)# interface fastEthernet 0/0
    Router(config-if)# no shutdown
    Router(config-if)# exit
    
    Router(config)# interface fastEthernet 0/0.10
    Router(config-subif)# encapsulation dot1q 10
    Router(config-subif)# ip address 192.168.10.254 255.255.255.0
    Router(config-subif)# exit
    
    Router(config)# interface fastEthernet 0/0.20
    Router(config-subif)# encapsulation dot1q 20
    Router(config-subif)# ip address 192.168.20.254 255.255.255.0
    Router(config-subif)# exit
    ```
    
4. Configure the switch port connected to the router as a trunk:
    ```
    Switch1(config)# interface fastEthernet 0/23
    Switch1(config-if)# switchport mode trunk
    Switch1(config-if)# exit
    ```
    

## Step 7: Configure default gateways on PCs

1. Set the default gateway on all PCs in VLAN 10 to 192.168.10.254
2. Set the default gateway on all PCs in VLAN 20 to 192.168.20.254

## Step 8: Test connectivity

1. Try pinging between PCs in the same VLAN (should work)
2. Try pinging between PCs in different VLANs (should work with router)
3. Try pinging the router subinterfaces from PCs


![[Pasted image 20250317141752.webp]]

---

# b. Change the native VLAN on a trunk port

## Step 1: Check current native VLAN

1. On both switches, check the current native VLAN (default is VLAN 1):
    ```
    Switch1# show interfaces trunk
    ```
   
## Step 2: Create a new native VLAN

1. On both switches, create VLAN 999 to be used as the native VLAN:
    ```
    Switch1(config)# vlan 999
    Switch1(config-vlan)# name NativeVLAN
    Switch1(config-vlan)# exit
    ```
    
2. Repeat on Switch2

## Step 3: Change native VLAN on Switch1

1. Configure the trunk port on Switch1:
    ```
    Switch1(config)# interface fastEthernet 0/24
    Switch1(config-if)# switchport trunk native vlan 999Switch1(config-if)# exit
    ```
    
## Step 4: Test for VLAN mismatch

1. At this point, you should see native VLAN mismatch errors in the console/logs
2. Check the status:
    ```
    Switch1# show interfaces trunk
    ```
    
## Step 5: Fix the VLAN mismatch

1. Change the native VLAN on Switch2 to match Switch1:
    ```
    Switch2(config)# interface fastEthernet 0/24
    Switch2(config-if)# switchport trunk native vlan 999Switch2(config-if)# exit
    ```
    
## Step 6: Verify the configuration

1. Check the trunk status on both switches:
    
    ```
    Switch1# show interfaces trunk
    Switch2# show interfaces trunk
    ```
![[Pasted image 20250317141951.webp|784]]

---

# c. Configure a management VLAN and assign an IP address for remote access

## Step 1: Create and configure the management VLAN

1. On both switches, ensure VLAN 30 is configured for management:
    ```
    Switch1(config)# vlan 30
    Switch1(config-vlan)# name ManagementSwitch1(config-vlan)# exit
    ```

## Step 2: Assign IP address to the management VLAN

1. On Switch1, configure the management VLAN interface:
    ```
    Switch1(config)# interface vlan 30
    Switch1(config-if)# ip address 192.168.30.1 255.255.255.0
    Switch1(config-if)# no shutdown
    Switch1(config-if)# exit
    ```
    
2. On Switch2, configure the management VLAN interface:
    ```
    Switch2(config)# interface vlan 30
    Switch2(config-if)# ip address 192.168.30.2 255.255.255.0
    Switch2(config-if)# no shutdown
    Switch2(config-if)# exit
    ```

## Step 3: Configure default gateway on switches

1. On both switches, set the default gateway to the router's interface in VLAN 30:
    ```
    Switch1(config)# ip default-gateway 192.168.30.254
    ```
    
2. Remember to add a subinterface on the router for VLAN 30:
    ```
    Router(config)# interface fastEthernet 0/0.30
    Router(config-subif)# encapsulation dot1q 30
    Router(config-subif)# ip address 192.168.30.254 255.255.255.0
    Router(config-subif)# exit
    ```

## Step 4: Configure SSH access

1. On Switch1, set up SSH access:
    ```
    Switch1(config)# hostname Switch1
    Switch1(config)# ip domain-name example.com
    Switch1(config)# crypto key generate rsa
    How many bits in the modulus [512]: 1024
    Switch1(config)# username admin privilege 15 secret Cisco123
    Switch1(config)# line vty 0 15
    Switch1(config-line)# transport input ssh
    Switch1(config-line)# login local
    Switch1(config-line)# exit
    ```
    
2. Repeat the same configuration on Switch2

## Step 5: Test SSH access

1. Add a PC to VLAN 30 with IP address 192.168.30.10/24
2. From this PC, open the command prompt and try to SSH to each switch:
    ```
    ssh -l admin 192.168.30.1
    ```
3. Enter the password when prompted

---