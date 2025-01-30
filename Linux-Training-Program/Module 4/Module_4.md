#### ***SCENARIO***

**For the attached file, write a bash script which should take the file as input and have to go through it line by line and need to generate an output file (say output.txt) with listings
of following parameters fetched from the input file.**

**Params expected to be fetched from input.txt file : "frame.time", "wlan.fc.type", "wlan.fc.subtype"**

**Sample output expected in output.txt:**

**"frame.time": "Nov 14, 2024 11:44:48.219200000 India Standard Time",**
**"wlan.fc.type": "1",**
**"wlan.fc.subtype": "9"**
**"frame.time": "Nov 14, 2024 11:44:48.219208000 India Standard Time",**
**"wlan.fc.type": "0",**
**"wlan.fc.subtype": "1",**

**and so on.**


---

#### ***SCRIPT***

```
#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "ERROR: Insufficient arguments."
    echo "Usage: $0 <input_file> <output_file>"
    exit 1
fi

input_file="$1"
output_file="$2"

# will clear output_file if it already exists
> "$output_file"


while read -r line; do
    if [[ "$line" =~ ^\"frame\.time\" ]]; then
        frame_time="$line"
    elif [[ "$line" =~ ^\"wlan\.fc\.type\" ]]; then
        wlan_fc_type="$line"
    elif [[ "$line" =~ ^\"wlan\.fc\.subtype\" ]]; then
        wlan_fc_subtype="$line"
        
        echo "$frame_time" >> "$output_file"
        echo "$wlan_fc_type" >> "$output_file"
        echo "$wlan_fc_subtype" >> "$output_file"
        echo "" >> "$output_file" 
    fi
done < "$input_file"  

echo "Successfully completed. Output saved in $output_file"


```

---

#### ***OUTPUT***

![](../../images/Pasted%20image%2020250131000925.webp)

---
