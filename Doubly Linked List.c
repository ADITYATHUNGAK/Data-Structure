/*Program in C for the following operations on DoublyLinkedList(DLL)of Employee
Data with the fields:SSN, Name,Dept,Designation, Sal, PhNo
a. Create a DLLof NEmployees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate How this DLL can be used as a DoubleEnded Queue.
f. Exit.*/

#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the doubly linked list
struct node {
    char ssn[25], name[25], dept[10], designation[25]; // Employee details: SSN, Name, Department, Designation
    int sal;                                           // Salary of the employee
    long int phone;                                    // Phone number of the employee
    struct node *llink;                                // Pointer to the previous node
    struct node *rlink;                                // Pointer to the next node
};

typedef struct node * NODE;   // Define NODE as a pointer to struct node
NODE first = NULL;            // Initialize the start (first) of the DLL to NULL
int count = 0;                // Counter to track the number of nodes in the DLL

// Function to create a new node with employee data
NODE create() {
    NODE enode;
    enode = (NODE)malloc(sizeof(struct node));  // Allocate memory for the new node
    if (enode == NULL) {
        printf("\nRunning out of memory");      // Check for memory allocation failure
        exit(0);
    }
    // Input employee details
    enode->phone=0;
    printf("\nEnter the SSN, Name, Department, Designation, Salary, and Phone Number of the employee: \n");
    scanf("%s %s %s %s %d %ld", enode->ssn, enode->name, enode->dept, enode->designation, &enode->sal, &enode->phone);
    enode->llink = NULL;    // Set the left link to NULL
    enode->rlink = NULL;    // Set the right link to NULL
    count++;                // Increment the node count
    return enode;           // Return the newly created node
}

// Function to insert a node at the front of the DLL
NODE insertfront() {
    NODE temp = create();   // Create a new node
    if (first == NULL) {    // If the list is empty, the new node becomes the start
        return temp;
    }
    temp->rlink = first;    // Link the new node's right link to the current first node
    first->llink = temp;    // Set the current first node's left link to the new node
    return temp;            // Return the new node as the start of the list
}

// Function to display all nodes in the DLL
void display() {
    NODE cur;
    int nodeno = 1;
    cur = first;            // Start from the first node
    if (cur == NULL) {
        printf("\nNo Contents to display in DLL");  // Check if the list is empty
        return;
    }
    printf("\nThe contents of DLL:\n");
    while (cur != NULL) {   // Traverse the list and display each node's data
        printf("\nENode:%d || SSN:%s | Name:%s | Department:%s | Designation:%s | Salary:%d | Phone no:%ld",
               nodeno, cur->ssn, cur->name, cur->dept, cur->designation, cur->sal, cur->phone);
        cur = cur->rlink;   // Move to the next node
        nodeno++;
    }
    printf("\nNumber of employee nodes: %d", count);  // Display the total count of nodes
}

// Function to delete a node from the front of the DLL
NODE deletefront() {
    NODE temp;
    if (first == NULL) {    // Check if the list is empty
        printf("\nDoubly Linked List is empty");
        return NULL;
    }
    if (first->rlink == NULL) {  // If there's only one node in the list
        printf("\nThe employee node with SSN: %s is deleted", first->ssn);
        free(first);             // Free the single node
        count--;
        return NULL;             // Set first to NULL as the list is now empty
    }
    temp = first;            // Store the current first node in temp
    first = first->rlink;     // Move first to the second node in the list
    temp->rlink = NULL;
    first->llink = NULL;      // Set the new first node's left link to NULL
    printf("\nThe employee node with SSN: %s is deleted", temp->ssn);
    free(temp);               // Free the old first node
    count--;
    return first;             // Return the new start of the list
}

// Function to insert a node at the end of the DLL
NODE insertend() {
    NODE cur, temp = create();   // Create a new node
    if (first == NULL) {         // If the list is empty, the new node becomes the start
        return temp;
    }
    cur = first;
    while (cur->rlink != NULL) { // Traverse to the last node of the list
        cur = cur->rlink;
    }
    cur->rlink = temp;           // Link the last node's right link to the new node
    temp->llink = cur;           // Link the new node's left link to the last node
    return first;                // Return the start of the list
}

// Function to delete a node from the end of the DLL
NODE deleteend() {
    NODE prev, cur;
    if (first == NULL) {         // Check if the list is empty
        printf("\nDoubly Linked List is empty");
        return NULL;
    }
    if (first->rlink == NULL) {  // If there's only one node in the list
        printf("\nThe employee node with SSN: %s is deleted", first->ssn);
        free(first);             // Free the single node
        count--;
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->rlink != NULL) { // Traverse to the last node
        prev = cur;
        cur = cur->rlink;
    }
    printf("\nThe employee node with SSN: %s is deleted", cur->ssn);
    free(cur);                   // Free the last node
    prev->rlink = NULL;          // Set the second last node's right link to NULL
    count--;
    return first;                // Return the start of the list
}

// Function to demonstrate double-ended queue (DEQ) operations using DLL
void deqdemo() {
    int ch;
    while (1) {
        printf("\nDemo Double Ended Queue Operations:");
        printf("\n1: Insert at Queue Front\n2: Delete from Queue Front\n3: Insert at Queue Rear\n4: Delete from Queue Rear\n5: Display DLL\n6: Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: first = insertfront(); // Insert at the front (DEQ front insertion)
                    break;
            case 2: first = deletefront(); // Delete from the front (DEQ front deletion)
                    break;
            case 3: first = insertend();   // Insert at the end (DEQ rear insertion)
                    break;
            case 4: first = deleteend();   // Delete from the end (DEQ rear deletion)
                    break;
            case 5: display();             // Display the list
                    break;
            default: return;               // Exit the DEQ demo
        }
    }
}

// Main function for menu-driven DLL operations
void main() {
    int ch, i, n;
    while (1) {
        printf("\n\n~~~ Menu ~~~");
        printf("\n1: Create DLL of Employee Nodes");
        printf("\n2: Display DLL");
        printf("\n3: Insert at End");
        printf("\n4: Delete at End");
        printf("\n5: Insert at Front");
        printf("\n6: Delete at Front");
        printf("\n7: Double Ended Queue Demo using DLL");
        printf("\n8: Exit\n");
        printf("\nPlease enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:  // Create DLL with N employee nodes using end insertion
                printf("\nEnter the number of employees: ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++)
                    first = insertend();
                break;
            case 2:  // Display all nodes in DLL
                display();
                break;
            case 3:  // Insert node at end
                first = insertend();
                break;
            case 4:  // Delete node from end
                first = deleteend();
                break;
            case 5:  // Insert node at front
                first = insertfront();
                break;
            case 6:  // Delete node from front
                first = deletefront();
                break;
            case 7:  // Demonstrate double-ended queue operations
                deqdemo();
                break;
            case 8:  // Exit the program
                exit(0);
            default: 
                printf("\nPlease enter a valid choice");  // Invalid choice handling
        }
    }
}
