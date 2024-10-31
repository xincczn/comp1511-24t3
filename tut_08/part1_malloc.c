// Xing He, z5413977, 31/10/24
// Part 1: Malloc and free

#include <stdio.h>
#include <stdlib.h>  // malloc is defined in stdlib

#define ARRAY_SIZE 3

struct box {
    int item_i;
    char item_c;
    double item_d;
};


// Main
int main() {
    //========== What is malloc? ==========
    /*
        Reminder that a function signature looks this:
            <return_type> <function_name>(<parameters>);

        Here is malloc's function signature:
            void *malloc(size_t size);
        
        Terminology:
            void * -> Returns a pointer to the allocated memory 
                      (Don't worry about why its void, just that its a pointer)
            size_t -> type which is a funky word for `int`
            size   -> A number parameter for amount of memory to allocate in bytes

        Malloc allows us to allocate memory on the `heap`. Which gives us control
        over where we allow the memory of variables to exist when the program is
        executing. Normally variables are stored on the `stack` which has its 
        limitations.

        Check out `part1_memory.txt` for more information on the limitations.
     */

    // We can use sizeof(data_type) to determine the size of a type
    // Don't worry about %lu, its just to print funky `size_t `types
    printf("Size of Int: %lu\n", sizeof(int));
    printf("Size of Char: %lu\n", sizeof(char));
    printf("Size of Double: %lu\n", sizeof(double));

    //========== Allocate memory for primitive data types ==========
    double num = 42.42;

    // Use malloc to allocate enough memory for an integer
    double *num_d = malloc(sizeof(double));
    *num_d = 18.18;

    printf("Static memory: %.2lf\n", num);
    printf("Dynamic memory: %.2lf\n", *num_d);

    //========== What is free? ==========
    /*
        Whenever we invoke `malloc` to allocate memory, that memory
        is permanently allocated until we invoke `free`.
        This is very important as any memory that isn't freed is 
        considered a memory leak in our program.

        Memory leaks results from memory which is allocated but not used anymore 
        and limits the amount of memory available to our program as it is 
        executing. Eventually the program might even run out of available memory
        which causes the program to crash. (Very bad!!!)

        TLDR: Every time `malloc` is called, a subsequent `free` should be called
              down the line before the program finishes.

        Here is free's function signature:
            void free(void *ptr)
     */

    // Pass the pointer (not dereferenced) as an argument into `free`
    free(num_d);

    //========== Allocate memory for an array ==========

    // Formula for calculating the size of array for malloc:
    //     amount of elements * size of an element
    int *array_d = malloc(ARRAY_SIZE * sizeof(int));

    array_d[0] = 1;
    array_d[1] = 2;
    array_d[2] = 3;

    printf("Dynamic Array: [ ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array_d[i]);
    }
    printf("]\n");

    // Prove we allocated the right amount of memory
    // printf("Shouldn't compile: %d\n", array_d[3]);

    // As only the array itself is malloc'd, we only free it and not the elements
    free(array_d);

    //========== Allocate memory for a struct ==========
    // Size of struct box
    printf("Size of Struct Box: %lu\n", sizeof(struct box));

    // Allocate like before, use -> instead of . since struct pointer
    struct box *new_box = malloc(sizeof(struct box));
    new_box->item_i = 1;
    new_box->item_c = '2';
    new_box->item_d = 3.0;

    printf("Dynamic Struct Box: {\n");
    printf("\titem_i: %d\n", new_box->item_i);
    printf("\titem_c: %c\n", new_box->item_c);
    printf("\titem_d: %.1lf\n", new_box->item_d);
    printf("}\n");

    // Likewise with arrays, here we free only the struct itself and none of the fields
    free(new_box);
}
