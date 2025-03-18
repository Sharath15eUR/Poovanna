
# TASK: 1: Implement ACLs to restrict traffic based on source and destination ports. Test rules by simulating legitimate and unauthorized traffic.
# TASK: 2: Configure a standard Access Control List (ACL) on a router to permit traffic from a specific IP range. Test connectivity to verify the ACL is working as intended.
# Task: 3: Create an extended ACL to block specific applications, such as HTTP or FTP traffic. Test the ACL rules by attempting to access blocked services.


ACLs are sequential lists of permit or deny statements that the router uses to control traffic. They act as traffic filters, allowing administrators to:

- Control what traffic can enter or exit network interfaces
- Protect networks by blocking unauthorized access
- Limit certain types of traffic for security or bandwidth management


- Connect the components in the below method
![[Pasted image 20250318091837.webp]]

- As we can see, we are able to ping to the other network. Hence still ACL is not active
![[Pasted image 20250317224952.webp]]


- In router2, we are creating a access list which will permit packets only from the 192.168.1.10 PC and will deny the rest.
- 0.0.0.0 is a wildcard mask which makes it clear that if it is 0, the ip address should match with the one specified
![[Pasted image 20250317225343.webp]]
- Now we are activating the access-group for the particular interface
![[Pasted image 20250317230551.webp]]

- After enabling the ACL in router2 via the interface connecting router1,
1. We are able to ping from the second pc 
![[Pasted image 20250317230519.webp]]
2. But ICMP packets from 1st pc are getting blocked.
![[Pasted image 20250317230500.webp]]


---

- Extending ACL to block packets for specific applications and ports

### HTTP(80) & HTTPS(443)
- Initially from 192.168.1.10, i am able to send https request to the server 192.168.2.20, which has a port 443
 ![[Pasted image 20250318082316.webp]]

- Created a new access-list and activated it.
- After applying the ACL blocking all https traffic going out of GigaBitEthernet0/0/0
![[Pasted image 20250318082600.webp]]
![[Pasted image 20250318082646.webp]]

- ICMP packets are able to leave
![[Pasted image 20250318082709.webp]]

- But packets with destination port 443 for https and 80 for http are blocked by the router
![[Pasted image 20250318083449.webp]]



```
REMOVE AN ACCESS-GROUP: no ip access-group number in/out
REMOVE AN ACCESS-LIST: no access-list number
TO SHOW ALL ACCESS-LIST: show access-list
```
![[Pasted image 20250318090910.webp]]


### FTP(20/21)
port 21 is used for commands and responses, for control connection
port 20 is used for actual data or file transfers

- Able to connect before ACL was activated
![[Pasted image 20250318091413.webp]]
![[Pasted image 20250318091708.webp|453]]
- After ACL was configued
![[Pasted image 20250318091654.webp]]

---

### PROCEDURE:

# 1: Implement ACLs to restrict traffic based on source and destination ports


1. **Create a basic network topology**
    - Add at least two PCs (PC1 and PC2)
    - Add a router (Router0)
    - Connect PC1 to one interface of Router0 (e.g., GigabitEthernet0/0)
    - Connect PC2 to another interface of Router0 (e.g., GigabitEthernet0/1)
2. **Configure IP addresses**
    - PC1: IP 192.168.1.10, Subnet 255.255.255.0, Default Gateway 192.168.1.1
    - PC2: IP 192.168.2.10, Subnet 255.255.255.0, Default Gateway 192.168.2.1
    - Router0 G0/0: IP 192.168.1.1, Subnet 255.255.255.0
    - Router0 G0/1: IP 192.168.2.1, Subnet 255.255.255.0
3. **Configure extended ACL**
    - Click on Router0
    - Go to CLI tab
    - Enter configuration mode:
        ```
        Router0> enableRouter0# configure terminal
        ```
        
    - Create an extended ACL to block HTTP traffic (port 80) but allow all other traffic:
        ```
        Router0(config)# access-list 101 deny tcp any any eq 80Router0(config)# access-list 101 permit ip any any
        ```
        
4. **Apply the ACL to an interface**
    - Apply the ACL to the G0/0 interface in the outbound direction:
        ```
        Router0(config)# interface GigabitEthernet0/0Router0(config-if)# ip access-group 101 outRouter0(config-if)# exit
        ```
        
5. **Test the ACL**
    - On PC1, open a command prompt and try to ping PC2 (should succeed):
        ```
        ping 192.168.2.10
        ```
    - On PC1, open Web Browser application and try to access http://192.168.2.10 (should fail)
    - On PC1, try to access a different port (e.g., FTP on port 21) which should succeed if you have an FTP server configured on PC2

# 2: Configure a standard ACL to permit traffic from a specific IP range

1. **Setup a new network or modify the existing one**
    - Add another PC (PC3) with IP 192.168.3.10, subnet 255.255.255.0
    - Connect PC3 to Router0 via a new interface (e.g., G0/2)
    - Configure Router0 G0/2: IP 192.168.3.1, Subnet 255.255.255.0
2. **Configure standard ACL**
    - Access the Router0 CLI:
        ```
        Router0> enableRouter0# configure terminal
        ```
    - Create a standard ACL to permit only traffic from the 192.168.1.0 network:
        ```
        Router0(config)# access-list 1 permit 192.168.1.0 0.0.0.255
        ```
    - The wildcard mask 0.0.0.255 corresponds to subnet 255.255.255.0
3. **Apply the ACL to an interface**
    - Apply the ACL to the G0/2 interface in the inbound direction:
        
        ```
        Router0(config)# interface GigabitEthernet0/2Router0(config-if)# ip access-group 1 inRouter0(config-if)# exit
        ```
        
4. **Test the ACL**
    - From PC1 (192.168.1.10), ping PC3 (should succeed):
        ```
        ping 192.168.3.10        ```
        
    - From PC2 (192.168.2.10), ping PC3 (should fail):
        
        ```
        ping 192.168.3.10
        ```
        

# 3: Create an extended ACL to block specific applications

1. **Setup an application server**
    - Configure PC2 as a server by enabling HTTP and FTP services:
        - Click on PC2
        - Go to Services tab
        - Enable HTTP and FTP services

2. **Configure extended ACL**
    - Access the Router0 CLI:
        ```
        Router0> enableRouter0# configure terminal
        ```
        
    - Create an extended ACL to block HTTP (port 80) and FTP (ports 20, 21) traffic:
        ```
        Router0(config)# access-list 102 deny tcp any any eq 80Router0(config)# access-list 102 deny tcp any any eq 21Router0(config)# access-list 102 deny tcp any any eq 20Router0(config)# access-list 102 permit ip any any
        ```
        
3. **Apply the ACL to an interface**
    - Apply the ACL to the G0/1 interface in the inbound direction:
        ```
        Router0(config)# interface GigabitEthernet0/1Router0(config-if)# ip access-group 102 inRouter0(config-if)# exit
        ```
        
4. **Test the ACL**
    - From PC1:
        - Open command prompt and ping PC2 (should succeed):
            ```
            ping 192.168.2.10
            ```
        - Open Web Browser application and try to access http://192.168.2.10 (should fail)
        - Open a Desktop > FTP client and try to connect to PC2's IP address using default FTP port (should fail)
    - To verify that the ACL is specifically blocking these applications and not all traffic, try to ping PC2 from PC1 (should succeed)


---

