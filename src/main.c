#include <stdio.h>

#include "userheader.h"

int main() {
    // Get the desired string length from user
    char line[255];
    int desired_length;

    // Ask the user
    fputs("Enter the desired length of your random string: ", stdout);
    // Loop until we receive a valid input
    for (;;) {
        // Return error if reached EOF?
        if (!fgets(line, sizeof(line), stdin)) {
            return -1;
        }
        
        // Validate input, break if valid
        // sscanf should return 1 integer && length should be positive
        if (1 == sscanf(line, "%d", &desired_length) && desired_length > 0) {
            break;
        }

        // Input is invalid, ask again
        fputs("Please enter a valid number: ", stdout);
    }
    
    // Generate the string and print 
    // Probably bad memory stuff here lol, but I threw this together real quick-like
    char buffer[desired_length + 1];
    gen_string(buffer, desired_length + 1);
    printf("%s\n", buffer);
}
