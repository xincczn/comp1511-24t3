// Xing He, z5413977, 31/10/24
// Part 3: Programming Linked Lists

#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
    // Node Values
    int value;

    // Next Pointer
    struct node *next;
};

// Linked List functions
struct node *create_node(int data);
struct node *append_to_head(struct node *head, int data);
struct node *append_to_tail(struct node *head, int data);
void print_list(struct node *head);
int list_length(struct node *head);

// Main
int main(void) {
    // Create a pointer to the head of the linked list
    struct node *head = NULL;

    // Insert a node at the beginning of the linked list
    head = append_to_head(head, 10);

    // Insert a node at the beginning of the linked list
    head = append_to_head(head, 5);

    // Insert a node at the end of the linked list
    head = append_to_tail(head, 15);

    // Insert a node at the end of the linked list
    head = append_to_tail(head, 20);

    // Print the linked list
    print_list(head);

    // Calculate and print the length of the linked list
    int length = list_length(head);
    printf("There are %d nodes in the list\n", length);

    // Note: We don't free in this exercise
    //       This will be covered next week :)

    return 0;
}

// Creates a new node
//
// Parameters:
//      data: The data to be stored in the new node
//
// Returns:
//      A pointer to the new node
struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    // Remember to always set new node's next to null initially
    // Eliminates errors where next is uninitialised
    new_node->next = NULL;  

    return new_node;
}

// Inserts a new node at the head of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//      data: The data to be stored in the new node
//
// Returns:
//      A pointer to the new head of the linked list
struct node *append_to_head(struct node *head, int data) {
    // Create a new node given data
    struct node *new_node = create_node(data);

    // Remember that single nodes are just linked list with 1 element
    // which means new_node is already a linked list and we can just allow it
    // to point to the rest of the initial list
    new_node->next = head;
    return new_node;
}

// Inserts a new node at the tail of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//      data: The data to be stored in the new node
//
// Returns:
//      A pointer to the head of the linked list
struct node *append_to_tail(struct node *head, int data) {
    // Create a new node given data
    struct node *new_node = create_node(data);

    // Empty List Case (base case)
    if (head == NULL) {
        return new_node;
    }

    // Loop that positions `current` to the tail of the list
    struct node *current = head;
    // Note that this loop while fail if the base case isn't handled
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node at the end of the linked list
    current->next = new_node;
    return head;
}

// Traverses a linked list and prints the data in each node
//
// Parameters:
//      head: A pointer to the head of the linked list
//
// Returns:
//      None
void print_list(struct node *head) {
    // Standard iterating structure for linked lists
    // Traverse the linked list and print each node 
    // until we reach the end of the list
    struct node *current = head;
    while (current != NULL) {
        // Prints individual node's value, formatted by an arrow 
        printf("%d -> ", current->value);
        current = current->next;
    }
    // We can't physically print NULL's value, so we print a X
    printf("X\n");  
}

// Finds the number of nodes in a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//
// Returns:
//      The number of nodes in the linked list
int list_length(struct node *head) {
    // Initialize the length of the list to 0
    int length = 0;

    // Set current to be the first node in the list
    struct node *current = head;

    // Traverse the linked list and increment the length
    // until we reach the end of the list
    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}