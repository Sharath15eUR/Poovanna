#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int rows, int cols, int key) {

    if (matrix == NULL || rows <= 0 || cols <= 0) {
        return false;
    }

    int row = 0;
    int col = cols - 1;
    
    while (row < rows && col >= 0) {
        if (matrix[row][col] == key) {
            return true; 
        } else if (matrix[row][col] > key) {
            col--;
        } else {
            row++;
        }
    }
    
    return false;
}


int main() {

    int matrix[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    
    int* matrixPtrs[4];
    for (int i = 0; i < 4; i++) {
        matrixPtrs[i] = matrix[i];
    }

    int key = 0;
    printf("\nEnter key to find: ");
    scanf("%d",&key);

    bool found = searchMatrix((int**)matrixPtrs, 4, 4, key);
    printf("Key %d: %s\n", key, found ? "Found" : "Not found");
    
    return 0;
}