
## 1. What are the different 802.11 PHY layer standards? Compare their characteristics.


|**Standard**|**Wi-Fi Gen**|**Year**|**PHY Name**|**Frequency**|**Max Speed**|**Modulation**|**Channel Width**|**Key Features**|
|---|---|---|---|---|---|---|---|---|
|**802.11**|-|1997|IR / FHSS / DSSS|2.4 GHz|2 Mbps|DBPSK / DQPSK|20 MHz|First Wi-Fi standard|
|**802.11b**|Wi-Fi 1|1999|DSSS|2.4 GHz|11 Mbps|CCK|20 MHz|Long range, low speed|
|**802.11a**|Wi-Fi 2|1999|OFDM|5 GHz|54 Mbps|BPSK to 64-QAM|20 MHz|Shorter range, faster than b|
|**802.11g**|Wi-Fi 3|2003|OFDM|2.4 GHz|54 Mbps|BPSK to 64-QAM|20 MHz|Backward compatible with 802.11b|
|**802.11n**|Wi-Fi 4|2009|HT (High Throughput)|2.4/5 GHz|600 Mbps|BPSK to 64-QAM|20/40 MHz|MIMO, channel bonding|
|**802.11ac**|Wi-Fi 5|2013|VHT (Very High Throughput)|5 GHz|3.5 Gbps|BPSK to 256-QAM|20/40/80/160 MHz|MU-MIMO, beamforming|
|**802.11ax**|Wi-Fi 6|2019|HE (High Efficiency)|2.4/5 GHz|9.6 Gbps|BPSK to 1024-QAM|20/40/80/160 MHz|OFDMA, TWT, improved MU-MIMO|
|**802.11ax**|Wi-Fi 6E|2020|HE + 6 GHz|6 GHz|9.6 Gbps|BPSK to 1024-QAM|20/40/80/160 MHz|New 6 GHz band, less interference|
|**802.11be**|Wi-Fi 7|~2024|EHT (Extremely High Throughput)|2.4/5/6 GHz|46 Gbps|BPSK to 4096-QAM|Up to 320 MHz|MLO (multi-link), 16x16 MU-MIMO, 4096-QAM|


- **WiFi 1 (802.11, 1997)** - The original standard was extremely slow (2 Mbps) using basic transmission techniques (FHSS, DSSS). 
- **WiFi 2 & 3 (802.11b/a/g, 1999-2003)** - These early improvements brought speeds up to 54 Mbps. The 802.11g version was particularly important as it worked with older devices while delivering faster speeds.
- **WiFi 4 (802.11n, 2009)** - A major leap forward that introduced MIMO technology (multiple antennas) and could use both 2.4 GHz and 5 GHz frequencies. Speed jumped to 600 Mbps, making video streaming practical.
- **WiFi 5 (802.11ac, 2013)** - Focused on the less crowded 5 GHz band with wider channels and more complex data encoding (256-QAM), reaching speeds of 6.9 Gbps. This made 4K streaming and fast file transfers possible.
- **WiFi 6/6E (802.11ax, 2019-2021)** - Added OFDMA technology to handle many devices simultaneously and expanded to the 6 GHz band. With speeds up to 9.6 Gbps, it's designed for dense environments with many connected devices.
- **WiFi 7 (802.11be, Upcoming)** - Will push speeds to 46 Gbps with even more advanced techniques, supporting future applications like augmented reality and 8K video.

- **Modulation**: Determines how data is transmitted on a wave. Higher-order QAM (like 1024-QAM or 4096-QAM) allows for more data per signal, but is more sensitive to noise.
- **Channel Width**: Wider channels = more data. 802.11n introduced 40 MHz; later standards went up to 320 MHz (Wi-Fi 7).
- **MIMO (Multiple Input, Multiple Output)**: Uses multiple antennas to send/receive more data simultaneously.
- **OFDMA (Orthogonal Frequency Division Multiple Access)**: Divides a channel into sub-channels, increasing efficiency for many users (used from Wi-Fi 6).
- **MU-MIMO**: Multiple users can transmit/receive simultaneously. Advanced in Wi-Fi 5 and 6.
- **MLO (Multi-Link Operation)**: Wi-Fi 7 feature that lets devices use multiple bands at once for better speed and latency.


## 2. What are DSSS and FHSS? How do they work?

DSSS and FHSS are two fundamental spread spectrum technologies used in wireless communications to improve reliability, security, and resistance to interference. Both techniques spread the signal across a wider bandwidth than minimally required, but they accomplish this in distinctly different ways.

#### Direct Sequence Spread Spectrum (DSSS)####

1. **Bit Spreading**: Each data bit is multiplied by a higher-rate pseudorandom bit sequence called a "chip sequence" or "spreading code"
2. **Spreading Process**:
    - Original data bit (0 or 1) is multiplied by each bit in the chip sequence
    - Typically uses Barker codes (11-chip sequence) or complementary codes
    - Example: A single data bit might be converted into 11 chips
3. **Transmission**: The resulting chip sequence is modulated onto the carrier wave
4. **Reception**: Receiver uses the same spreading code to correlate and extract the original data


#### Frequency Hopping Spread Spectrum (FHSS)####

1. **Channel Division**: Available frequency band is divided into multiple narrow channels
2. **Hopping Sequence**: Transmitter and receiver share a predetermined pseudorandom hopping pattern
3. **Rapid Switching**: Carrier frequency changes (hops) according to this pattern at fixed time intervals
4. **Dwell Time**: Amount of time spent on each frequency (typically milliseconds)
5. **Synchronization**: Both transmitter and receiver must maintain synchronization to the hopping pattern


| Aspect                      | DSSS                                                         | FHSS                                                          |
| --------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------- |
| **Interference Resistance** | Excellent rejection of narrowband interference               | Good resistance through frequency diversity                   |
| **Jamming Susceptibility**  | Resistant to narrowband jamming                              | Highly resistant to jamming unless all frequencies are jammed |
| **Security**                | Good (requires knowledge of spreading code)                  | Better (requires both code and hopping pattern)               |
| **Complexity**              | More complex synchronization                                 | Simpler receiver design                                       |
| **Near-Far Problem**        | More susceptible                                             | Less susceptible                                              |
| **Spectral Efficiency**     | Lower                                                        | Higher for multiple co-located systems                        |
| **Power Density**           | Lower power density                                          | Higher power in each channel                                  |
| **Implementation**          | Used in 802.11b (Wi-Fi), GPS, CDMA, GPS satellite navigation | Used in Bluetooth, early 802.11, military systems             |


DSSS provides better performance in terms of data rates and distance for fixed applications, while FHSS offers better security, resistance to selective jamming, and is often preferred for mobile applications or environments with multiple systems.


## 3. How do modulation schemes work in the PHY layer? Compare different modulation schemes and their performance across various Wi-Fi standards.


Modulation is a core technique in this layer that encodes digital information onto analog carrier waves.Modulation schemes work by varying one or more properties of a carrier wave (amplitude, frequency, or phase) to represent digital data. The basic process involves:

1. Taking binary data (1s and 0s)
2. Mapping these bits to symbols according to the modulation scheme
3. Adjusting the carrier wave's properties based on these symbols
4. Transmitting the modulated signal through the air

The receiver then demodulates the signal to recover the original data.

Wi-Fi uses **digital modulation** schemes, mainly:
- **BPSK (Binary Phase Shift Keying)**: Uses two phase states (0° and 180°) to encode 1 bit per symbol
- **QPSK (Quadrature Phase Shift Keying)**: Uses four phase states to encode 2 bits per symbol
- **QAM (Quadrature Amplitude Modulation)**: Combines amplitude and phase modulation to encode more bits per symbol (16-QAM, 64-QAM, 256-QAM, etc.)

| Standard | Primary Modulation Schemes | Max Data Rate | Key Features |
|----------|----------------------------|--------------|--------------|
| 802.11b  | DBPSK, DQPSK, CCK         | 11 Mbps      | Simple but low throughput, 2.4 GHz only |
| 802.11a/g | BPSK, QPSK, 16-QAM, 64-QAM with OFDM | 54 Mbps | OFDM improved spectral efficiency |
| 802.11n  | BPSK to 64-QAM with OFDM  | 600 Mbps     | Added MIMO and 40 MHz channels |
| 802.11ac | BPSK to 256-QAM with OFDM | 6.9 Gbps     | 5 GHz, wider channels (up to 160 MHz), MU-MIMO |
| 802.11ax | BPSK to 1024-QAM with OFDMA | 9.6 Gbps   | OFDMA, longer symbol duration, both 2.4/5 GHz |
| 802.11be | Up to 4096-QAM with OFDMA | 46 Gbps      | 320 MHz channels, multi-link operation |

#### **Performance Tradeoffs**
 
 **Spectral Efficiency vs. Reliability**
 
Higher-order modulation schemes (like 256-QAM or 1024-QAM) pack more bits into each symbol, offering higher data rates, but with tradeoffs:
- **Higher data rates**: More bits per symbol means faster transmission
- **Reduced range**: Higher-order modulations require better signal quality
- **Lower reliability**: More susceptible to noise and interference
- **Adaptive modulation**: Modern Wi-Fi dynamically adjusts modulation based on channel conditions

|**Modulation Scheme**|**Bits per Symbol**|**Explanation**|**Approx. SNR Required**|**Wi-Fi Standards**|
|---|---|---|---|---|
|**BPSK** (Binary PSK)|1 bit|2 phase states (0°, 180°). Very robust, slowest.|~6 dB|802.11a, b, g, n, ac, ax, be|
|**QPSK** (Quadrature PSK)|2 bits|4 phase shifts (0°, 90°, 180°, 270°). Doubles BPSK speed.|~10 dB|802.11a, g, n, ac, ax, be|
|**16-QAM**|4 bits|4 phase × 4 amplitude levels. More data per symbol.|~16 dB|802.11n, ac, ax, be|
|**64-QAM**|6 bits|8×8 constellation. High throughput, more prone to noise.|~22 dB|802.11n, ac, ax, be|
|**256-QAM**|8 bits|16×16 constellation. Very high speed, needs clean signal.|~28 dB|802.11ac, ax, be|
|**1024-QAM**|10 bits|32×32 constellation. Dense and efficient.|~35 dB|802.11ax (Wi-Fi 6/6E), be|
|**4096-QAM**|12 bits|64×64 constellation. Extreme efficiency, used in ideal conditions.|~41 dB|802.11be (Wi-Fi 7)|


## 4. What is the significance of OFDM in WLAN? How does it improve performance?

Key significance of OFDM (Orthogonal Frequency Division Multiplexing) include:

**1. Multipath Interference Mitigation**
OFDM divides the data stream into multiple narrowband subcarriers transmitted simultaneously. This approach effectively handles multipath propagation in indoor environments where signals reflect off walls and objects. By converting a high-speed serial transmission into multiple parallel slower transmissions, OFDM provides immunity against multipath fading and intersymbol interference (ISI).

**2. Spectral Efficiency**
OFDM achieves high spectral efficiency through:
- Orthogonally arranged subcarriers that can overlap without interference
- More efficient use of the available bandwidth compared to traditional modulation techniques
- Support for higher data rates within the same channel bandwidth

**3. Robustness Against Narrowband Interference**
Since OFDM spreads data across multiple subcarriers, damage to a few subcarriers affects only a small portion of the transmitted data, which can be recovered through error correction.


**OFDM improves performance through following ways:**

**1. Higher Data Rates**
By dividing the channel into multiple subcarriers and transmitting data in parallel, OFDM enables significantly higher data rates. This is particularly important for modern applications requiring high bandwidth.

**2. Extended Range**
OFDM's resistance to multipath effects and interference allows for more reliable connections at greater distances than would be possible with single-carrier approaches.

**3. Adaptive Modulation and Coding**
OFDM systems can dynamically adjust modulation schemes and coding rates for different subcarriers based on channel conditions, optimizing performance in variable environments.

**4. Efficient Spectrum Use**
The orthogonal nature of OFDM subcarriers allows them to be tightly packed without causing interference, achieving nearly optimal spectrum utilization.

**5. Simplified Equalization**
OFDM requires simpler equalization at the receiver compared to single-carrier systems, as each subcarrier experiences relatively flat fading, reducing implementation complexity.

**6. MIMO Compatibility**
OFDM works exceptionally well with Multiple-Input Multiple-Output (MIMO) techniques, further enhancing throughput and reliability in modern Wi-Fi standards.

OFDM's unique combination of spectral efficiency, interference resistance, and adaptability to challenging wireless environments has made it indispensable for high-performance WLANs.


## 5. How are frequency bands divided for Wi-Fi? Explain different bands and their channels.

Wi-Fi operates across several frequency bands, each divided into specific channels. The division of these bands and their channel structures significantly impacts wireless network performance, range, and compatibility.

There are **three main frequency bands** used in Wi-Fi communication:
- **2.4 GHz**: Great coverage, but crowded and slower.
- **5 GHz**: Faster with less interference, ideal for modern networks.
- **6 GHz**: Cutting-edge speed and capacity, future-ready but limited to new devices.

|Feature|**2.4 GHz**|**5 GHz**|**6 GHz (Wi-Fi 6E)**|
|---|---|---|---|
|**Frequency Range**|2.400 – 2.4835 GHz|5.150 – 5.825 GHz|5.925 – 7.125 GHz|
|**Wi-Fi Standards**|802.11b/g/n|802.11a/n/ac/ax|802.11ax (Wi-Fi 6E)|
|**Max Channel Width**|20 MHz (up to 40 MHz in some cases)|20, 40, 80, 160 MHz|20, 40, 80, 160 MHz|
|**Number of Channels**|14 (only 11 in most regions)|Up to 24 (varies by country)|Up to 59 (20 MHz)|
|**Non-Overlapping Channels**|3 (1, 6, 11)|Many (no overlap due to spacing)|All channels are non-overlapping|
|**Range**|Longest (best through walls)|Medium|Shortest (sensitive to walls)|
|**Speed**|Lowest (up to ~600 Mbps)|Higher (~1.3 Gbps or more)|Highest (up to 9.6 Gbps or more)|
|**Interference**|High (microwaves, Bluetooth, etc.)|Medium (used by fewer devices)|Low (new band, few devices)|
|**Device Compatibility**|Almost all Wi-Fi devices|Most modern devices|Only Wi-Fi 6E devices|
|**Best Use Case**|Wide coverage, older devices|Fast, stable connections (gaming/streaming)|Ultra-fast, low-latency apps (VR, AR, 4K/8K video)|

#### 2.4 GHz Band (2.412-2.484 GHz)
- **Range**: Excellent coverage, better penetration through walls and obstacles
- **Congestion**: Highly congested due to widespread use and interference from other devices (microwaves, Bluetooth, etc.)
- **Data rates**: Lower maximum speeds compared to higher bands
- **Used by**: 802.11b/g/n/ax standards

#### 2.4 GHz Channels
- **Total channels**: 14 channels (only 1-11 available in US, 1-13 in Europe)
- **Channel width**: Traditionally 20 MHz
- **Channel spacing**: 5 MHz apart (center frequencies)
- **Non-overlapping channels**: Only 3 non-overlapping channels (1, 6, 11) when using 20 MHz width


#### 5 GHz Band (5.15-5.85 GHz)
- **Range**: Shorter range than 2.4 GHz, less effective through obstacles
- **Congestion**: Less crowded, more available channels
- **Data rates**: Higher speeds possible
- **Used by**: 802.11a/n/ac/ax standards
- **Regulation**: Different portions have varying power limitations and indoor/outdoor usage rules

#### 5 GHz Channels
- **Channel organization**: Divided into sub-bands (UNII-1, UNII-2, UNII-2 Extended, UNII-3)
- **Channel widths**: 20, 40, 80, and 160 MHz supported
- **Non-overlapping channels**: Many more non-overlapping channels than 2.4 GHz
  - Up to 24 non-overlapping 20 MHz channels
  - Up to 12 non-overlapping 40 MHz channels
  - Up to 6 non-overlapping 80 MHz channels
  - Up to 2 non-overlapping 160 MHz channels
- **DFS channels**: Some channels require Dynamic Frequency Selection to avoid radar interference


#### 6 GHz Band (5.925-7.125 GHz)
- **Range**: Similar to 5 GHz but with less legacy interference
- **Congestion**: Least congested, 1200 MHz of new spectrum
- **Data rates**: Highest possible throughput
- **Used by**: 802.11ax (Wi-Fi 6E) and 802.11be (Wi-Fi 7)
- **Availability**: Recently opened in many countries, but regulatory status varies globally

#### 6 GHz Channels
- **Total spectrum**: 1200 MHz of available bandwidth
- **Channel widths**: 20, 40, 80, 160, and 320 MHz (with Wi-Fi 7)
- **Non-overlapping channels**:
  - Up to 59 non-overlapping 20 MHz channels
  - Up to 29 non-overlapping 40 MHz channels
  - Up to 14 non-overlapping 80 MHz channels
  - Up to 7 non-overlapping 160 MHz channels
  - Up to 3 non-overlapping 320 MHz channels (Wi-Fi 7)


#### 60 GHz Band (57-71 GHz)
- **Range**: Very limited range, line-of-sight required
- **Data rates**: Extremely high throughput (multi-gigabit)
- **Used by**: 802.11ad/ay (WiGig)
- **Applications**: Specialized short-range, high-bandwidth applications


## 6. What is the role of Guard Intervals in WLAN transmission? How does a short Guard Interval improve efficiency?

Guard Intervals (GI) are time buffers inserted between OFDM symbols in WLAN transmissions to prevent inter-symbol interference caused by multipath propagation, where signals arrive at different times due to reflections.

When wireless signals travel via multiple paths, delayed signals from one symbol can overlap with the next symbol. The guard interval provides time for these delayed components to settle before the next symbol begins, preserving orthogonality between subcarriers.

A short guard interval (400ns vs standard 800ns) improves efficiency by:

- Reducing overhead time between symbols
- Allowing more data symbols to be transmitted in the same timeframe
- Increasing throughput by approximately 10-11%

This efficiency boost comes with a trade-off: short guard intervals work best in environments with minimal signal delay spread. In conditions with significant multipath delays, short guard intervals may introduce interference rather than prevent it.


## 7. Describe the structure of an 802.11 PHY layer frame. What are its key components?


The 802.11 PHY layer frame consists of three main parts:
1. Preamble
2. PHY Layer Convergence Protocol (PLCP) Header
3. PSDU (PHY Service Data Unit)

#### 1. Preamble

This enables receivers to detect a signal is coming (whether it is carrier sensing) and synchronise their timing with the transmitter
- It is made up of 2 parts:
    - **Short Training Field (STF)**: 10 short symbols used for signal detection, automatic gain control, and coarse frequency correction
    - **Long Training Field (LTF)**: 2 long symbols used for channel estimation and fine frequency correction

#### 2. PLCP Header

This contains critical information about how to decode the following data
- This is composed of:
    - **Signal Field**: Contains modulation and coding scheme (MCS) information
    - **Rate**: Indicates the data rate for transmission
    - **Length**: Specifies how long the frame is
    - **Service Field**: Reserved bits for future use
    - **Parity Bit**: For error detection
    - **Tail Bits**: Used to return convolutional encoder to zero state

#### 3. PSDU (Data)

This contains the actual data being transmitted
- This is made up of:
    - **MAC Header**: Addressing and control information
    - **Frame Body**: The actual data being transmitted
    - **FCS (Frame Check Sequence)**: For error detection (typically CRC-32)



## 8. What is the difference between OFDM and OFDMA?

OFDM (Orthogonal Frequency Division Multiplexing) and OFDMA (Orthogonal Frequency Division Multiple Access) are both multiplexing techniques used in wireless communications.
Orthogonal Frequency Division Multiplexing (OFDM) divides the channel into multiple subcarriers, allowing parallel data transmission and better resilience against interference. OFDMA (in 802.11ax/Wi-Fi 6 and newer) takes this further by allowing multiple users to share subcarriers simultaneously.

The main difference is that OFDM serves one user at a time using all available frequency resources, while OFDMA can serve multiple users simultaneously by allocating portions of the frequency spectrum to each user, making it more efficient for environments with many connected devices.

| Feature                 | OFDM (Orthogonal Frequency Division Multiplexing)                          | OFDMA (Orthogonal Frequency Division Multiple Access)                      |
| ----------------------- | -------------------------------------------------------------------------- | -------------------------------------------------------------------------- |
| **Definition**          | Divides a channel into multiple subcarriers that transmit data in parallel | Evolution of OFDM that allows subcarrier allocation to different users     |
| **Resource Allocation** | One user gets entire channel bandwidth at a time                           | Channel bandwidth divided among multiple users simultaneously              |
| **User Servicing**      | Serves one user at a time using all available subcarriers                  | Can serve multiple users simultaneously, each with specific subcarriers    |
| **Efficiency**          | Less efficient in multi-user scenarios as users must take turns            | More efficient for multiple users, especially with small data packets      |
| **Latency**             | Higher latency in multi-user environments due to waiting                   | Lower latency as users don't need to wait their turn                       |
| **Wi-Fi Standards**     | Wi-Fi 4 (802.11n) and earlier                                              | Introduced in Wi-Fi 5 (802.11ac), expanded in Wi-Fi 6 (802.11ax)           |
| **Use Case**            | Better for scenarios with fewer, high-bandwidth users                      | Ideal for dense environments with many devices (IoT, busy networks)        |
| **Scheduling**          | Simple scheduling (first come, first served)                               | Complex scheduling based on user needs and priorities                      |
| **Analogy**             | Like having all lanes on a highway dedicated to one vehicle at a time      | Like dividing highway lanes so multiple vehicles can travel simultaneously |


## 9. What is the difference between MIMO and MU-MIMO?


| Feature             | MIMO (Multiple Input Multiple Output)                                  | MU-MIMO (Multi-User MIMO)                                                   |
| ------------------- | ---------------------------------------------------------------------- | --------------------------------------------------------------------------- |
| **Definition**      | Uses multiple antennas to send/receive multiple data streams           | Uses multiple antennas to communicate with multiple devices simultaneously  |
| **Target**          | Single device at a time                                                | Multiple devices concurrently                                               |
| **Purpose**         | Increase throughput and reliability for one user                       | Serve several users at once without making them wait                        |
| **Operation**       | Creates multiple data paths between router and single device           | Divides available bandwidth to communicate with several devices in parallel |
| **Primary Benefit** | Improved speed and connection reliability for individual devices       | Enhanced network efficiency in multi-device environments                    |
| **Use Case**        | High-bandwidth applications for a single device (HD streaming, gaming) | Busy networks with many connected devices (offices, smart homes)            |
| **Generation**      | Earlier Wi-Fi standards (802.11n)                                      | More recent Wi-Fi standards (802.11ac, 802.11ax/Wi-Fi 6)                    |
| **Analogy**         | Multiple highway lanes for one vehicle                                 | Multiple vehicles traveling simultaneously on different lanes               |


## 10. What are PPDU, PLCP, and PMD in the PHY layer?


In wireless networking standards (like IEEE 802.11/Wi-Fi), the PHY layer is split into components to handle different aspects of physical transmission. These components were designed to separate the logical handling of data from the specific transmission technologies, making the standards more flexible and adaptable.

In the Physical Layer (PHY) of wireless networks, PPDU, PLCP, and PMD are important components that handle the transmission and reception of data.

**PPDU (Physical Protocol Data Unit)**

- This is the complete packet that's transmitted at the physical layer
- Contains all the necessary information for successful wireless transmission
- Includes both the PLCP header and the data payload
- Essentially what "goes over the air" in a wireless transmission

**PLCP (Physical Layer Convergence Protocol)**

- Acts as an adaptation layer between the MAC layer and the physical medium
- Prepares MAC frames for transmission over the physical medium
- Adds preamble and header information to the data
- The PLCP header contains information about data rate, length, and other transmission parameters
- Helps synchronize the receiver with the transmitter

**PMD (Physical Medium Dependent)**

- The component that directly interfaces with the transmission medium
- Handles the actual modulation/demodulation of signals
- Responsible for transmitting and receiving the raw bits over the air
- Deals with specific RF characteristics like frequency, power levels, and signal encoding
- Varies depending on the specific wireless technology (e.g., different for 802.11a/b/g/n/ac)

These components work together in a hierarchical structure: the PLCP prepares data for transmission, the PMD handles the physical transmission, and the PPDU is the complete packet format that goes over the air.


## 11. What are the types of PPDU? Explain the PPDU frame format across different Wi-Fi generations.

Physical Protocol Data Unit (PPDU) is the complete physical layer packet transmitted over the wireless medium in Wi-Fi communications. 

IEEE® 802.11™ is a packet-based protocol. Each physical layer protocol data unit (PPDU) contains preamble and data fields. The preamble field contains the transmission vector format information. The data field contains the user payload and higher layer headers, such as medium access control (MAC) fields and cyclic redundancy check (CRC).

The PPDU structure has evolved significantly across different Wi-Fi generations to support higher data rates, improved spectral efficiency, and new features.

| Wi-Fi Generation | IEEE Standard         | PPDU Format Types                         | Key Features and Improvements                                                                                                                                                                                                                                                                                                                                                                               |
| ---------------- | --------------------- | ----------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Wi-Fi 1**      | 802.11 (1997)         | DSSS PPDU                                 | - Simple format- 1-2 Mbps data rates- DBPSK/DQPSK modulation<br><br>- Basic Direct Sequence Spread Spectrum (DSSS) for reliable communication<br>                                                                                                                                                                                                                                                           |
| **Wi-Fi 2**      | 802.11b (1999)        | HR/DSSS PPDU                              | - Enhanced DSSS format<br><br>- Up to 11 Mbps- CCK modulation for higher data rates<br><br>- Improved spectral efficiency compared to Wi-Fi 1                                                                                                                                                                                                                                                               |
| **Wi-Fi 3**      | 802.11a/g (1999/2003) | OFDM PPDU                                 | - First implementation of Orthogonal Frequency Division Multiplexing (OFDM)<br><br>- Up to 54 Mbps<br><br>- Uses multiple subcarriers for better bandwidth utilization-<br><br>- Supports BPSK to 64-QAM for flexible data rates                                                                                                                                                                            |
| **Wi-Fi 4**      | 802.11n (2009)        | HT PPDU:- Legacy- HT-Mixed- HT-Greenfield | - Introduced MIMO (up to 4 spatial streams)<br><br>- Supports wider channels (20/40 MHz)<br><br>- Frame aggregation for reduced overhead<br><br>- Short Guard Interval for faster transmissions<br><br>- Up to 600 Mbps, significantly improving throughput over Wi-Fi 3                                                                                                                                    |
| **Wi-Fi 5**      | 802.11ac (2013)       | VHT PPDU                                  | - Operates exclusively in the 5 GHz band<br><br>- MU-MIMO support for simultaneous multi-user communication<br><br>- Wider channels (20/40/80/160 MHz)<br><br>- Higher modulation order (256-QAM)<br><br>- Up to 8 spatial streams, achieving up to 6.9 Gbps speeds<br><br>- Enhanced efficiency for high-bandwidth applications like streaming and gaming                                                  |
| **Wi-Fi 6**      | 802.11ax (2019)       | HE PPDU:- HE SU- HE MU- HE ER SU- HE TB   | - Introduced OFDMA for multi-user support in both uplink and downlink<br><br>- Higher modulation order (1024-QAM)- BSS coloring to reduce co-channel interference<br><br>- Target Wake Time for power efficiency in IoT devices<br><br>- Longer OFDM symbols for better reliability in dense environments<br><br>- Up to 9.6 Gbps, improving capacity and efficiency over Wi-Fi 5                           |
| **Wi-Fi 6E**     | 802.11ax-2021         | Same as Wi-Fi 6                           | - Extended operation into the 6 GHz band<br><br>- More available channels for reduced congestion<br><br>- Same features as Wi-Fi 6 but with expanded spectrum access for higher performance in crowded areas                                                                                                                                                                                                |
| **Wi-Fi 7**      | 802.11be (2024)       | EHT PPDU:- EHT MU- EHT TB                 | - Supports extremely wide channels (up to 320 MHz)<br><br>- Higher modulation order (4096-QAM)<br><br>- Multi-link operation for simultaneous use of multiple bands<br><br>- Multi-RU allocation for efficient resource use<br><br>- Preamble puncturing to utilize fragmented spectrum efficiently<br><br>- Speeds up to 46 Gbps, revolutionizing high-throughput applications like AR/VR and cloud gaming |


## 12. How is the data rate calculated?

In order to calculate the the data rate we will be needing the following parameters:

- Nsd    : Number of data sub-carriers
- Nbpscs : Number of coded bits per sub-carrier per stream
- R      : Rate of Coding
- Nss    : Number of spatial stream
- Tdft   : OFDM symbol duration
- Tgi    : Guard Interval duration

Therefore,
 `Data rate = (Nsd X Nbpscs X R X Nss)/(Tdft + Tgi)`

This is the rate of bits transmitted per OFDM symbol.

---
