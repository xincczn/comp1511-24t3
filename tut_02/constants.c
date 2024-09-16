// Xing, z5413977, 20/09/24
// Part 1b: Constants

#include <stdio.h>

#define PI 3.141592

int main(void) {

    /*
        Now with variables under our toolbelt,
        lets do some crazy calculation.

        Lets learn how to calculate the area of a circle.
        
        The formula for the area is as follows:
        Area = pi x radius^2
    */

    int radius;

    // First, we will be initialising `radius` 
    // with a value from user input.

    printf("What is the radius of the circle: ");
    scanf(" %d", &radius);

    printf("Radius: %d\n", radius);

    // double pi = 3.141592;

    // Initially we might store the value of `pi` in a variable
    // like with the commented out code above.
    // But since that value is always constant, it is considered
    // a magic value/number.
    // These should be defined as constants instead.

    // Look above the main function to see how we
    // define constants

    double area = PI * radius * radius;

    // Note: `.2` is added to force the variable to be printed with
    //       two decimal places. 
    printf("Area: %.2lf\n", area);

    return 0;
}