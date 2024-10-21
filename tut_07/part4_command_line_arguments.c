// Xing He, z5413977, 25/10/24
// Part 4: Command-line arguments

/*
    Remember that main() is a function, and although it is a special function, 
    we can define it have parameters. 
    The arguments are passed in via the command line i.e., the terminal

    Normally, we will call the program name like this
        $ dcc args.c -o args
        $ ./args
    
    To pass in arguments, we add them as strings next to the program name
        $ ./args arg1 arg2 arg3
    
    These get processed into a string array (for the above): ["./args", "arg1", "arg2", "arg3"] 

    Note: The program name counts itself as an argument and will always be index 0
*/

// Instead of main(void), we have
int main(int argc, char *argv[]) {
    // argc -> Argument Count
    // An integer denoting the length of the argument array
    printf("argc: %d\n", argc);

    // argv -> Argument Vector
    // An array of strings holding all the arguments
    printf("argv: [");
    for (int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("]\n");

    return 0;
}
