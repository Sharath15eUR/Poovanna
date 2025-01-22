> **NAME: POOVANNA K B**

---


**1.  Create a file and add executable permission to all users (user, group and others)** 
```
$ touch filename
$ chmod a+x filename
```

---

**2. Create a file and remove write permission for group user alone.**
```
$ touch filename
$ chmod g-w filename
```
 
---

**3. Create a file and add a softlink to the file in different directory (Eg : Create a file in dir1/dir2/file and create a softlink for file inside dir1)**
```
$ mkdir -p dir1/dir2
$ touch ./dir1/dir2/filename
$ ln -s ./dir1/dir2/filename ./dir1/softlink
```

---

**4. Use ps command with options to display all active process running on the system**
```
$ ps aux
```

---

**5. Create 3 files in a dir1 and re-direct the output of list command with sorted by timestamp of the files to a file**
```

$ mkdir dir1
$ cd dir1
$ touch file1 file2 file3
$ cd ..
$ ls -lt dir1 > sortedFileName.txt
```

![[sortedFileName.webp|563]]

---






