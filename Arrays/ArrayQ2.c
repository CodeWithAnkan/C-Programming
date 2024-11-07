#include <stdlib.h>

int** make2DArray(int rows, int cols) {
    int **x;
    int i;

    // Allocate memory for row pointers
    x = (int**)malloc(rows * sizeof(int*));

    // Check if memory allocation was successful
    if (x == NULL) {
        return NULL; // Memory allocation failed
    }

    // Allocate memory for each row
    for (i = 0; i < rows; i++) {
        x[i] = (int*)malloc(cols * sizeof(int));
        
        // Check if memory allocation was successful
        if (x[i] == NULL) {
            // Free previously allocated memory if allocation fails
            for (int j = 0; j < i; j++) {
                free(x[j]);
            }
            free(x);
            return NULL;
        }
    }
    
    return x;
}
