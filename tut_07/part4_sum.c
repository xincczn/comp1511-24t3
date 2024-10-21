// Xing He, z5413977, 25/10/24
// Part 4.1: Sum of Command Line Arguments (Your Turn!)

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int sum = 0;

    // Note that `i` starts at 1 as we skip the program name in the argv array
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }

    printf("Sum: %d\n", sum);

    return 0;
}
