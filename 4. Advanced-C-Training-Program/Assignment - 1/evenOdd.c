#include <stdio.h>
#include <stdlib.h>

void solve(int *arr, int size) {
    if (arr == NULL || size <= 1) {
        return;
    }

    int *temp = (int *)malloc(size * sizeof(int));
    
    int *original = arr;
    int *result = temp;
    int evenCount = 0;
    
    for (int i = 0; i < size; i++) {
        if (*original % 2 == 0) { 
            *result = *original;
            result++;
            evenCount++;
        }
        original++;
    }
    
    original = arr;
    for (int i = 0; i < size; i++) {
        if (*original % 2 != 0) {  
            *result = *original;
            result++;
        }
        original++;
    }
    
    original = arr;
    result = temp;
    for (int i = 0; i < size; i++) {
        *original = *result;
        original++;
        result++;
    }

    free(temp);
}

void printArray(int *arr, int size) {
    int *ptr = arr;
    for (int i = 0; i < size; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}

int main() {
    int arr1[] = {12, 34, 45, 9, 8, 90, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Before: ");
    printArray(arr1, size1);
    
    solve(arr1, size1);
    
    printf("After: ");
    printArray(arr1, size1);
    
    
    return 0;
}