/*
Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine the records in file F. 
Assume that file F is maintained in memory by a Hash Table (HT) of m memory locations with L as the set of memory addresses (2-digit) of locations in HT. 
Let the keys in K and addresses in L are Integers. 
Program in C that uses Hash function H:K→LasH(K)=Kmodm(remainder method), and implement hashing technique to map a given key K to the address space L. 
.Resolve the collision (if any) using linear probing.*/


#include<stdio.h>
#include<stdlib.h>

int key[20], n, m;   // Array for storing employee keys, n is the number of records, m is the size of hash table
int *ht, index;      // Pointer to the hash table and variable for calculated hash index
int count = 0;       // Counter to track the number of inserted records

// Function to insert a key into the hash table
void insert(int key) {
    index = key % m;                     // Compute hash index using the formula H(K) = K % m
    while (ht[index] != -1) {            // If collision occurs (index is already occupied)
        index = (index + 1) % m;         // Use linear probing to find the next available index
    }
    ht[index] = key;                     // Insert the key at the computed index
    count++;                             // Increment the count of inserted records
}

// Function to display the contents of the hash table
void display() {
    int i;
    if (count == 0) {                    // If no records are inserted
        printf("\nHash Table is empty");
        return;
    }
    printf("\nHash Table contents are:\n ");
    for (i = 0; i < m; i++) {
        printf("\n T[%d] --> %d ", i, ht[i]);  // Print each index and its corresponding value
    }
    printf("\n");
    printf("Total records inserted: %d\n", count);  // Print the total number of inserted records
}

// Main function to handle input and drive the program
void main() {
    int i;

    // Input the number of employee records
    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);

    // Input the size of the hash table
    printf("\nEnter the two-digit memory locations (m) for hash table: ");
    scanf("%d", &m);

    // Allocate memory for the hash table and initialize all locations to -1
    ht = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        ht[i] = -1;  // -1 indicates an empty location
    }

    // Input the keys for employee records
    printf("\nEnter the four-digit key values (K) for N Employee Records:\n ");
    for (i = 0; i < n; i++) {
        scanf("%d", &key[i]);  // Store each key in the array
    }

    // Insert the keys into the hash table
    for (i = 0; i < n; i++) {
        if (count == m) {  // If the hash table is full, stop inserting further keys
            printf("\n~~~ Hash table is full. Cannot insert the record %d key ~~~", i + 1);
            break;
        }
        insert(key[i]);  // Call the insert function to add the key to the hash table
    }

    // Display the contents of the hash table
    display();
}
