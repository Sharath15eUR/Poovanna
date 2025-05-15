#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>

int N;
int prime_sum = 0;

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

void* thread_a_function(void* arg) {
    clock_t start = clock();

    printf("Thread A started: Calculating sum of first %d prime numbers\n", N);
    
    int count = 0;
    int num = 2;
    prime_sum = 0;
    
    while (count < N) {
        if (is_prime(num)) {
            prime_sum += num;
            count++;
        }
        num++;
    }
    
    printf("Thread A finished: Sum of first %d primes = %d\n", N, prime_sum);

    clock_t end = clock();
    printf("Thread A function start time: %ld",start);
    printf("\nThread A function stop time: %ld\n",end);
    return NULL;

}

void* thread_b_function(void* arg) {

    printf("Thread 1 started: Will print message every 2 seconds for 100 seconds\n");
    
    time_t start_time = time(NULL);
    time_t current_time;

    while (1) {
        clock_t start = clock();
        current_time = time(NULL);
        if (current_time - start_time >= 100) {
            break; 
        }
    
        clock_t end = clock();
        printf("\nThread 1 running");
        printf("\nThread 1 function start time: %ld",start);
        printf("\nThread 1 function stop time: %ld\n",end);
         sleep(2);
    }
    
    printf("Thread 1 finished\n");
    return NULL;
}

void* thread_c_function(void* arg) {

    printf("\nThread 2 started: Will print message every 3 seconds for 100 seconds\n");
    
    time_t current_time;
    
    while (1) {
        time_t start_time = time(NULL);
        clock_t start = clock();
        current_time = time(NULL);
        if (current_time - start_time >= 100) {
            break; 
        }
        
        clock_t end = clock();
        printf("\nThread 2 running");
        printf("\nThread 2 function start time: %ld",start);
        printf("\nThread 2 function stop time: %ld\n",end);
        sleep(3); 
    }

    printf("Thread 2 finished\n");    
    return NULL;
}



int main() {

    signal(SIGINT, SIG_IGN);

    printf("Enter value of N: ");
    scanf("%d", &N);
    
    pthread_t thread_a, thread_b, thread_c;
    pthread_create(&thread_a, NULL, thread_a_function, NULL);
    pthread_join(thread_a, NULL);
    
    printf("\nStarting Threads B and C in parallel...\n\n");
    pthread_create(&thread_b, NULL, thread_b_function, NULL);
    pthread_create(&thread_c, NULL, thread_c_function, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);
    
    printf("\nAll threads are executed.\n");
    return 0;
}