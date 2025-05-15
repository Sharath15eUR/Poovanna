# Questions

1. Write a C program to define 3 different threads with the following purposes where N is the input
   - Thread A - To run a loop and return the sum of first N prime numbers
   - Thread B & C - should run in parallel. One prints "Thread 1 running" every 2 seconds, and the other prints "Thread 2 running" every 3 seconds for 100 seconds.

2. In the above program,
   - add signal handling for SIGINT (etc) and prevent termination.
   - Convert the above threads to individual functions and note down the time taken and the flow of execution.

# Topics

## 1. Child process - fork()
- When a process calls the fork function, it creates a child process which receives same memory space as that of the parent's including the data, memory stack and heap.
- As a return value, the parent receives the PID of the child, and the child gets 0, and if -1 is returned it means fork has failed.
	
## 2. Handing common signals
- signals are system interrupts which are sent to notify a specific events.
- Some common signals include:
	- SIGINT: this is sent when the user presses Ctrl+c in order to terminate a program
	- SIGTERM: this is the standard signals which requests for process termination
	- SIGKILL: forces immediates process termination which cannot be caught of killed
	- SIGSEGV: this is sent when a processes accesses invalid memory or when there is a segmentation fault
	- SIGUP: is sent if termnial disconnects or to trigger config reloads
	- SIGUSR1/SIGUSR2: these are custom signals

We can handle these signals using the signal() function.
Ex: using `signal(SIGINT, SIG_IGN)` will ignore signal termination request from the user
Also we can use our custom function it order to process when there is such a request

```C
#include <stdio.h>
#include <signal.h>

void signal_handler(int signum){
	if(signum==SIGINT){
		printf(" CTRL+C has been presses");
		exit(0);
	}
}
int main(){
	signal(SIGINT, singal_handler);
	return 0;
}
```

## 3. Exploring different Kernel crashes
1. Kernel Panic (Linux/macOS)
	- This is when the Linux or macOS kernel encounters an error it cannot recover from. The system halts and displays error information.

2. Blue Screen of Death (Windows)
	- Microsoft Windows displays a blue screen with error codes when the kernel encounters a critical error. In modern Windows, this includes a QR code and error information.

3. Kernel Protection Fault
	- Occurs when the kernel attempts to access protected memory regions or violates memory protection mechanisms.

4. Deadlock Situations
	- When kernel threads lock resources in a circular dependency, preventing any thread from proceeding.
	
## 4. Time complexity
This is basically a commutationals measurement of an algorithm to check how its runtime will scale with input size.
	
## 5. Blocking mechanism - mutex/spinlock
A mutex is a synchronization primitive that allows only one thread to access a resource at a time.
	- If a thread attempts to lock an already locked mutex, it's typically put to sleep until the mutex becomes available
	- A mutex has an owner (the thread that locked it)
	- Only the owner can unlock the mutex
	- Best used for operations that might take some time to complete

A spinlock is a lock where the waiting thread continuously checks if the lock is available, "spinning" in a loop rather than sleeping.
	- Waiting threads consume CPU cycles while waiting (active waiting)
	- No context switch overhead when waiting
	- Best used for protecting very short critical sections
	- More efficient than mutexes when wait times are expected to be very brief
	- Can lead to CPU waste if contention is high or wait times are long

Trade-offs between mutex and spinlock:
	- Mutexes are better when the expected wait time might be long
	- Spinlocks are better when the critical section is very short and contention is low
	- Spinlocks generally perform better on multiprocessor systems
	- Spinlocks should never be held while sleeping or performing I/O operations
