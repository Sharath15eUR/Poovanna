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
            # Overwrite file if it is older than the source file using timestamps
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



