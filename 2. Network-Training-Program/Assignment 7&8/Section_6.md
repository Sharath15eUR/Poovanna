### 1. Try Static NAT, Dynamic NAT and PAT to translate IPs


- We can follow the same steps to setup NAT as we did in Assignment5&6 in the NAT question.

- To remove all NAT-related configurations we can use the `no` command:
	1. Remove all NAT translations:
    ```
    Router(config)# no ip nat inside source
    ```

	2. Remove NAT pool definitions (if any were created):
    ```
    Router(config)# no ip nat pool MY_POOL
    ```

	3. Remove NAT interface designations:
    ```
    Router(config)# interface FastEthernet0/0
    Router(config-if)# no ip nat inside
    Router(config-if)# exit
    Router(config)# interface FastEthernet0/1
    Router(config-if)# no ip nat outside
    ```



- one more thing which we need to do before we do any of the below methods, is config which interface should be nat outside or nat inside.
	`$ ip nat outside`
	`$ ip nat inside`
- Therefore the part of the interface having the private address should be nat inside.
---

- Enter into global config mode in the router and do the following:

### 1. Static NAT 

1. Configure static mapping:
    ```
    Router(config)# ip nat inside source static 192.168.1.2 203.0.113.100
    ```
2. Test by pinging from the statically mapped PC
3. Capture and verify source IP is translated to 203.0.113.100

	![[Pasted image 20250318131048.webp]]

	![[Pasted image 20250318131122.webp|636]]

---

### 2. Dynamic NAT

1. Remove previous NAT configuration:
    ```
    Router(config)# no ip nat inside source static 192.168.1.2 203.0.113.100
    ```
    
2. Define a pool of public addresses:
    ```
    Router(config)# ip nat pool MY_POOL 203.0.113.100 203.0.113.110 netmask 255.255.255.0
    ```
    
3. Configure dynamic NAT:
    ```
    Router(config)# ip nat inside source list 1 pool MY_POOL
    ```
    
4. Test by pinging from internal PCs
5. Capture and verify different PCs get different IPs from the pool

---

### 3. PAT (Port Address Translation)

1. Remove previous NAT configuration:
    ```
    Router(config)# no ip nat inside source list 1 pool MY_POOL
    ```
    
2. Configure PAT:
    ```
    Router(config)# ip nat inside source list 1 interface FastEthernet0/1 overload
    ```
    
3. Test by having multiple internal PCs ping simultaneously
4. Capture and analyze traffic - note all internal IPs translate to the same external IP with different ports

- Therefore as we can see the global address will be the same as the gateway of the router.

	![[Pasted image 20250318130502.webp]]

	![[Pasted image 20250318130404.webp]]

---

- After configuring any NAT type, verify translations:
```
Router# show ip nat translations
Router# show ip nat statistics
```

- This will display active translations and statistics about NAT operation.

---
