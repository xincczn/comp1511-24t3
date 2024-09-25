// Xing He, z5413977, 27/09/24
// Part 2.1: Drawing Boxes (Your Turn!)

#include <stdio.h>

// When possible we want to replace raw values with #define constants 
// This constant is used in our loop conditions
#define SIZE 4

/*
    We can place a loop inside another loop to allow us to form a nested loop
    Nested loops work with an inner loop executing a block of code x times, 
    and an outer loop executing the inner loops y times.
    Nested loops tend to be used to work on 2D problems.

    The following procedures a, b, c, d will showcase many different ways of
    how 2d loops work.

    The approach to printing out these boxes requires labelling each X or O
    with its coordinates. Then by referring to the pattern exhibited, we can
    design an if statement which can decide when a X or O is printed.ßß
*/

/*
    This 2d loops prints out
        OXXX
        XOXX
        XXOX
        XXXO
*/
void a(void) {
    // Outer loop
    int row = 0;
    while (row < SIZE) {  // Executing SIZE times

        // Inner loop
        int col = 0;
        while (col < SIZE) {  // Executing SIZE times
            // Block of code execution like a 4x4 square
            // Both counters are being compared to determine the flow
            if (row == col) {
                printf("O");
            } else {
                printf("X");

            }
            col++;
        }


        row++;
        printf("\n");
    }
}

/*
    This 2d loops prints out
        OXOX
        OXOX
        OXOX
        OXOX
*/
void b(void) {
    // Outer loop
    int row = 0;
    while (row < SIZE) {  // Executing SIZE times

        // Inner loop
        int col = 0;
        while (col < SIZE) {  // Executing SIZE times
            // Block of code execution like a 4x4 square
            // The inner counter is being compared to determine the flow
            if (col % 2 == 0) {
                printf("O");
            } else {
                printf("X");

            }
            col++;
        }

        row++;
        printf("\n");
    }
}

/*
    This 2d loops prints out
        OXOO
        XXXX
        OXOO
        OXOO
*/
void c(void) {
    // Outer loop
    int row = 0;
    while (row < SIZE) {  // Executing SIZE times

        // Inner loop
        int col = 0;
        while (col < SIZE) {  // Executing SIZE times
            // Block of code execution like a 4x4 square
            // Both counters are being compared to determine the flow
            if (col != 1 && row != 1) {
                printf("O");
            } else {
                printf("X");

            }
            col++;
        }

        row++;
        printf("\n");
    }
}

/*
    This 2d loops prints out
        XXXX
        XOOX
        XOOX
        XXXX
*/
void d(void) {
    // Outer loop
    int row = 0;
    while (row < SIZE) {  // Executing SIZE times
        printf("X");

        // Inner loop
        int col = 1;
        while (col < 3) {  // Executing twice
            // Block of code execution like a 4x2 rectangle
            // Both counters are being compared to determine the flow
            if (row == 0 || row == 3) {
                printf("X");
            } else {
                printf("O");
            }
            col++;
        }

        printf("X");
        row++;
        printf("\n");
    }
}

// Uncomment to run specific loop.

int main(void) {

    // a();
    // b();
    // c();
    // d();

    return 0;
}