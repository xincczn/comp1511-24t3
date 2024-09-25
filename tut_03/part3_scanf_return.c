// Xing He, z5413977, 27/09/24
// Part 3: What Scanf returns

#include <stdio.h>

int main(void) {
    // Scanf returns an integer, this integer is based on how many values (input) 
    // it was able to scan in successfully that match the required string

    // Note: You might notice that the provided scanf string is in the form `" %d"`
    // The space at the front allows the scanf to ignore newlines, spaces and tabs characters
    // This becomes an issue for example, if you are trying to scan in characters,
    // as the user presses the enter key, it will be picked up by the scanf 

    /*
        Note that the code here is written in one line, but can be expressed as:

        int i = 0;
        int result = scanf(" %d", &i);
        printf("Result of scanf: %d\n", result);
    */

    int i = 0;
    printf("Result of scanf: %d\n", scanf(" %d", &i));


    int j = 0;
    printf("Result of scanf: %d\n", scanf(" %d %d", &i, &j));

    int k = 0;
    printf("Result of scanf: %d\n", scanf(" %d %d %d", &i, &j, &k));

    // Here we have three scanf executing, expecting different number of integer inputs
    // As each successfully executes, we see that the value returned by scanf is equal to the number
    // of values scanned in by that given statement

    // If we attempt to Ctrl-D early, scanf that fail to scan in anything will return -1
    // And if we scan in a non-integer (like a char) and nothing else, it will return 0

    // This means that the integer value returned is based on how many successful values it scanned in

    return 0;
}