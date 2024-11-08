// Xing He, z5413977, 08/11/24
// Part 3: Linked List Exercises

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Linked List Node
struct node {
    // Node Values
    int data;

    // Next Pointer
    struct node *next;
};

// -----------------------------------------------------------------------------
// Functions Prototypes
// -----------------------------------------------------------------------------

/**
 *  Given two linked lists:
 *      return 0, if neither list contains even numbers.
 *      return 1, if one list contains even numbers, but the other does not.
 *      return -1, if both lists contain even numbers.
 */
int list_evens(struct node *head1, struct node *head2);

// Given a linked list that is ordered in acending order and a value to insert, 
// insert the value into the list that will allow the list to remain 
// in acending order.
struct node *list_ordered_insert(struct node *head, int data);

// Given a linked list, remove the node with the smallest value from the linked 
// list and return the new head of the list.
struct node *list_delete_smallest(struct node *head);

// Given a linked list, make a copy of the list and free the old list 
// and return the new head of the list.
struct node *list_copy(struct node *head1);

// Given a linked list, reverse the list and return the new head of the list.
struct node *list_reverse(struct node *head);

// Given two linked lists, return a new list that is constructed of nodes 
// containing any values that appear in both lists.
struct node *list_find_intersection(struct node *head1, struct node *head2);

// Given a linked list and a value, count the number of times that value
// appears in the linked list.
int list_count_occurrences(struct node *head, int data);

/* BONUS FUNCTIONS */

// Given a linked list and a value, find if that value exists in the list
// and return the node holding that value, otherwise return null.
// Note: This is a powerful function and is usually used for many scenarios.
//       We use this in the implementation of `list_find_intersection()`
//       Check the function for an example of usage.
//       (Might find this function useful in assignment 2)
struct node *find_node(struct node *head, int data);


// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------

int main(void) {
    /* Test your functions */
    
    return 0;
}

// -----------------------------------------------------------------------------
// Revision functions Implementation
// -----------------------------------------------------------------------------

int list_evens(struct node *head1, struct node *head2) {
    /**
     *  Thought process:
     *      We can check each list separately on if they contain even numbers.
     *      A flag (sentinel variable) can be used to represent if the list 
     *      is even.
     *      We can then compare the flags to know what we should return.
     */

    int is_list_1_even = FALSE;
    int is_list_2_even = TRUE;

    // Check if list 1 contains an even number
    // We iterate through each node in our list
    // If the current node is even, we set the respective flag to TRUE 
    struct node *current = head1;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            is_list_1_even = TRUE;  // the flag can only be changed from F to T
        }

        current = current->next;
    }

    // Do the same with thing on list 2
    current = head2;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            is_list_2_even = TRUE;  // the flag can only be changed from F to T
        }

        current = current->next;
    }

    // Now we need to compare the flags
    if (is_list_1_even && is_list_2_even) {
        return -1;
    } else if (is_list_1_even || is_list_2_even) {
        return 1;
    } else {
        return 0;
    }
}

struct node *list_ordered_insert(struct node *head, int data) {
    /**
     *  Thought process:
     *      Since the list passed into this function is already sorted,
     *      then we can add our new number before the current node if
     *      it is smallest.
     */

    // Create new node (this should be its own function)
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    // We are going utilise a previous pointer to help with this
    // Previous is null initially since theres no node before the head
    struct node *previous = NULL;  
    struct node *current = head;

    // The loop stops if we are at the end, or current's data is larger
    while (current != NULL && data > current->data) {
        // We move the previous to where current is
        // Why is the order of these two lines important?
        previous = current;  
        current = current->next;
    }

    // After this loop ends, then current and previous will be positioned 
    // where we want them and can use them to attach our new node

    // If previous is null, then current must still be the head
    // and the new node is inserted as the new head
    // (since previous was never moved)
    if (previous == NULL) {
        new->next = head;
        return new;
    }

    // Otherwise, we insert the new node between previous and current
    // What does it mean if current is null and does it matter?
    previous->next = new;
    new->next = current;

    // head wasn't changed
    return head;
}

struct node *list_delete_smallest(struct node *head) {
    /**
     *  Thought process:
     *      First we need to find the smallest value
     *      Then we can delete the node using the normal method
     */

    // Base case: Empty list
    // Nothing to delete
    if (head == NULL) {
        return head;
    }

    // We assign smallest with the first node's value
    // We can't guarantee that any other value doesnt exist in the list
    int smallest = head->data;

    /**
     * We are going to use the previous node approach here
     * Since the current->next node approach can be 
     * found in tut_09/part1_delete_list.c
     * 
     * Example list:
     *     1 -> 2 -> 3 -> 4 -> 5 -> X
     *  p  c
     * 
     * Set previous to NULL since there is no node before the head
     * Current is at head initially
     * Each time current moves, previous moves as well
     */
         
    struct node *previous = NULL;
    struct node *current = head;
    
    /**
     * We want the loop to stop when current 
     * to the node holding the smallest value
     * The condition for when the loop stops:
     * (we are at the end) or (we are at the smallest node)
     *     current == NULL || current->data == smallest
     */
    while (current != NULL && current->data != smallest ) {
        previous = current;
        current = current->next;
    }

    // Now we just check previous and current
    if (previous == NULL) {
        // Then we are still at the head
        struct node *temp = current;
        current = current->next;
        free(temp);
        return current;
    }

    // Otherwise current is not the head
    previous->next = current->next;
    free(current);

    return head;
}

struct node *list_copy(struct node *head1) {
    /**
     * Thought process:
     *      We go through each node in the list and create a new node with 
     *      its data.
     *      Then, we add it at the tail of our new list.
     */

    // Base case: Empty list
    // Nothing to copy
    if (head1 == NULL) {
        return head1;
    }

    // Create new list and a pointer to keep track of the tail of new list
    struct node *new_head = NULL;
    struct node *new_tail = NULL;

    struct node *current = head1;
    while (current != NULL) {
        // Create new node
        struct node *new = malloc(sizeof(struct node));
        new->data = current->data;
        new->next = NULL;

        // For the first node, we need to update head and tail
        // Subsequent nodes will be attach as new tail
        if (new_head == NULL) {
            new_head = new;
            new_tail = new;
        } else {
            new_tail->next = new;
            new_tail = new;
        }

        // Store node to be delete to temp and move current to next node
        struct node *temp = current;
        current = current->next;
        free(temp);
    }

    return new_head;
}

struct node *list_reverse(struct node *head) {
    /**
     * Thought process: 
     *      This one is a bit tricky and as mentioned in the tutorial,
     *      the best way to solve a lot of linked list questions is by
     *      drawing them out.
     *      Specifically, the before and after diagrams.
     * 
     * Example:
     *      Before: 1 -> 2 -> 3 -> 4 -> 5 -> X
     *      After:  5 -> 4 -> 3 -> 2 -> 1 -> X
     * 
     *      Still a bit confusing what to do but what if we aligned the
     *      respective nodes in the diagram like this:
     * 
     *      Before: X    1 -> 2 -> 3 -> 4 -> 5 -> X
     *      After:  X <- 1 <- 2 <- 3 <- 4 <- 5    X
     * 
     *      Now we can see that we are just swapping the arrows around.
     *      We can use all three pointers: previous, current, and next 
     *      to solve this.
     */
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;  // Keep track of next node
        current->next = prev;  // Redirect current->next to point to prev
        prev = current;        // Move the previous pointer forward
        current = next;        // Move the current pointer forward
    }
    
    return prev;
}

struct node *list_find_intersection(struct node *head1, struct node *head2) {
    /**
     * Thought process:
     *      We can find the intersection (values that exists in both list)
     *      by going through one list and seeing if a node's value exist in
     *      the other list
     */

    // Create new list and a pointer to keep track of the tail of new list
    struct node *new_head = NULL;
    struct node *new_tail = NULL;

    struct node *current = head1;
    while (current != NULL) {
        // Check if current exists in the second list
        // We can use a helper function
        struct node *found = find_node(head2, current->data);
        if (found != NULL) {
            // Create a new node
            struct node *new = malloc(sizeof(struct node));
            new->data = found->data;
            new->next = NULL;

            // New list is empty
            if (new_head == NULL) {
                new_head = new;
                new_tail = new;
            } else {
                // Append new node to tail of new list
                new_tail->next = new;
                new_tail = new;
            }
        }

        current = current->next;
    }

    return new_head;
}

int list_count_occurrences(struct node *head, int data) {
    /**
     * Thought process:
     *      Just go through the list and count each time we come across
     *      a node holding the matching value
     */
    int count = 0;
    while (head != NULL) {
        if (head->data == data) {
            count++;
        }
        head = head->next;
    }
    return count;
}

// -----------------------------------------------------------------------------
// Bonus functions
// -----------------------------------------------------------------------------

struct node *find_node(struct node *head, int data) {
    /**
     * Thought process:
     *      We just go through the list and attempt to find the node
     */

    struct node *current = head;
    while (current != NULL) {
        // return early if node was found
        if (current->data == data) {
            return current;
        }

        current = current->next;
    }

    // Didn't find the node and return'd early
    return NULL;
}
