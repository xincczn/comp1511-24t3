// Xing He, z5413977, 21/06/24
// Part 1: Arrays Practice

#include <stdio.h>

// Declared a constant for the size of our arrays
#define SIZE 5

int main(void) {
    // Array declaration syntax
    // <type> <array_name>[<length>];
    int array[SIZE] = { 1, 2, 3, 4, 5 };
    
    int i = 0;
    while (i < SIZE) {
        /*
            Access an element of array syntax
            <array_name>[<index>]

            [] operator allows us to index a particular element of the array
            Note: Array index starts at 0 and up to length of array minus one
            Example: The array below has index range: 0 <= i <= SIZE - 1
         */

        if (array[i] % 2 == 1) {
            array[i] += 1;
        }
    
        i++;
    }


    // Make sure that our counter `j` starts at 0 as mentioned above
    // We use different counter name since `i` has been declared already
    int j = 0;
    while (j < SIZE) {
        printf("%d ", array[j]);
        j++;
    }

    printf("\n");

    return 0;
}