# Week 1 Tutorial

## Terminal Commands

```bash
# Print Working Directory
pwd

# Change Directory
cd <path>

# Unique Directories
.  (current directory)
.. (previous directory)
~  (home directory)

# List directory contents
ls

# Make Directory
mkdir <directory_name>

# Opens file in VSCode (If file doesn't exist, creates it)
code <file_name> &

# Creates a file (Use `code` over this generally)
touch <file_name>

# Moves a file from A to B
mv <path_of_A> <path_of_B>

# Copies file from A to B
cp <path_of_A> <path_of_B>

# Remove file (Use sparingly)
rm <file_name>
```

## C Code Features

```c
// Basic Hello World program
// Marc Chee, September 2020

#include <stdio.h>

int main(void) {
    printf("Hello World\n");

    return 0;
}
```

Some interesting features from the block of code above are:

### Comments

```c
// Basic Hello World program
// Marc Chee, September 2020
```

Comments are used to annotate written code or pieces of useful statements.

We write comments, starting with `//` followed by the comment itself.

---

### Printf Statements

```c
printf("Hello World\n");
```

Print functions are a type of statement that allows us to print `"Strings"` to our terminal.

The structure goes like this `printf();` and we place the string to be printed between the two brackets `()`.

---

### Semicolons

```c
printf("Hello World\n");
return 0;
```

Semicolons end code statements. Think of them like full stops `.` in sentences.

We must end each statement with a semicolon like above or else we will not be able to run our code properly.

---

### Indentation

```c
// Indentation Level 0
{
    // Level 1
    {
        // Level 2
        {
            // Level 3
            {
                // Level 4
            }
            // Level 3
		    }
        // Level 2
    }
    // Level 1
}
```

Indentation is used to improve the readability of our code.

To increase the indentation level by one, we either add 4 `spaces` or by pressing the `tab` key.

A simple rule to indenting properly is to always increase the indentation level by one when entering a pair of curly braces `{}` and vice versa.

---

### Escape Character

```c
printf("Hello World\n");
```

The backslash `\` is a special character as it isn’t interpreted normally by C. Instead it ******\*\*******changes******\*\******* the meaning of the character place behind it e.g., `\a` `\b` `\n` `\"` `\\`. Because of this, be wary when using it as it might cause your code to not compile.

Some notable combinations in C are:

- `\n` is a newline character
- `\"` allows you to use the **`“`** character without it being interpreted as the start of a string.

```c
// Example: Lets say you wanted to print out "Hi!" (quotes included)
// We would type something like this:

printf(""Hi!"");

// Notice how the string isn't completely highlighted?
// This is because C counts a string as characters between two double quotes

"string"Hi!"string"

// As you can see, Hi! isn't apart of either strings
// To fix this we can escape the double quote itself:

"\"Hi!\""
```

- `\\` allows you to print a backslash inside your strings by escaping itself

---

### Importing Libraries

```c
#include <stdio.h>
```

By typing `#include <name>` at the start of a C file, we can import and use a library which contains prewritten code (code that somebody else wrote so we don’t have to).

`printf()` for example comes from the `<stdio.h>` library which allows us to print text to the terminal. We will be exploring some other stuff found in this library in the future.

---

### Return statement

```c
return 0;
```

A `return` statement signifies the end of our code. Anything written underneath one will not be executed.

```c
int main() {
	// reachable code
	return 0;
	// unreachable code
}
```

## Other

[My VS Code Theme: Dark Horizon](https://marketplace.visualstudio.com/items?itemName=mcagampan.dark-horizon)
