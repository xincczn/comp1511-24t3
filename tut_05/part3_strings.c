// Xing He, z5413977, 11/10/24
// Part 3: String Warmup

#include <stdio.h>

#define MAX_SIZE 1024

int main(void) {
    // Declare and initialise a string
    char my_string[] = "Hello world!";
    
    // Traverse the string and print each character
    int i = 0;
    while (my_string[i] != '\0') {
        printf("%c", my_string[i]);
        i++;
    }
    printf("\n");

    // Another way to traverse the string and print each character 
    for (int i = 0; my_string[i] != '\0'; i++) {
        printf("%c", my_string[i]);
    }

    // How to print a string in its entirety
    printf("My string: %s\n", my_string);

    // Declare a string
    char another_string[MAX_SIZE];
    
    // Read a string from the user, note we DO NOT use scanf for strings
    printf("Enter a string: ");
    fgets(another_string, MAX_SIZE, stdin);
    
    // Print the string using fputs
    fputs(another_string, stdout);

    return 0;
}
