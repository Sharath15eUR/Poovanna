
## 1. What are the pillars of Wi-Fi security?

The pillars of Wi-Fi security consist of three fundamental components that work together to protect wireless networks:

1. **Authentication**  
    Verifies the identity of users or devices before granting network access. Methods include:
    - **Pre-shared keys (PSK)** for personal networks
    - **802.1X/EAP** with RADIUS servers for enterprise networks
    - **WPA3-Enterprise** for enhanced certificate-based authentication
        
2. **Encryption**  
    Scrambles data to prevent eavesdropping using protocols like:
    - **AES-256** (strongest standard, used in WPA2/WPA3)
    - **TKIP** (older, deprecated in favor of AES)
    - **GCMP-256** (WPA3's more secure alternative to AES)
        
3. **Message Integrity**  
    Ensures transmitted data isn't altered maliciously via:
    - **Message Integrity Codes (MIC)** in WPA2
    - **256-bit BIP-GMAC** in WPA3 to detect forged packets


## 2. Explain the difference between authentication and encryption in WiFi security.

**Authentication** means verifying the identity of devices/users attempting to connect to the network.  
It determines **WHO can access the network**. It's the process of verifying identity before allowing connection.

- **Open Authentication**: No credentials required (e.g., public hotspots).
- **Pre-Shared Key (PSK)**: Uses a password (e.g., WPA2-Personal).
- **802.1X/EAP**: Enterprise-grade authentication via RADIUS servers (e.g., WPA3-Enterprise).  
    **Role**: Acts as a "bouncer," ensuring only authorized devices join the network.
    
**Encryption** determines **HOW data is protected** once on the network. It scrambles the transmitted data so only authorised parties can understand it.  

- **WEP**: Uses RC4 encryption (easily cracked, deprecated)
- **WPA/WPA2**: Uses AES-CCMP or TKIP (TKIP is weaker)
- **WPA3**: Uses GCMP-256 and SAE for stronger protection
    **Role**: Acts as a "scrambler," rendering intercepted data unreadable


## 3. Explain the differences between WEP, WPA, WPA2, and WPA3.

|**Feature**|**WEP** (1997)|**WPA** (2003)|**WPA2** (2004)|**WPA3** (2018)|
|---|---|---|---|---|
|**Encryption**|RC4 (64/128-bit)|TKIP/RC4 (128-bit)|AES-CCMP (128/256-bit)|AES-GCMP (128/192/256-bit)|
|**Authentication**|Open/Shared Key|PSK/Enterprise (802.1X)|PSK/Enterprise|SAE/Enterprise (192-bit mode)|
|**Key Management**|Static (manual updates)|Dynamic per-packet keys|Dynamic keys|Unique per-device keys|
|**Security**|**Weak** (crackable in <1h)|**Moderate** (TKIP vulnerable)|**Strong** (KRACK vulnerability)|**Very Strong** (KRACK-resistant)|
|**Handshake**|None|4-way handshake|4-way handshake|SAE (dragonfly handshake)|
|**Use Case**|**Deprecated**|**Legacy systems**|**Current standard**|**Future-proof**|

1. **Encryption Strength**
    - **WEP**: Uses RC4 stream cipher with small IVs, leading to key reuse
    - **WPA**: Improves WEP with TKIP (temporary fix) but retains RC4
    - **WPA2**: Introduces AES-CCMP, a military-grade block cipher
    - **WPA3**: Upgrades to AES-GCMP with 192/256-bit keys for enterprise
        
2. **Authentication**
    - **WPA3-Personal**: Replaces PSK with SAE, preventing offline brute-force attacks
    - **WPA3-Enterprise**: Adds 192-bit cryptographic suites for sensitive data
        
3. **Vulnerabilities**
    - **WEP**: Easily cracked with tools like Aircrack-ng
    - **WPA**: Susceptible to TKIP attacks (e.g., Beck-Tews
    - **WPA2**: KRACK attack exploits 4-way handshake
    - **WPA3**: Mitigates KRACK via SAE and forward secrecy[.
        
4. **Adoption**
    - **WPA2** dominates due to device compatibility.
    - **WPA3** requires new hardware (e.g., Wi-Fi 6 routers).
        
|Feature|WEP|WPA|WPA2|WPA3|
|---|---|---|---|---|
|**Encryption**|RC4 (64/128-bit)|TKIP/RC4|AES-CCMP|AES-GCMP/SAE|
|**Authentication**|Open/Shared Key|PSK/802.1X|PSK/802.1X|SAE/192-bit Enterprise|
|**Security**|Broken (1999)|Vulnerable (TKIP)|KRACK vulnerability|Quantum-resistant|
|**Use Case**|Never use|Legacy devices|General use|Future-proof networks|

WPA3 represents the current gold standard, combining individualized encryption, brute-force protection, and quantum-resistant algorithms.


## 4. Why is WEP considered insecure compared to WPA2 or WPA3?

WEP (Wired Equivalent Privacy) is considered **fundamentally broken** due to critical design flaws, while WPA2 and WPA3 address these vulnerabilities with modern security measures.

**1. Weak Encryption**
- **WEP**: Uses **RC4 stream cipher** with a **24-bit initialization vector (IV)**. IVs repeat frequently (after ~5,000 packets), enabling attackers to crack keys via **IV collisions** and **keystream reuse**[
- **WPA2**: Replaces RC4 with **AES-CCMP**, a robust block cipher resistant to key-reuse attacks.
- **WPA3**: Introduces **AES-GCMP-256**, offering quantum-resistant encryption.

**2. Authentication Vulnerabilities**
- **WEP**: Relies on **shared static keys** (same key for all devices). No mutual authentication, making it prone to **rogue AP attacks
- **WPA2/WPA3**:
    - **WPA2-Personal**: Uses **PSK with salting** to mitigate brute-force attacks.
    - **WPA3-Personal**: Replaces PSK with **SAE (Simultaneous Authentication of Equals)**, eliminating offline dictionary attacks.
    - **Enterprise**: Implements **802.1X/EAP** for certificate-based authentication.
        
**3. Key Management Flaws**
- **WEP**:
    - **Static keys** (never rotated unless manually changed).
    - **No forward secrecy**: Compromised keys decrypt past traffic
- **WPA2/WPA3**:
    - **Dynamic key generation** (per session).
    - **Forward secrecy** (WPA3): Past sessions remain secure even if the password is leaked.
        
**4. Integrity Protection**
- **WEP**: Uses **CRC-32 checksum**, which is linear and easily manipulated (allows **packet injection/modification**)
- **WPA2**: Implements **MIC (Message Integrity Code)** with AES-CCMP.
- **WPA3**: Uses **256-bit BIP-GMAC** for tamper-proof integrity checks.

**5. Attack Susceptibility**

| **Attack**             | **WEP** | **WPA2** | **WPA3** |
| ---------------------- | ------- | -------- | -------- |
| **IV/Keystream Reuse** | Yes     | No       | No       |
| **Brute-Force (PSK)**  | Yes     | Yes      | No (SAE) |
| **KRACK (Handshake)**  | N/A     | Yes      | No       |
| **Packet Injection**   | Yes     | Limited  | Blocked  |

Therefore the main reasons for WEPs weaknesses are:
1. **RC4 Weaknesses**: Flaws in RC4 allow key recovery from captured packets
2. **24-bit IV**: Exhausts quickly, causing IV reuse and keystream repetition
3. **No Mutual Authentication**: Allows rogue devices to impersonate APs
4. **Static Keys**: No automatic rotation, making key compromise permanent
    
**WPA2** mitigated these issues with AES and improved key management, while **WPA3** introduced SAE and forward secrecy to address WPA2’s lingering vulnerabilities. For modern networks, **WEP is obsolete** and **WPA3 is the gold standard**.


## 5. Why was WPA2 introduced?

**WPA2 was introduced** primarily to **address critical security flaws in its predecessors (WEP and WPA)** and to **implement the finalized IEEE 802.11i standard**. The main purpose of its introduction are as follows:

**1. Replace Insecure Protocols**
- **WEP's Failures**: Used **RC4 encryption** with weak **24-bit IVs**, making it crackable in minutes
- **WPA's Limitations**: Introduced **TKIP** as a stopgap but retained RC4, leaving vulnerabilities like **Beck-Tews attacks
- **WPA2's Fix**: Adopted **AES-CCMP**, a military-grade encryption standard resistant to key-reuse attacks

**2. Implement IEEE 802.11i's Robust Security**
WPA2 fully incorporated the **802.11i standard**, which:
- **Separated authentication from encryption** for stronger security
- **Introduced CCMP** for data confidentiality, integrity, and authentication
- **Enabled enterprise-grade 802.1X/EAP authentication** for large networks

**3. Enhance Encryption and Authentication**
- **AES Encryption**: Replaced RC4 with **128-bit AES**, which is quantum-resistant and immune to WEP-style attacks
- **CCMP Protocol**: Used **counter mode** for encryption and **CBC-MAC** for integrity checks, preventing packet tampering
- **Enterprise Mode**: Added **RADIUS server support** for per-user authentication.

**4. Improve Performance and Compatibility**
- **Backward Compatibility**: Supported **TKIP fallback** for older devices while prioritizing AES
- **Seamless Roaming**: Enabled **PMK caching** and **pre-authentication** for uninterrupted connectivity across multiple APs.

In short, WPA2 was introduced to **eliminate the risks of WEP/WPA** and **standardize enterprise-grade wireless security**.


## 6. What is the role of the Pairwise Master Key (PMK) in the 4-way handshake?

The Pairwise Master Key (PMK) plays a foundational role in the 4-way handshake process. It serves as the secure starting point from which all other session keys are derived. Some core functions include: 

1. **Source of Cryptographic Material**
    - The PMK is the primary keying material used to derive the working keys
    - It's never directly transmitted over the network, preserving its security
2. **Authentication Foundation**
    - Knowledge of the PMK serves as proof of identity for both parties
    - Only authorized devices with the correct PMK can complete the handshake
3. **Key Derivation Input**
    - The PMK is used as input to derive the Pairwise Transient Key (PTK)
    - The PTK calculation: PTK = PRF(PMK + ANonce + SNonce + MAC addresses)
    - Where PRF is a pseudorandom function (typically HMAC-SHA1)


The PMK comes from one of two sources, depending on the authentication method:
- **WPA/WPA2-Personal (PSK) Mode:**
    - PMK = PBKDF2(passphrase, SSID, 4096 iterations, 256 bits)
    - The passphrase is converted to the PMK using this key derivation function
    - Both client and AP independently calculate the same PMK from the shared passphrase
- **WPA/WPA2-Enterprise (802.1X) Mode:**
    - PMK is derived from the Master Session Key (MSK) from the EAP authentication
    - The authentication server provides the PMK to the access point
    - Typically 256 bits (32 bytes) in length

Its important during the 4 way handshake because of its: 
- **Implicit Authentication:** The ability to correctly derive the PTK and calculate valid MICs implicitly proves knowledge of the PMK
- **Security Anchor:** The PMK never changes during a session, while the PTK can be refreshed periodically
- **Separation of Concerns:** The PMK remains constant, while derived keys handle specific security functions

The PMK is essentially the "shared secret" that enables the entire secure association process while never being directly exposed during the handshake. This design provides strong security because an attacker would need to know the PMK to successfully complete the handshake or decrypt the traffic, even if they capture all the handshake messages.


## 7. How does the 4-way handshake ensure mutual authentication between the client and the access point?

The 4-way handshake is a critical security mechanism in Wi-Fi Protected Access (WPA/WPA2/WPA3) that ensures mutual authentication between a client and an access point. 

The 4-way handshake serves three main purposes:

1. Confirm that both parties possess the correct Pre-Shared Key (PSK)
2. Establish a fresh Pairwise Transient Key (PTK) for encrypting the session
3. Enable secure transmission of the Group Temporal Key (GTK) for multicast/broadcast traffic

The process runs as follows: 

Before the handshake, the prerequisites include: 
- Both sides already share a Pairwise Master Key (PMK)
    - In WPA-Personal, this is derived from the Pre-Shared Key (passphrase)
    - In WPA-Enterprise, this comes from the 802.1X/EAP authentication process

Message 1: Access Point → Client
- AP sends a random nonce (ANonce) to the client
- No encryption yet, as the keys haven't been generated

Message 2: Client → Access Point
- Client generates its own random nonce (SNonce)
- Client derives the PTK using: PMK + ANonce + SNonce + MAC addresses
- Client sends SNonce and a Message Integrity Code (MIC)
- The MIC proves the client knows the PMK without revealing it

Message 3: Access Point → Client
- AP can now derive the same PTK independently
- AP sends the GTK (encrypted with PTK) and another MIC
- This MIC proves the AP knows the PMK (mutual authentication)

Message 4: Client → Access Point
- Client sends acknowledgment with a MIC
- Confirms successful installation of keys
- The session is now secure for data transmission

Through this the security benefits include:
- Mutual authentication: Both parties prove knowledge of the shared secret
- Fresh session keys: New keys for each session prevent replay attacks
- Forward secrecy: Even if PSK is compromised later, previous sessions remain secure
- Protection against man-in-the-middle attacks: The authentication is cryptographically verified

The 4-way handshake is particularly elegant because it enables mutual authentication without either party actually transmitting the original key material, maintaining security even on an unencrypted channel.


## 8. What will happen if we put a wrong passphrase during a 4Way handshake?

When an incorrect passphrase is used during the WPA2 4-way handshake:
1. **PMK derivation fails**: The Pairwise Master Key (PMK) is derived from the passphrase and network SSID using PBKDF2. An incorrect passphrase produces an invalid PMK
2. **PTK mismatch**: Since the PTK (Pairwise Transient Key) is generated using the PMK, nonces, and MAC addresses, a wrong PMK leads to an incorrect PTK on the client side. The client's MIC (Message Integrity Code) calculations will not match the AP's expectations.
3. **Handshake failure**: During message 3 verification, the client compares the AP's MIC with its own calculation. A mismatch (due to incorrect PTK) causes the client to reject the handshake. The AP never receives a valid message 4 acknowledgment.
4. **No network access**: The handshake fails entirely, preventing the client from installing the encryption keys needed to communicate securely with the AP.



## 9. What problem does 802.1X solve in a network?


802.1X solves the fundamental problem of unauthorized network access. Without 802.1X, networks face these critical vulnerabilities:
- **Open Port Access**: Any device physically connected to a network port (wired) or within range (wireless) can potentially access the network without verification.
- **Identity Uncertainty**: Networks cannot reliably identify who is connecting, only recognizing device MAC addresses which can be spoofed.
- **Weak Authentication**: Pre-shared key methods (like WPA2-Personal) use the same password for all users, which can be leaked or compromised.
- **Rogue Devices**: Unauthorized devices can connect to the network and potentially access sensitive resources or launch attacks from within.
- **Network Visibility Gaps**: IT administrators lack visibility into who is accessing the network and when.
    
802.1X addresses these issues by implementing port-based access control that requires authentication before any network access is granted, essentially creating a secure "lobby" where users must verify their identity before being allowed into the network.



## 10. How does 802.1X enhance security over wireless networks?

802.1X significantly enhances wireless network security through port-based access control. Here's how it provides superior protection compared to traditional wireless security methods:

- **Authentication Framework**: 802.1X requires users to authenticate before accessing network resources, preventing unauthorized devices from connecting to the network.
- **EAP Integration**: Uses Extensible Authentication Protocol (EAP) to support various authentication methods like certificates, tokens, or credentials.
- **User-based Access Control**: Authenticates individual users rather than just devices, ensuring personalized security policies.
- **Dynamic Encryption Keys**: Generates unique encryption keys for each session, eliminating vulnerabilities of static pre-shared keys.
- **Centralized Authentication**: Works with RADIUS servers to provide enterprise-grade authentication management.
- **Mutual Authentication**: Can verify both the client and the network, protecting against rogue access points.
    

---
