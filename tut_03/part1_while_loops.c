// Xing He, z5413977, 27/09/24
// Part 1: While Loops

#include <stdio.h>

int main(void) {
    // Translation of the flow chart example:
	printf("Start of loop!");

    int counter = 0;  // [1]
	while (counter < 10) {  // [2]
		printf("%d\n", counter);
		counter++;  // [3]
	}

	printf("End of loop!");

    /* 
        There are three crucial components of a count loop.

        1. The counter variable
        2. Condition checking the counter
        3. The counter being updated to a new value 
           (which eventually invalidates the condition)
    */

    /*
        The loop is executed based the following four steps:
        
        1. Evaluating the condition: 
            When the program execution reaches the while loop, 
            it first evaluates the condition provided within 
            the parentheses.
        2. Executing the loop body: 
            If the condition is found true, the code block 
            enclosed within the curly braces is executed.
        3. Re-evaluation: 
            The condition is re-evaluated, and if it 
            remains true, the loop body is executed again. 
            This process of re-evaluation and execution 
            continues until the condition becomes false.
        4. Termination: 
            Once the condition becomes false, the loop 
            terminates, and the program execution moves 
            to the next statement after the loop.
    */

    return 0;
}
