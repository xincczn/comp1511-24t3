// Xing, z5413977, 20/09/24
// Part 3: Weird Data Types and Arithmetic

#include <stdio.h>

int main(void) {

    /*
        When doing calculations, the results can 
        differ based on the provided types of values.

        int    + int    -> int
        double + double -> double
        double + int    -> double
    */

    int answer_1 = 7 / 2;
    printf("Sensible answer: 3.5\n");
    printf("C answer: %d\n", answer_1);


    double answer_2 = (3.0 / 2) + 1;
    printf("Sensible answer: 2.5\n");
    printf("C answer: %lf\n", answer_2);

    // Bonus question
    double answer_2_1 = (3 / 2) + 1.0;
    printf("Sensible answer: 2.5\n");
    printf("C answer: %lf\n", answer_2_1);

    char answer_3 = 'a' + 5;
    printf("Sensible answer: (a + 5) / (a = -5)\n");
    printf("C answer: %c\n", answer_3);
    printf("Reason: %d\n", answer_3);
    // char have numerical representation which is used here
    // C: 97 + 5 == 102

    char answer_4 = 'F' - 'A' + 'a';
    printf("Sensible answer: Error\n");
    printf("C answer: %c\n", answer_4);
    printf("Reason: %d\n", answer_4);
    // 'A' - 'a' is 32, which is the exact offset between uppercase and lowercase
    // letters, hence why adding 32 to 'F' turn it into 'f'
    // C: 102 => 'f'

    return 0;
}