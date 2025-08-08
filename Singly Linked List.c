/*Program in C for the following operations on SinglyLinkedList(SLL) of
student Data with the fields:USN,Name, Programme, Sem,PhNo.
a. Create a SLL of N Students Data by using frontinsertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion/Deletionat End of SLL
d. Perform Insertion/Deletion at Front of SLL(Demonstration of stack)
e. Exit
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student data
struct node {
    char usn[25], name[25], branch[25]; // USN, Name, Branch of the student
    int sem;                            // Semester of the student
    long int phone;                     // Phone number of the student
    struct node *link;                  // Pointer to the next node
};

typedef struct node * NODE;  // Define NODE as a pointer to struct node
NODE start = NULL;           // Start pointer to the beginning of the linked list
int count = 0;               // Count to keep track of the number of nodes in the list

// Function to create a new node for student data
NODE create() {
    NODE snode;
    snode = (NODE)malloc(sizeof(struct node));  // Allocate memory for a new node
    if (snode == NULL) {
        printf("\nMemory is not available");    // If memory allocation fails, exit
        exit(1);
    }
    // Get input for student details
    printf("\nEnter the USN, Name, Branch, Semester, and Phone Number of the student: ");
    scanf("%s %s %s %d %ld", snode->usn, snode->name, snode->branch, &snode->sem, &snode->phone);
    snode->link = NULL;        // The new node's next pointer is set to NULL (end of the list)
    count++;                   // Increment the node count
    return snode;              // Return the newly created node
}

// Function to insert a node at the front of the SLL
NODE insertfront() {
    NODE temp = create();      // Create a new node
    if (start == NULL) {       // If the list is empty, the new node becomes the start
        return temp;
    }
    temp->link = start;        // Otherwise, link the new node to the current start node
    return temp;               // Return the new node as the start
}

// Function to delete a node from the front of the SLL
NODE deletefront() {
    NODE temp;
    if (start == NULL) {       // Check if the list is empty
        printf("\nLinked list is empty");
        return NULL;
    }
    temp = start;              // Store the current start node in a temp variable
    start = start->link;       // Update the start to the next node in the list
    printf("\nThe Student node with USN: %s is deleted", temp->usn); // Print the deleted node's details
    free(temp);                // Free the memory of the deleted node
    count--;                   // Decrement the node count
    return start;
}

// Function to insert a node at the end of the SLL
NODE insertend() {
    NODE cur, temp = create(); // Create a new node
    if (start == NULL) {       // If the list is empty, the new node becomes the start
        return temp;
    }
    cur = start;
    while (cur->link != NULL) { // Traverse to the last node of the list
        cur = cur->link;
    }
    cur->link = temp;          // Add the new node at the end
    return start;
}

// Function to delete a node from the end of the SLL
NODE deleteend() {
    NODE cur, prev;
    if (start == NULL) {        // Check if the list is empty
        printf("\nLinked List is empty");
        return NULL;
    }
    if (start->link == NULL) {  // If there is only one node in the list
        printf("\nThe student node with USN: %s is deleted", start->usn);
        free(start);            // Delete the single node
        count--;
        return NULL;
    }
    prev = NULL;
    cur = start;
    while (cur->link != NULL) { // Traverse to the last node
        prev = cur;
        cur = cur->link;
    }
    printf("\nThe student node with USN: %s is deleted", cur->usn); // Print the deleted node's details
    free(cur);                  // Free the memory of the last node
    prev->link = NULL;          // Update the previous node's link to NULL (new end of the list)
    count--;
    return start;
}

// Function to display the SLL
void display() {
    NODE cur;
    int num = 1;
    if (start == NULL) {        // Check if the list is empty
        printf("\nNo Contents to display in SLL\n");
        return;
    }
    printf("\nThe contents of SLL:\n");
    cur = start;
    while (cur != NULL) {       // Traverse the list and print each node's details
        printf("\n||%d|| USN: %s | Name: %s | Branch: %s | Sem: %d | Ph: %ld |",
               num, cur->usn, cur->name, cur->branch, cur->sem, cur->phone);
        cur = cur->link;        // Move to the next node
        num++;
    }
    printf("\nNo of student nodes is %d\n", count);  // Print the total number of nodes
}

// Stack demo functions for insertion/deletion at the front
void stackdemo() {
    int ch;
    while (1) {
        printf("\n~~~ Stack Demo using SLL ~~~\n");
        printf("\n1: Push operation\n2: Pop operation\n3: Display\n4: Exit\n");
        printf("\nEnter your choice for stack demo: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: start = insertfront();  // Stack Push operation (insert at front)
                    break;
            case 2: start = deletefront();  // Stack Pop operation (delete from front)
                    break;
            case 3: display();              // Display the current stack (SLL)
                    break;
            default: return;                // Exit the stack demo
        }
    }
}

// Main function to handle all operations
int main() {
    int ch, i, n;
    while (1) {
        printf("\n~~~ Menu ~~~");
        printf("\nEnter your choice for SLL operation: ");
        printf("\n1: Create SLL of Student Nodes");
        printf("\n2: Display Status");
        printf("\n3: Insert at End");
        printf("\n4: Delete at End");
        printf("\n5: Stack Demo using SLL (Insertion and Deletion at Front)");
        printf("\n6: Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the number of students: ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++)  // Create N student nodes using front insertion
                    start = insertfront();
                break;
            case 2:
                display();               // Display the current list of students
                break;
            case 3:
                start = insertend();      // Insert a node at the end of the list
                break;
            case 4:
                start = deleteend();      // Delete a node from the end of the list
                break;
            case 5:
                stackdemo();              // Demonstrate stack operations using SLL
                break;
            case 6:
                exit(0);                  // Exit the program
            default:
                printf("\nPlease enter a valid choice");  // Invalid choice handling
        }
    }
}

