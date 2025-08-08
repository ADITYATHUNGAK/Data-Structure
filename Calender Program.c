/*Program in C for the following:
Declare a calendar as an array of 7 elements (A dynamically Created array) to represent 7 days of week. 
Each Element of the array is a structure having three fields.
The first field is the name of the Day (A dynamically allocated String), 
The second field is the date of the Day (A integer), 
the third field is the description of the activity for a particular day (A dynamically allocated String).
Write functions create(), read() and display(); to create the calendar, to read the data from the keyboard and to print weeks activity details report on screen.
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS 7

// Structure to represent a day
struct Day {
    char* dayName;             // Pointer to store the name of the day (dynamically allocated)
    int date;                  // Integer to store the date of the day
    char* activityDescription; // Pointer to store the activity description for the day (dynamically allocated)
};

// Function to create and initialize the calendar
void create(struct Day* calendar) {
    for (int i = 0; i < MAX_DAYS; i++) {
        // Allocate memory for the day name (20 characters max)
        calendar[i].dayName = (char *)malloc(20 * sizeof(char));
        
        // Allocate memory for the activity description (100 characters max)
        calendar[i].activityDescription = (char *)malloc(100 * sizeof(char));
    }
}

// Function to read data from the user
void read(struct Day* calendar) {
    for (int i = 0; i < MAX_DAYS; ++i) {
        printf("\nEnter details for day %d:\n", i + 1);

        // Read the name of the day
        printf("Enter day name: ");
        scanf("%s", calendar[i].dayName);

        // Read the date of the day
        printf("Enter date: ");
        scanf("%d", &calendar[i].date);

        // Read the activity description (this handles multi-word input)
        printf("Enter activity description: ");
        scanf(" %[^\n]", calendar[i].activityDescription);
    }
}

// Function to display the calendar
void display(struct Day* calendar) {
    printf("\nWeek's Activity Details Report:\n");
    printf("%-10s %-10s %-30s\n", "Day", "Date", "Activity Description");

    // Loop through each day and print its details
    for(int i = 0; i < MAX_DAYS; ++i) {
        printf("%-10s %-10d %-30s\n", calendar[i].dayName, calendar[i].date, calendar[i].activityDescription);
    }
}

// Function to free the dynamically allocated memory
void freeMemory(struct Day* calendar) {
    for (int i = 0; i < MAX_DAYS; ++i) {
        // Free the memory allocated for day name
        free(calendar[i].dayName);

        // Free the memory allocated for activity description
        free(calendar[i].activityDescription);
    }
}

int main() {
    // Dynamically allocate memory for the calendar (array of 7 Day structures)
    struct Day* calendar = (struct Day*)malloc(sizeof(struct Day) * MAX_DAYS);

    // Check if memory allocation was successful
    if (calendar == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit if memory allocation failed
    }

    // Call the create function to initialize the calendar
    create(calendar);

    // Call the read function to input data from the user
    read(calendar);

    // Call the display function to show the week's activity details
    display(calendar);

    // Free the allocated memory
    freeMemory(calendar);
    free(calendar);

    return 0;
}
