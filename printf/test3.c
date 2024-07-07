#include <stdarg.h>
#include <stdio.h>

// Function to count the number of arguments based on a format string
int count_arguments(const char* format, ...) {
    va_list args;        // Declare a va_list variable
    int count = 0;       // Variable to store the count of arguments

    va_start(args, format);  // Initialize args to store the additional arguments

    const char* p = format;
    while (*p != '\0') {     // Iterate over each character in the format string
        switch (*p) {
            case 'd':  // Integer argument
                va_arg(args, int);
                count++;
                break;
            case 'f':  // Double argument
                va_arg(args, double);
                count++;
                break;
            case 'c':  // Char argument
                va_arg(args, int); // char is promoted to int in variadic functions
                count++;
                break;
            // Add more cases for other types if needed
        }
        p++;
    }

    va_end(args);  // Clean up the va_list
    return count;
}

int main() {
    // Example usage with a format string
    int count1 = count_arguments("dcdc", 10, 'A', 30, 'B');
    int count2 = count_arguments("fff", 1.1, 2.2);

    // Print the counts
    printf("Count of arguments: %d\n", count1);  // Output: 4
    printf("Count of arguments: %d\n", count2);  // Output: 3

    return 0;
}
