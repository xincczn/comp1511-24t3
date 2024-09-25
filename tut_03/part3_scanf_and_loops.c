// Xing He, z5413977, 27/09/24
// Part 3.1: Scanf and Loops

#include <stdio.h>

// Enter a series of integers until you reach a negative number. 
// Then, stop and calculate the sum.
void a(void) {
    int num = 0;
    int sum = 0;

    printf("Please enter a number: ");
    scanf("%d", &num);

    while (num >= 0) {
        sum += num;
        printf("Please enter a number: ");
        scanf("%d", &num);
    }

    printf("Sum: %d\n", sum);
}

// Enter numbers until the user presses 'q'. 
// Then, display the count of numbers entered.
void b(void) {
    int count = 0;
    char character = 0;

    printf("Please enter a character: ");
    scanf("%c", &character);

    while (character != 'q') {
        count++;
        printf("Please enter a character: ");
        scanf(" %c", &character);
    }

    printf("Count: %d\n", count);
}

// Scan for numbers until end of input and display all even numbers entered.
void c(void) {
    int num = 0;

    printf("Please enter a number: ");
    while (scanf("%d", &num) == 1) {
        if (num % 2 == 0) {
            printf("%d\n", num);
        }
        printf("Please enter a number: ");
    }
}

// Scan for integers keeping a cumulative sum, 
// until the sum of entered integers reaches or 
// exceeds the target sum provided by the user.

// Print the final sum.
void d(void) {
    int num = 0;
    int sum = 0;
    int target = 0;

    printf("Please enter a target sum: ");
    scanf("%d", &target);

    printf("Please enter a number: ");
    scanf("%d", &num);
    sum += num;

    while (sum < target) {
        printf("Please enter a number: ");
        scanf("%d", &num);
        sum += num;
    }

    printf("Sum: %d\n", sum);
}

// Uncomment to run specific loop.
int main(void) {

    // a();
    // b();
    // c();
    // d();

    return 0;
}

