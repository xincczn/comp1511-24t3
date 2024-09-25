// Xing He, z5413977, 27/09/24
// Part 1.1: Various Loops (Your Turn!)

#include <stdio.h>

/*
    Loops allow us to execute a particular block of code x times allowing us
    to introduce conditional repetition while also reducing code repetition.

    The following procedures a, b, c will showcase many different ways of
    how loops repeat themselves.
*/

// This loops prints out numbers 0, 2, 4, 6, ..., 26, 28, 30.
void a(void) {
    int i = 0;  // The counter is initialsied as 0
    while (i < 32) {  // Stops when the counter is 32 or more
        printf("%d\n", i);
        i = i + 2;  // The counter steps by incrementing by 2
    }
}

// This loop prints out numbers 5, 4, 3, 2, 1, 0.
void b(void) {
    int i = 5;  // The counter is initialised as 5
    while (i >= 0) {  // Stops when the counter is less than 0
        printf("%d\n", i);
        i--;  // The counter steps by decrementing by 1
    }
}

// This loop prints out the number 5.
int c(void) {
    int i = 0; 
    int keep_going = 1;  // The sentinel (flag) is intiialised as 1 (True)
    while (keep_going == 1) {  // Stops when the sentinel is 0 (False)
        if (i > 3) {
            keep_going = 0;  // The sentinel switches to 0 (False)
        }
        i++;
    }
    printf("%d\n", i);
	return 0;
}

/*
    Unlike if statements and other code structures that we have came across so far,
    while loops have a more complex syntax structure and writing them improperly
    can lead to issues.

    The following procedures d, e, f will showcase many different ways of
    how loops fail to perform as intended.
*/

// This loop will not compile as the counter isn't initialised.
void d(void) {
    // int i;  // Not initialised
    // while (i > 0) {
    //     printf("%d\n", i);
    //     i--;
    // }
}

// This loop will execute infinitely as the counter is not stepping towards the condition.
void e(void) {
    int i = 0;
    int max = 32;
    while (i < max) {
        printf("%d\n", i);
        max = max + 2;
    }

}

// This loop will not execute because the sentinel value (flag) is set to 0 (false).
// The condition is never true as a result.
void f(void) {
    int i = 0;
    int keep_going = 0;
    while (keep_going == 1) {
        if (i > 3) {
            keep_going = 0;
        }
        i++;
    }
    printf("%d\n", i);
}

// Uncomment to run specific loop.
int main(void) {

    // a();
    // b();
    // c();
    // d();
    // e();
    // f();

    return 0;
}

