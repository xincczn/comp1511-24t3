// Xing He, z5413977, 08/11/24
// Part 1: Remove nodes from linked list

#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
    // Node Values
    int value;

    // Next Pointer
    struct node *next;
};

// Linked List functions (implemented tut 07)
struct node *create_node(int data);
struct node *append_to_head(struct node *head, int data);
struct node *append_to_tail(struct node *head, int data);
void print_list(struct node *head);
int list_length(struct node *head);

// New Linked List functions
struct node *remove_head(struct node *head);
struct node *remove_tail(struct node *head);

// Main
int main(void) {
    // X
    struct node *head = NULL;

    // 1 -> 2 -> 3 -> 4 -> 5 -> X
    for (int n = 0; n < 5; n++) {
        head = append_to_tail(head, n + 1);
    }

    int length = list_length(head);
    printf("There are %d nodes in the list\n", length);
    print_list(head);

    // 2 -> 3 -> 4 -> 5 -> X
    head = remove_head(head);

    // 2 -> 3 -> 4 -> X
    head = remove_tail(head);

    // 2 -> 3 -> X
    head = remove_tail(head);

    // 3 -> X
    head = remove_head(head);

    // X
    head = remove_head(head);

    // X (Ensuring that removing from an empty list doesn't do anything weird)
    head = remove_head(head);
    head = remove_head(head);
    head = remove_tail(head);
    head = remove_tail(head);

    length = list_length(head);
    printf("There are %d nodes in the list\n", length);
    print_list(head);
}

// Removes the head of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//
// Returns:
//      A pointer to the head of the linked list
struct node *remove_head(struct node *head) {
    // If the linked list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // Store the head node in a temporary variable
    struct node *temp = head;
    // Update the head to point to the next node
    head = head->next;
    // Free the memory allocated for the old head node
    free(temp);

    return head;
}

// Removes the tail of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//
// Returns:
//      A pointer to the head of the linked list
struct node *remove_tail(struct node *head) {
    // If the linked list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // If the linked list has only one node, free the memory
    // allocated for the node and return NULL
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Traverse the linked list to find the second last node
    struct node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Store the last node in a temporary variable
    struct node *temp = current->next;

    // Update the second last node to point to NULL
    current->next = NULL;

    // Free the memory allocated for the last node
    free(temp);

    return head;
}

// -----------------------------------------------------------------------------

struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;  

    return new_node;
}

struct node *append_to_head(struct node *head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = head;

    return new_node;
}

struct node *append_to_tail(struct node *head, int data) {
    struct node *new_node = create_node(data);

    if (head == NULL) {
        return new_node;
    }

    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return head;
}

void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }

    printf("X\n");  
}

int list_length(struct node *head) {
    int length = 0;

    struct node *current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}