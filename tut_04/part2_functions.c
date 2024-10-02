// Xing He, z5413977, 21/06/24
// Part 2: Function Practice

#include <stdio.h>

/*
    Function Protoype (Declaring that the function exists)
    Syntax: <return_type> <function_name>(parameters ...);
 */
int add(int number1, int number2);

int main(void) {
    int result;
    int num1 = 5;
    int num2 = 3;

    // Function call (using function and passing required values)
    // Syntax: <function_name>(arguments ...);
    result = add(num1, num2);

    printf("Result: %d\n", result);
    
    return 0;
}

// Function definition
/*
    Function Definition (Defining what the function does)
    Syntax: 
        <return_type> <function_name>(parameters ...) {
            ...
        }
 */
int add(int number1, int number2) {
    // Function body
    int sum = number1 + number2;

    // Return statement (if return type isn't void)
    return sum;
}