/*Program in C for the following operations on Binary Search Tree(BST) of Integers .
a. Create a BST of N Integers: 6, 9,5, 2,8, 15,24, 14,7,8,5, 2
d. Traverse the BST in Inorder,Preorder andPostOrder
c. Search the BST for a given element (KEY)and report the appropriate message
d. Exit*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Search Tree (BST) node
struct BST {
    int data;                  // Data field to store the value
    struct BST *lchild;        // Pointer to the left child
    struct BST *rchild;        // Pointer to the right child
};

typedef struct BST * NODE;     // Define NODE as a pointer to struct BST

// Function to create a new node for the BST
NODE create() {
    NODE temp;
    temp = (NODE) malloc(sizeof(struct BST)); // Allocate memory for the new node
    printf("Enter the value: ");
    scanf("%d", &temp->data);                 // Input the value for the new node
    temp->lchild = NULL;                      // Initialize left child to NULL
    temp->rchild = NULL;                      // Initialize right child to NULL
    return temp;                              // Return the created node
}

// Function to insert a new node into the BST
void insert(NODE root, NODE newnode) {
    /* If the value of the new node is less than the current node's value,
       it will be inserted in the left subtree. */
    if (newnode->data < root->data) {
        if (root->lchild == NULL)             // If the left child is empty, insert here
            root->lchild = newnode;
        else
            insert(root->lchild, newnode);    // Otherwise, recursively call insert on left child
    }
    /* If the value of the new node is greater than the current node's value,
       it will be inserted in the right subtree. */
    if (newnode->data > root->data) {
        if (root->rchild == NULL)             // If the right child is empty, insert here
            root->rchild = newnode;
        else
            insert(root->rchild, newnode);    // Otherwise, recursively call insert on right child
    }
    // Note: Duplicate values are ignored in this implementation.
}

// Function to search for a specific value (key) in the BST
void search(NODE root) {
    int key;
    NODE cur;

    if (root == NULL) {                       // If the tree is empty
        printf("\nBST is empty.");
        return;
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);                        // Input the value to search
    cur = root;                               // Start searching from the root node

    while (cur != NULL) {
        if (cur->data == key) {               // If the key matches the current node's value
            printf("\nKey element is present in BST.");
            return;
        }
        if (key < cur->data)                  // If the key is smaller, move to the left child
            cur = cur->lchild;
        else                                  // If the key is larger, move to the right child
            cur = cur->rchild;
    }

    printf("\nKey element is not found in the BST.");  // If not found
}

// Function for Inorder Traversal (Left, Root, Right)
void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->lchild);                // Recursively traverse the left subtree
        printf("%d ", root->data);            // Visit the root node
        inorder(root->rchild);                // Recursively traverse the right subtree
    }
}

// Function for Preorder Traversal (Root, Left, Right)
void preorder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->data);            // Visit the root node
        preorder(root->lchild);               // Recursively traverse the left subtree
        preorder(root->rchild);               // Recursively traverse the right subtree
    }
}

// Function for Postorder Traversal (Left, Right, Root)
void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->lchild);              // Recursively traverse the left subtree
        postorder(root->rchild);              // Recursively traverse the right subtree
        printf("%d ", root->data);            // Visit the root node
    }
}

// Main function for menu-driven operations
void main() {
    int ch, key, val, i, n;
    NODE root = NULL, newnode;

    while (1) {
        // Display menu
        printf("\n~~~~ BST MENU ~~~~");
        printf("\n1. Create a BST");
        printf("\n2. BST Traversals");
        printf("\n3. Search");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:  // Create a BST with user-defined number of elements
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++) {
                    newnode = create();        // Create a new node
                    if (root == NULL)          // If the tree is empty, set root to the new node
                        root = newnode;
                    else
                        insert(root, newnode); // Otherwise, insert the new node in the BST
                }
                break;

            case 2:  // Perform Inorder, Preorder, and Postorder traversals
                if (root == NULL)
                    printf("\nTree is not created.");
                else {
                    printf("\nThe Preorder display: ");
                    preorder(root);           // Preorder Traversal
                    printf("\nThe Inorder display: ");
                    inorder(root);            // Inorder Traversal
                    printf("\nThe Postorder display: ");
                    postorder(root);          // Postorder Traversal
                }
                break;

            case 3:  // Search for a specific key in the BST
                search(root);
                break;

            case 4:  // Exit the program
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
}

/*
Explanation of the Program:
This program performs the following operations on a Binary Search Tree (BST):

Creating a BST:

The create() function generates a new node by taking user input for the value.
The insert() function places the new node in the BST, following BST rules:
Values smaller than the current node go to the left child.
Values larger than the current node go to the right child.
Duplicate values are ignored.
Traversals:

Inorder Traversal:
Visits nodes in the order: Left Subtree → Root → Right Subtree.
Produces a sorted order of the elements in the BST.
Preorder Traversal:
Visits nodes in the order: Root → Left Subtree → Right Subtree.
Useful for copying or exporting the structure of the tree.
Postorder Traversal:
Visits nodes in the order: Left Subtree → Right Subtree → Root.
Used for deleting or freeing the tree in a bottom-up manner.
Searching:

The search() function looks for a user-specified value (key) in the BST.
It starts at the root and moves left or right depending on the comparison:
If the key is smaller than the current node, move to the left child.
If the key is larger, move to the right child.
If the key is found, it reports success; otherwise, it reports failure.
Menu-Driven Interface:

Users can choose operations like creating a BST, performing traversals, or searching for a key.

Tree structure
           6
         /   \
        5     9
       /     /  \
      2     8    15
           /    /  \
          7    14   24


*/
