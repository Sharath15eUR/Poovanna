1) Use the appropriate command to list all files larger than 1 MB in the current directory and save the output to a file.
	`$ find -maxdepth 1 -type f -size +1M > output.txt`
![](../images/Pasted%image%20250125113443.png)


---

2) Replace all occurrences of "localhost" with "127.0.0.1" in a configuration file named config.txt, and save the updated file as updated_config.txt.

	`$ sed 's/localhost/127.0.0.1/g' config.txt > updated_config.txt`

	![][Pasted%image%20250125113955.webp|371] ""]

	![[Pasted image 20250125114025.webp|475]]

	

---

3) Use the appropriate command to search for lines containing the word "ERROR" in a log file but exclude lines containing "DEBUG". Save the results to a file named
	filtered_log.txt.

	log:
	
	DEBUG: Starting the application initialization.
	ERROR: Unable to connect to the database.
	INFO: User 'admin' logged in successfully.
	DEBUG: Fetching configuration settings from the server.
	ERROR: DEBUG - Configuration settings could not be applied.
	INFO: Scheduled job 'backup' completed successfully.
	DEBUG: Connection to server timed out. Retrying...
	ERROR: Failed to fetch data from API endpoint '/users'.
	INFO: Maintenance mode activated.
	ERROR: DEBUG - Query execution failed due to a syntax error.
	DEBUG: Reloading application modules.
	ERROR: Missing required parameter in the request.
	INFO: Shutting down the system gracefully.
	DEBUG: Closing unused network connections.
	ERROR: DEBUG - Unexpected server response received.

	`$ grep "ERROR" log.txt | grep -v "DEBUG" > filtered_log.txt`

	![[Pasted image 20250125120453.webp]]

	![[Pasted image 20250125120514.webp]]


---

4) Write a code to identify the process with the highest memory usage and then terminate it.
	- Create a script and make it executable
	- Run the script

```
#!/bin/bash 

# To store process ID and name 
PROCESS_INFO=$(ps aux --sort=-%mem | awk 'NR==2 {print $2, $11}') 

# Initializing PID and process name 
PID=$(echo "$PROCESS_INFO" | awk '{print $1}') 
PROCESS_NAME=$(echo "$PROCESS_INFO" | awk '{print $2}') 

# Terminate the process with highest memory 
if [ -n "$PID" ]; 
then 
echo "Process found with highest memory usage!" 
echo "PID: $PID" echo "NAME: $PROCESS_NAME" 
echo "Terminating the mentioned process" 
kill -9 "$PID" 
else echo 
"Process not found." 
fi
```

![[Pasted image 20250125204946.webp]]


---

5) Use the networking tool command and print all the gateway available in a sorted manner

	- Create a script and make it executable
	- Run the script
	
	***Script***
	```
	#!/bin/bash
	netstat -rn | awk '/^0.0.0.0/ {print $2}' | sort -u
	```

	![[Pasted image 20250125203100.webp]]

***
