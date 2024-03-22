/* Create functions to prompt users for input data such as the number of days, periods per day, subjects, teachers, and constraints.
Validate user input to ensure it meets the required format and constraints.
Constraint Handling Module: */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes
int promptInt(const char* message);
bool validateInt(const char* input);
char* promptString(const char* message);
bool validateString(const char* input);

int main() {
    int numDays = promptInt("Enter the number of days: ");
    int periodsPerDay = promptInt("Enter the number of periods per day: ");
    int numSubjects = promptInt("Enter the number of subjects: ");
    int numTeachers = promptInt("Enter the number of teachers: ");
    
    // You can add more prompts for constraints if needed
    
    // Use the input data as needed
    printf("You entered %d days, %d periods per day, %d subjects, and %d teachers.\n", numDays, periodsPerDay, numSubjects, numTeachers);
    
    return 0;
}

// Function to prompt user for integer input.
int promptInt(const char* message) {
    int input;
    char buffer[100];
    bool isValid = false;

    do {
        printf("%s", message);
        fgets(buffer, sizeof(buffer), stdin);
        isValid = validateInt(buffer);
        if (!isValid) {
            printf("Invalid input. Please enter a valid integer.\n");
        } else {
            input = atoi(buffer);
        }
    } while (!isValid);

    return input;
}

// Function to validate integer input
bool validateInt(const char* input) {
    int i = 0;

    // Check if input is empty
    if (input[0] == '\n' || input[0] == '\0') {
        return false;
    }

    // Check if input contains only digits
    while (input[i] != '\0') {
        if (!isdigit(input[i])) {
            return false;
        }
        i++;
    }

    return true;
}

// Function to prompt user for string input
char* promptString(const char* message) {
    char buffer[100];
    bool isValid = false;

    do {
        printf("%s", message);
        fgets(buffer, sizeof(buffer), stdin);
        isValid = validateString(buffer);
        if (!isValid) {
            printf("Invalid input. Please enter a valid string.\n");
        }
    } while (!isValid);

    // Remove newline character if present
    if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
    }

    char* input = malloc(strlen(buffer) + 1);
    strcpy(input, buffer);

    return input;
}

// Function to validate string input
bool validateString(const char* input) {
    int i = 0;

    // Check if input is empty
    if (input[0] == '\n' || input[0] == '\0') {
        return false;
    }

    // Check if input contains only alphanumeric characters or spaces
    while (input[i] != '\0') {
        if (!isalnum(input[i]) && !isspace(input[i])) {
            return false;
        }
        i++;
    }

    return true;
}
