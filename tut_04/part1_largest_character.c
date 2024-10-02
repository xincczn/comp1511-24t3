// Xing He, z5413977, 21/06/24
// Part 1.2: Largest Character (Your turn!)

#include <stdio.h>

#define SIZE 8

int main(void) {
    // Create a character array with exactly 8 elements.
    char letters[SIZE] = { 'C', 'o', 'm', 'p', '1', '5', '1', '1' };

    // Create a character variable called largest_character, equal to the first character of the array.
    // Note: Becareful of accessing with an invalid index
    //       Here 0 is safe, since the length is 8 
    char largest_character = letters[0];

    // Create a while loop to loop through the character array.
    int i = 0; 
    while (i < SIZE) {
        // Create an if statement to check if the current character has a higher ascii value than "largest_character"
        if (letters[i] > largest_character) {
            largest_character = letters[i];
        }

        i++;
    }

    // Print out the largest character you've found.
    printf("Largest character: %c\n", largest_character);

    return 0;
}