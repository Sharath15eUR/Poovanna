

### ***Scenario***: 

>**Automating file backup and Reporting to the system. Create a shell script called "backup_manager.sh" that performs the following tasks incorporating the concepts suggested.**

---

### ***Requirements:***

1. **Command-line Arguments and Quoting**: The script must accept three arguments: 
- Source directory: A directory containing files to back up. 
- Backup directory: The destination where files will be backed up. 
- File extension: A specific file extension to filter (e.g., .txt).
	Example: ./backup_manager.sh "/home/user/source" "/backup" ".txt"

2. **Globbing**:
- The script should use globbing to find all files in the source directory matching the provided file extension.

3. **Export Statements:**
- Use export to set an environment variable BACKUP_COUNT, which tracks the total number of files backed up during the script execution.

4. **Array Operations:**
- Store the list of files to be backed up in an array.
- Print the names of these files along with their sizes before performing the backup.

5. **Conditional Execution:**
- If the backup directory does not exist, create it. If creation fails, exit with an error.
- If the source directory is empty or contains no files matching the extension, exit with a message.
- If a file already exists in the backup directory with the same name, only overwrite it if it is older than the source file (compare timestamps).

6. **Output Report:**
After the backup, generate a summary report displaying:
- Total files processed.
- Total size of files backed up.
- The path to the backup directory.
- The report should be saved in the backup directory as backup_report.log.

---

### ***Script***:

- Create backup_manager.sh script file and make it executable
```
$ touch backup_manager.sh
$ chmod +x backup_manager.sh
```

```
#!/bin/bash

# 1. Command Lined Arguments and Quoting
# ERROR1: if all arguments are not given 
if [ "$#" -ne 3 ]; then
	echo "ERROR: Missing arguments"
       	echo "RUN: $0 <source_directory> <backup_directory> <file_extension>"
	exit 1
fi

# Command-line arguments
SOURCE_DIR=$1
BACKUP_DIR=$2
FILE_EXT=$3

# ERROR2: if Source Directory provided by the user does not exist
if [ ! -d "$SOURCE_DIR" ]; then
    echo "ERROR: Source directory '$SOURCE_DIR' doesn't exist."
    exit 1
fi

# CONDITION1: If BACKUP_DIR doesn't exist create a new directory. 
if [ ! -d "$BACKUP_DIR" ]; then
    mkdir -p "$BACKUP_DIR"
    if [ $? -ne 0 ]; then
        echo "ERROR: Failed to create backup directory '$BACKUP_DIR'."
        exit 1
    fi
fi

# 2. Globbing: Find files with matching extensions
FILES=("$SOURCE_DIR"/*"$FILE_EXT")

# Check if files matching the extension exist
if [ "${#FILES[@]}" -eq 0 ] || [ ! -e "${FILES[0]}" ]; then
    echo "No files with extension '$FILE_EXT' found in '$SOURCE_DIR'."
    exit 0
fi

# 3. Export statment for backup count
export BACKUP_COUNT=0

# 4. ARRAY OPERATION: Store the list of backed files, and print name+size
TOTAL_SIZE=0
echo "Files to be backed up:"
for FILE in "${FILES[@]}"; do
    if [ -f "$FILE" ]; then
        FILE_NAME=$(basename "$FILE")
        FILE_SIZE=$(stat -c%s "$FILE")
        echo "  - $FILE_NAME (Size: $FILE_SIZE bytes)"
        
        # Check if the file already exists in the backup directory
        if [ -e "$BACKUP_DIR/$FILE_NAME" ]; then
            # Overwrite file if it is older than the source file using timestamps, by using -nt or newerthan option
            if [ "$FILE" -nt "$BACKUP_DIR/$FILE_NAME" ]; then
                cp "$FILE" "$BACKUP_DIR"
                ((BACKUP_COUNT++))
                ((TOTAL_SIZE+=FILE_SIZE))
            fi
        else
            # Copy file if it doesn't already exist
            cp "$FILE" "$BACKUP_DIR"
            ((BACKUP_COUNT++))
            ((TOTAL_SIZE+=FILE_SIZE))
        fi
    fi
done



# 6. Generate Output Report
REPORT_FILE="$BACKUP_DIR/backup_report.log"
echo "Backup Summary Report" > "$REPORT_FILE"
echo "----------------------" >> "$REPORT_FILE"
echo "Total files processed: $BACKUP_COUNT" >> "$REPORT_FILE"
echo "Total size of files backed up: $TOTAL_SIZE bytes" >> "$REPORT_FILE"
echo "Backup directory path: $BACKUP_DIR" >> "$REPORT_FILE"
echo "Summary report path: $REPORT_FILE"
echo
echo "Backup completed successfully..!"


```

---

### ***Output***
![](../../images/Pasted%20image%2020250128220911.webp)

---


