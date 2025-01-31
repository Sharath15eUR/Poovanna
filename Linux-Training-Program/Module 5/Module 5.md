
---

#### ***Problem Statement***

Create a Bash script 'file_analyzer.sh', to demonstrate the following concepts:
1. Recursive functions
- Write a recursive function to search for files in a directory and its subdirectories containing a specific keyword.
2. Redirection and error handling
- Log errors (e.g., invalid arguments, missing files) to 'errors.log' and display them in the terminal.
1. Here document and here string
- Use a here document to display a help menu when the '--help' option is passed.
- Search for a keyword in a specified file using a here string
2. Special parameters
	- Use parameters like '$0', '$#', '$?' and '$@' to provide meaningful feedback.
3. Regular expressions
- Validate inputs with regular expressions (Check if the file exists and the keyword is not empty and valid)
4. Command-line arguments using getopts
- Use 'getopts' to handle:
'-d <directory>': Directory to search.
'-k <keyword>': Keyword to search.
'-f <file>': File to search directly.
'--help': Display the help menu.

Example usage:
```
# Recursively search a directory for a keyword
./file_analyzer.sh -d logs -k error
# Search for a keyword in a file
./file_analyzer.sh -f script.sh -k TODO
# Display the help menu
./file_analyzer.sh --help
```

---

#### ***Script***

```
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
```


---


#### ***Output***

![](../../images/Pasted%20image%2020250131225538.webp "")

![](../../images/Pasted%20image%2020250131225605.webp)
