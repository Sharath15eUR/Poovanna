#!/bin/bash

ERROR_LOG="errors.log"

if [[ $# -eq 0 ]]; then
    echo "Error: No arguments provided. Use '$0 --help' for usage details." | tee -a "$ERROR_LOG"
    exit 1
fi

#------------------------------------------------------------------------------------

# 1. Recursive function which is able to search of a keyword inside files in a nested directory
search_directory() {
    local dir="$1"
    local keyword="$2"
    
    if [[ ! -d "$dir" ]]; then
        echo "ERROR: Directory '$dir' not found." | tee -a "$ERROR_LOG"
        return 1
    fi
    
    for file in "$dir"/*; do
        if [[ -d "$file" ]]; then
            search_directory "$file" "$keyword"  # Recursive call
        elif [[ -f "$file" ]]; then
            grep -Hn "$keyword" "$file" | tee -a "$ERROR_LOG"		
        fi
    done
}

#------------------------------------------------------------------------------------

# 2. Function to display help menu using a here document
show_help() {
    cat <<EOF
Usage: $0 [OPTIONS]

Options:
  -d <directory>   Search for a keyword recursively in a directory.
  -k <keyword>     Keyword to search for.
  -f <file>        Search for a keyword in a specific file.
  --help           Display this help menu.

Examples:
  $0 -d logs -k error
  $0 -f script.sh -k TODO
  $0 --help
EOF
}

#------------------------------------------------------------------------------------

# 3. Function to search for a keyword in a file using a here string
search_file() {
    local file="$1"
    local keyword="$2"
    
    if [[ ! -f "$file" ]]; then
        echo "Error: File '$file' not found." | tee -a "$ERROR_LOG"
        return 1
    fi
    
    grep -Hn "$keyword" "$file" <<< "$(cat "$file")" | tee -a "$ERROR_LOG"
}


#------------------------------------------------------------------------------------

while getopts ":d:k:f:-:" opt; do
    case "$opt" in
        d) directory="$OPTARG" ;;
        k) keyword="$OPTARG" ;;
        f) file="$OPTARG" ;;
        -) case "$OPTARG" in
               help) show_help; exit 0 ;;
               *) echo "Invalid option --$OPTARG" | tee -a "$ERROR_LOG"; exit 1 ;;
           esac ;;
        ?) echo "Invalid option: -$OPTARG" | tee -a "$ERROR_LOG"; exit 1 ;;
    esac
done


#------------------------------------------------------------------------------------

# Validate inputs
if [[ -z "$keyword" ]]; then
    echo "Error: Keyword must not be empty." | tee -a "$ERROR_LOG"
    exit 1
fi

if [[ -n "$file" && -n "$directory" ]]; then
    echo "Error: Please specify either a file (-f) or a directory (-d), not both." | tee -a "$ERROR_LOG"
    exit 1
fi

#------------------------------------------------------------------------------------

# Execute appropriate search
if [[ -n "$directory" ]]; then
    search_directory "$directory" "$keyword"
elif [[ -n "$file" ]]; then
    search_file "$file" "$keyword"
else
    echo "Error: Either a directory (-d) or a file (-f) must be specified." | tee -a "$ERROR_LOG"
    exit 1
fi

