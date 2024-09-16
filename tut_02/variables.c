// Xing, z5413977, 20/09/24
// Part 1a: Variables

#include <stdio.h>

int main(void) {

    /*
        There are three main data types we can use in C.
        c syntax   (Type)      -> example value

        int        (Integer)   -> 3
        double     (Double)    -> 3.14
        char       (Character) -> 'a'

        Programming allows us to perform complex calculations.
        Variables allow us to store values of the above 
        types to help with this.

        There are three steps to using variables in C.
    */

    
    /*
        Step 1: Declaration

        <type> <variable_name>;    (replace anything in <>)

        First we need to declare them with a name of our choice, 
        alongside the type that the variable can hold.
        Once declared, that variable can only hold values
        matching that type.

        Note: Make sure to follow our style guide for name conventions. 
              - They should be descriptive and readable.
    */

    int number;
    double pi;
    char letter;

    // Do not uncomment these yet.
    // printf("number = %d\n", number);
    // printf("pi = %lf\n", pi);
    // printf("letter = %c\n", letter);

    /*
        Step 2: Initialisation

        <variable_name> = <value>;

        Variables can't be used unless it holds a value.
        If you uncomment any of the above three lines,
        the program will fail to compile as a result.

        Initialising variables is an important step, as
        it gives them an initial value.
    */

   number = 8;
   pi = 3.14;
   letter = 'a';

    printf("number = %d\n", number);
    printf("pi = %lf\n", pi);
    printf("letter = %c\n", letter);
    printf("\n");

    /*
        Step 3: Re-assignment

        <variable_name> = <new_value>;

        Variables are really powerful because we can
        update the value they hold.
        Check out some of the way we can reassign variables.
    */

    number = 10;
    pi = pi + pi;
    letter = 'b';

    printf("number = %d\n", number);
    printf("pi = %lf\n", pi);
    printf("letter = %c\n", letter);

    /*
        Bonus Step: Declaring and Initialising at the same time.

        <type> <variable_name> = <value>;

        We can declare and initialise variables in one line.
        Most of the time, we will choose to do this as
        the variables tend to have initial values.

        An example of when this isn't the case would be
        when we need to grab a value from user input.
    */

    int life = 42;

    int user_input;
    printf("What is your favourite number?: ");
    scanf(" %d", &user_input);

    printf("Your new favourite number: %d!\n", user_input + life);

    return 0;
}


