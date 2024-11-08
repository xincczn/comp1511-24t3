// Xing He, z5413977, 08/11/24
// Part 1.1: Free malloc'd memory

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // Malloc'ing an integer
    int *ptr = malloc(sizeof(int));
    *ptr = 42;
    printf("Value: %d\n", *ptr);

    // Every malloc function call we make during the runtime of our program must be 
    // eventually matched by a free function call.
    
    // Compile and run via: dcc --leak-check free.c -o free
    
    // Uncomment the below line to prevent the error
    // free(ptr);

    return 0;
}
