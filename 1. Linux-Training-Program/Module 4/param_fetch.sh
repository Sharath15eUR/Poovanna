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

