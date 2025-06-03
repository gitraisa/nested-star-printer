#include <stdio.h>

// Function to get a valid integer input with prompt
int get_valid_input(const char *prompt) {
    int value;
    int result;
    do {
        printf("%s", prompt);
        result = scanf("%d", &value);
        while(getchar() != '\n'); // clear input buffer
        if(result != 1) {
            printf("Invalid input. Please enter an integer.\n");
        }
    } while(result != 1);
    return value;
}

// Function to get start and end values with validation (start < end)
void get_range(const char *var_name, int *start, int *end) {
    do {
        *start = get_valid_input("Enter start value for ");
        printf("%s", var_name);
        *end = get_valid_input("Enter end value for ");
        if (*start >= *end) {
            printf("Invalid range. Start value must be less than end value. Please try again.\n");
        }
    } while (*start >= *end);
}

// Function to print stars in color
void print_stars(int count, const char *color_code) {
    printf("%s", color_code); // set color
    for (int i = 0; i < count; i++) {
        printf("*");
    }
    printf("\033[0m"); // reset color
}

int main(void) {
    int i_start, i_end;
    int j_start, j_end;
    int k_start, k_end;

    printf("Welcome to the Nested Stars Printer!\n");

    // Get validated ranges for i, j, and k
    do {
        printf("For variable i:\n");
        i_start = get_valid_input("  Enter start value: ");
        i_end = get_valid_input("  Enter end value: ");
        if (i_start >= i_end)
            printf("  Invalid range for i. Start must be less than end.\n");
    } while (i_start >= i_end);

    do {
        printf("For variable j:\n");
        j_start = get_valid_input("  Enter start value: ");
        j_end = get_valid_input("  Enter end value: ");
        if (j_start >= j_end)
            printf("  Invalid range for j. Start must be less than end.\n");
    } while (j_start >= j_end);

    do {
        printf("For variable k:\n");
        k_start = get_valid_input("  Enter start value: ");
        k_end = get_valid_input("  Enter end value: ");
        if (k_start >= k_end)
            printf("  Invalid range for k. Start must be less than end.\n");
    } while (k_start >= k_end);

    printf("\nPrinting stars with ranges:\n\n");

    // Outer loop - i
    for (int i = i_start; i < i_end; i++) {
        printf("i = %d\n", i);
        // Middle loop - j
        for (int j = j_start; j < j_end; j++) {
            printf("  j = %d: ", j);
            // Inner loop - k: print stars in green color
            print_stars(k_end - k_start, "\033[0;32m");
            printf("\n");
        }
        printf("\n");
    }

    printf("Done printing stars. Thanks for using the program!\n");

    return 0;
}
