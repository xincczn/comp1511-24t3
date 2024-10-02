// Xing He, z5413977, 21/06/24
// Part 1.1: Copy Array (Your Turn!)

#include <stdio.h>

#define OLD_LENGTH 3
#define NEW_LENGTH 10

int main(void) {

    // Create an array of doubles with 3 elements, each with a non-zero value.
    double old_array[OLD_LENGTH] = { 1.2, 2.4, 3.6 };

    // Create another array of doubles with 10 elements where every element initialised to 0.0.
    double new_array[NEW_LENGTH] = { 0.0 };

    // Create a while loop that loops through every element of the first array.
    int i = 0;
    while (i < OLD_LENGTH) {
        // Copy the elements of the first array into the second array (leave 0's at the end)
        new_array[i] = old_array[i];

        i++;
    }

    // Create a while loop that prints out all the elements of the second array.
    int j = 0;
    while (j < NEW_LENGTH) {
        // %.Xlf where X is how many decimal places you want to format the double value
        printf("%.2lf ", new_array[j]);

        j++;
    }

    return 0;
}