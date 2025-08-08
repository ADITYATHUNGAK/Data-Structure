/*Program in C for the following operations on Circular QUEUE of
characters(Array ImplementationofQueue with maximum size MAX)
f. Insert an Element on to CircularQUEUE
g. Delete an Elementf rom CircularQUEUE
h. Demonstrate Overflow and Underflow situations on CircularQUEUE
i. Display the status of CircularQUEUE
j. Exit
Support the program with appropriate functions for each of the above operations.*/

//program
#include <stdio.h>
#define MAX 5  // Define the maximum size of the circular queue

int queue[MAX];  // Array to represent the circular queue
int front = -1, rear = -1;  // Initialize front and rear pointers to -1 (queue is empty)

// Function to insert an element in the circular queue
void enQueue(int item) {
    // Check if the queue is full
    if ((front == (rear + 1) % MAX)) {
        printf("Queue is full (Overflow)\n");  // Queue overflow situation
        return;
    }
    
    // If this is the first insertion, set front to 0
    if (front == -1) {
        front = 0;
    }

    // Update rear to the next position using modular arithmetic for circular behavior
    rear = (rear + 1) % MAX;
    queue[rear] = item;  // Insert the item at the rear
    printf("Inserted %d into the queue\n", item);
}

// Function to delete an element from the circular queue
void deQueue() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue is empty (Underflow)\n");  // Queue underflow situation
        return;
    }

    // Print the element being dequeued
    printf("Deleted %d from the queue\n", queue[front]);

    // If only one element is left, reset both front and rear to -1 (queue becomes empty)
    if (front == rear) {
        front = rear = -1;
    } else {
        // Move front to the next position using modular arithmetic for circular behavior
        front = (front + 1) % MAX;
    }
}

// Function to display the elements of the circular queue
void display() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    
    // Start displaying from the front and loop through the queue until rear is reached
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;  // Move to the next position in a circular manner
    }
    printf("%d\n", queue[rear]);  // Print the last element
}

// Main function to drive the menu-based circular queue operations
int main() {
    int choice, item;  // Variables to store user choice and the item to be inserted

    while (1) {
        // Display the menu for circular queue operations
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Read the user's choice

        switch (choice) {
            case 1:  // Insert an element into the circular queue
                printf("Enter the element to insert: ");
                scanf("%d", &item);  // Read the item to be inserted
                enQueue(item);  // Call enQueue function
                break;
            case 2:  // Delete an element from the circular queue
                deQueue();  // Call deQueue function
                break;
            case 3:  // Display the circular queue
                display();  // Call display function
                break;
            case 4:  // Exit the program
                printf("Exiting...\n");
                return 0;  // Exit the program
            default:  // Handle invalid input
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
