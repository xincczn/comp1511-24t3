// Xing He, z5413977, 27/09/24
// Part 2: 2D Loops

#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int main(void) {
    
    /* 
        Recall the three crucial components of a loop
        2D loops is simply a loop inside another loop

        Outer 1. declare and initialise the counter
        while (Outer 2. condition) {

            Inner 1. declare and initialise the counter
            while (Inner 2. condition) {
                ...

                Inner 3. moving the counter to a new value 
                (which eventually invalidates the condition)
            }

            Outer 3. moving the counter to a new value 
            (which eventually invalidates the condition)
        }
    */

    // Translation of the flowchart.

    printf("Start of outer loop!\n\n");

    int row = 0;
    while (row < MAX_ROW) {
        printf("Start of inner loop!\n");

        int col = 0;
        while (col < MAX_COL) {
            printf("%d ", col);
            col++;
        }

        printf("\nEnd of inner loop!\n\n");
        row++;
    }
    printf("End of outer loop!\n");

    return 0;
}
