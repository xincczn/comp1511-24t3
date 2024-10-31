// Xing He, z5413977, 31/10/24
// Part 3: Linked List Practice (Tutorial Code)

#include <stdio.h>
#include <stdlib.h>


struct node {
    // The data stored in the node
    int value;
    // Pointer to the next node in the linked list
    struct node *next;
};

// Function Prototypes - Linked List Operations
struct node *create_node(int data);

struct node *insert_head(struct node *head, int data);

struct node *insert_tail(struct node *head, int data);

void print_list(struct node *head);

int list_length(struct node *head);

int main(void) {

    // Create a pointer to the head of the linked list
    struct node *head = NULL;

    // Insert a node at the beginning of the linked list
    head = insert_head(head, 10);

    // Insert a node at the beginning of the linked list
    head = insert_head(head, 5);

    // Insert a node at the end of the linked list
    head = insert_tail(head, 15);

    // Insert a node at the end of the linked list
    head = insert_tail(head, 20);

    // Print the linked list
    print_list(head);

    // Calculate and print the length of the linked list
    int length = list_length(head);
    printf("There are %d nodes in the list\n", length);

    return 0;
}

// Creates a new node
//
// Parameters:
//      data: The data to be stored in the new node
//
// Returns:
//      A pointer to the new node
struct node *create_node(int data) {
    // 1. draw the circle (creating node)
    struct node *new_node = malloc(sizeof(struct node));
    // 2. give it a value (assign it data)
    new_node->value = data;
    // 3. draw arrow pointing to X (assigning next pointer to NULL)
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
struct node *insert_head(struct node *head, int data) {
    struct node *new_node = create_node(data);

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
struct node *insert_tail(struct node *head, int data) {
    struct node *new_node = create_node(data);

    // Base case - Empty Linked List (i.e., head == NULL)
    // Guard statement allows us to return early
    if (head == NULL) {
        return new_node;
    }

    // If the guard statement failed to guard
    // Then we can assume the opposite of the guard condition
    // Therefore head != NULL i.e., head is not empty

    // Apply iterating through a linked list pattern
    /*
        struct node *current = head;
        while (... != NULL) {
            current = current->next;
        }
    */
    struct node *current = head;  // counter
    // tail -> current->next == NULL
    while (current->next != NULL) {
        // This loop only executes if current isnt the tail
        current = current->next;
    }

    // current is now the tail after the loop (whether it ran or not)
    // assign current tail to point to new tail
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
    // Set current to be the first node in the list
    struct node *current = head;
    
    // Traverse the linked list and print each node 
    // until we reach the end of the list
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
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
    int length = 0;

    // 1. iterate through the list
    struct node *current = head;

    // Base case - empty list
    // Base case - single node list
    // Main case - 1+ node list

    // Tip: writing while loop conditions
    //      the loop condition is when it should continue (not stop)
    //      so we should first figure out when it should stop
    //      current == NULL
    //      take the opposite
    while (current != NULL) {
        // 2. at each node, increment length by 1
        length++;
        current = current->next;
    }


    return length;
}
