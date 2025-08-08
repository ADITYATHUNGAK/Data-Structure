/*Program in C for the following operations on Graph(G) of Cities
a. Create a Graph of N cities  using  Adjacency Matrix.
b. print all the nodes reachable from a given starting node in a digraph using DFS/BFS method
*/


#include<stdio.h>
#include<stdlib.h>

int a[50][50], n, visited[50];  // `a` is the adjacency matrix, `n` is the number of vertices, `visited` keeps track of visited nodes.
int q[20], front = -1, rear = -1;  // Queue for BFS (using front and rear pointers)
int s[20], top = -1, count = 0;    // Stack for DFS (using top pointer)

// Function to perform BFS traversal
void bfs(int v) {
    int i, cur;
    visited[v] = 1;            // Mark the starting vertex as visited
    q[++rear] = v;             // Enqueue the starting vertex

    while (front != rear) {    // While the queue is not empty
        cur = q[++front];      // Dequeue the front element
        for (i = 1; i <= n; i++) {  // Traverse all vertices
            if ((a[cur][i] == 1) && (visited[i] == 0)) {  // If there is an edge and the node is unvisited
                q[++rear] = i;                            // Enqueue the adjacent vertex
                visited[i] = 1;                           // Mark it as visited
                printf("%d ", i);                         // Print the vertex
            }
        }
    }
}

// Function to perform DFS traversal
void dfs(int v) {
    int i;
    visited[v] = 1;            // Mark the starting vertex as visited
    s[++top] = v;              // Push the starting vertex onto the stack

    for (i = 1; i <= n; i++) {  // Traverse all vertices
        if (a[v][i] == 1 && visited[i] == 0) {  // If there is an edge and the node is unvisited
            printf("%d ", i);                   // Print the vertex
            dfs(i);                             // Recursively call DFS for the adjacent vertex
        }
    }
}

// Main function to handle input and menu-driven operations
int main() {
    int ch, start, i, j;

    // Input the number of vertices
    printf("\nEnter the number of vertices in graph: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);  // Read adjacency matrix elements
        }
    }

    // Input the starting vertex
    printf("\nEnter the starting vertex: ");
    scanf("%d", &start);

    // Menu-driven program for BFS and DFS
    while (1) {
        printf("\n==>1. BFS: Print all nodes reachable from a given starting node");
        printf("\n==>2. DFS: Print all nodes reachable from a given starting node");
        printf("\n==>3: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nNodes reachable from starting vertex %d are: ", start);
                for (i = 1; i <= n; i++)
                    visited[i] = 0;  // Reset visited array for BFS
                bfs(start);          // Call BFS function
                for (i = 1; i <= n; i++) {  // Check for unreachable vertices
                    if (visited[i] == 0)
                        printf("\nThe vertex that is not reachable is %d", i);
                }
                break;

            case 2:
                printf("\nNodes reachable from starting vertex %d are:\n", start);
                for (i = 1; i <= n; i++)
                    visited[i] = 0;  // Reset visited array for DFS
                dfs(start);          // Call DFS function
                for (i = 1; i <= n; i++) {  // Check for unreachable vertices
                    if (visited[i] == 0)
                        printf("\nThe vertex that is not reachable is %d", i);
                }
                break;

            case 3:
                exit(0);  // Exit the program

            default:
                printf("\nPlease enter valid choice.");  // Handle invalid input
        }
    }
}
