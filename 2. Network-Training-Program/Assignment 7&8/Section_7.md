## 1. Download iperf in laptop/phone and make sure they are in same network. Try different iperf commands with tcp, udp, birectional, reverse, multicast, parallel options and analyze the bandwidth and rate of transmission, delay, jitter etc.

iPerf3 is a tool for active measurements of the maximum achievable bandwidth on IP networks. It supports tuning of various parameters related to timing, buffers and protocols (TCP, UDP, SCTP with IPv4 and IPv6). For each test it reports the bandwidth, loss, and other parameters.

- Install iperf3 in both laptop and phone
  - Laptop: `sudo apt install iperf3`
  - Phone: `pkg install iperf3`
- Run iperf3 server on laptop: `iperf3 -s`
- Client can connect to the server using: `iperf3 -c <ip_address>`

1. **TCP (Reliable, Connection-Oriented)** → Packets are sent sequentially with acknowledgments (ACKs), ensuring **ordered and reliable delivery** but with **congestion control** limiting bandwidth.
2. **UDP (Fast, Unreliable)** → Packets are sent **without acknowledgments**, making it **faster** but prone to **packet loss and jitter**, useful for **real-time streaming and VoIP**.
3. **Bidirectional (`--bidir`)** → Simultaneously sends and receives data **between client and server**, testing **both uplink and downlink throughput**.
4. **Reverse (`-R`)** → The **server sends data to the client**, useful for measuring **download speeds** instead of upload.
5. **Multicast (`-u -B <multicast-IP>`)** → The server sends **one packet to multiple clients** in a multicast group using **UDP**, reducing redundant transmissions.
6. **Parallel (`-P <N>`)** → Runs **multiple data streams** simultaneously to **stress test bandwidth and measure parallel throughput**.

---

## TCP

By default..data is transferred using TCP 

![](./img/Pasted%20image%2020250316155327.webp)

---

## UDP

Connect to the server using: `iperf3 -c <ip_address> -u -b 10M` : to transfer 10MBytes

![](./img/Pasted%20image%2020250316155851.webp)

---

## birectional

- Connect to the server: `iperf3 -c <ip_addr> -u -b 10M --bdir`

![](./img/Pasted%20image%2020250316160102.webp)

---

## reverse

`iperf3 -c <ip_addr> -u -b 10M -R`

![](./img/Pasted%20image%2020250316160232.webp)

---

## multicast
-ERROR:  multicasting option doesnt exist in iperf3

- `-s` → Starts **iPerf in server mode** (listens for connections).
- `-u` → Uses **UDP mode** (required for multicast).
- `-B 239.255.1.1` →
    - **Binds the server to the multicast group** `239.255.1.1`.
    - **Multicast IP range:** `224.0.0.0` - `239.255.255.255`.
    - Only devices **joining this multicast group** can receive the data.
- `-i 1` → Sets the **reporting interval** to **1 second**.
    - The server will **display real-time bandwidth stats every 1 second**.
- `-T 32` → **Sets the TTL (Time-To-Live) to 32 hops**.
    - Controls how far multicast packets can travel.
    - Default TTL is **1**, meaning packets stay in the local network.
    - Increasing it **allows packets to pass through routers** if multicast is enabled.
- `-t 10` → Sends traffic for **10 seconds**.
- `-b 100M` →
    - **Sets bandwidth to 100 Mbps**.
    - UDP is not congestion-controlled like TCP, so setting a bandwidth limit is necessary.
    - Default (without `-b`) is **1 Mbps**.
    
![](./img/Pasted%20image%2020250316162301.webp)

![](./img/Pasted%20image%2020250316162322.webp)

---

## parallel
To Establish 10 simultaneous connections: `iperf3 -c <ip_addr> -P 10`

![](./img/Pasted%20image%2020250316160801.webp)

---
