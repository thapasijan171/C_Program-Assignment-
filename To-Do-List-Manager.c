// To-Do List Manager

/*
1. Add task 
- The program should allow users to add tasks to the to-do list.
- Users should be able to input a description for the task.
- If the task list is full (reaches the maximum number of tasks), the program should display an appropriate message.

2. View Tasks:
- The program should display the list of tasks along with their completion status.
- Tasks should be numbered for easy identification.
- If there are no tasks in the list, the program should display a message indicating that there are no tasks.

3. Mark Task as Completed:
- Users should be able to mark a task as completed by entering its corresponding task number.
- The program should update the completion status of the specified task.
- If an invalid task number is entered, the program should display an error message.
*/

// To-Do List Manager

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of tasks allowed in the list
#define MAX_TASKS 80
// Maximum length of task description
#define MAX_LENGTH 80

// Define a structure to represent a task
typedef struct {
    char description[MAX_LENGTH]; // Task description
    int completed; // Flag to indicate if the task is completed (1) or not (0)
} Task;

// Array to store tasks
Task tasks[MAX_TASKS];
// Variable to keep track of the number of tasks currently in the list
int num_tasks = 0;

// Function to add a task to the list
void addTask(const char *description) {
    // Check if the task list is not full
    if (num_tasks < MAX_TASKS) {
        // Copy the task description to the tasks array
        strcpy(tasks[num_tasks].description, description);
        // Set the completed flag to 0 (not completed)
        tasks[num_tasks].completed = 0;
        // Increment the number of tasks
        num_tasks++;
        // Print success message
        printf("Task added successfully!\n");
    } else {
        // Print error message if the task list is full
        printf("Cannot add more tasks. Task list is full.\n");
    }
}

// Function to view all tasks in the list
void viewTasks() {
    // Check if there are no tasks in the list
    if (num_tasks == 0) {
        // Print message indicating no tasks
        printf("No tasks to display.\n");
    } else {
        // Print the list of tasks along with their completion status
        printf("Tasks:\n");
        for (int i = 0; i < num_tasks; i++) {
            printf("%d. [%s] %s\n", i + 1, tasks[i].completed ? "X" : " ", tasks[i].description);
        }
    }
}

// Function to mark a task as completed
void markCompleted(int index) {
    // Check if the index is valid
    if (index >= 1 && index <= num_tasks) {
        // Set the completed flag of the specified task to 1 (completed)
        tasks[index - 1].completed = 1;
        // Print success message
        printf("Task marked as completed!\n");
    } else {
        // Print error message for invalid index
        printf("Invalid task number.\n");
    }
}

// Function to delete a task from the list
void deleteTask(int index) {
    // Check if the index is valid
    if (index >= 1 && index <= num_tasks) {
        // Shift tasks to fill the gap left by the deleted task
        for (int i = index - 1; i < num_tasks - 1; i++) {
            strcpy(tasks[i].description, tasks[i + 1].description);
            tasks[i].completed = tasks[i + 1].completed;
        }
        // Decrement the number of tasks
        num_tasks--;
        // Print success message
        printf("Task deleted successfully!\n");
    } else {
        // Print error message for invalid index
        printf("Invalid task number.\n");
    }
}

// Main function
int main() {
    int choice;
    char description[MAX_LENGTH];

    // Display menu and handle user input until the user chooses to exit
    do {
        printf("\nTo-Do List Manager\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                getchar(); // Clear input buffer
                fgets(description, MAX_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0; // Remove trailing newline character
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                printf("Enter task number to mark as completed: ");
                scanf("%d", &choice);
                markCompleted(choice);
                break;
            case 4:
                printf("Enter task number to delete: ");
                scanf("%d", &choice);
                deleteTask(choice);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
