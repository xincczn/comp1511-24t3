// Xing He, z5413977, 25/10/24
// Part 3: Structs and Pointers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[100];
    char author[100];
    int year;
};

void modify_book(struct book *book);

int main() {
    struct book book;

    strcpy(book.title, "To Kill a Mockingbird");
    strcpy(book.author, "Harper Lee");
    book.year = 1960;

    printf("Before modification:\n");
    printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);

    modify_book(&book);  // Pass the address instead

    printf("After modification:\n");
    printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);

    return 0;
}
// Refer to functions_and_pointers.c first
// When it comes structs, when we dereference the struct pointer to access the struct's members
// Instead of adding the asterisk * behind the variable
// We simply replace the dot operator . (which access a member) with an arrow/stab operator ->
void modify_book(struct book *book) {
    book->year = 1925;
    strcpy(book->title, "The Great Gatsby");
    strcpy(book->author, "F. Scott Fitzgerald");
}

/*
    Unmodified function

    void modify_book(struct book book) {
        book.year = 1925;
        strcpy(book.title, "The Great Gatsby");
        strcpy(book.author, "F. Scott Fitzgerald");
    }
*/