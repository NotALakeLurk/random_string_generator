#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

#include "userheader.h"

int main() {
    // Get the desired string length from user
    // 20 is the number of digits in ULLONG_MAX (overkill anyway)
    char line[20];
    unsigned int desired_length;

    // Ask the user
    fputs("Enter the desired length of your random string: ", stdout);
    // Loop until we receive a valid input
    for (;;) {
        // Return error if reached EOF?
        // NOTE: sizeof(line) only works because char is 1 byte
        //  C spec doesn't require 1 byte chars, so imma fix that
        if (!fgets(line, sizeof(line)/sizeof(*line), stdin)) {
            return -1; // Magic number >:(
        }
        
        // Validate input, break if valid
        // sscanf should return 1 integer
        //  and length should be less than max to prevent 'overflow' (we add 1)
        if (1 == sscanf(line, "%u", &desired_length) && desired_length < UINT_MAX) {
            break;
        }

        // Input is invalid, ask again
        fputs("Please enter a valid number: ", stdout);
    }
    
    // Generate the string and print 
    // Probably bad memory stuff here lol, but I threw this together real quick-like

    // Allocate *heap* memory for the output string
    char *buffer = malloc(sizeof(char) * (desired_length + 1));

    gen_string(buffer, desired_length + 1);
    printf("%s\n", buffer);

    // You don't neccessarily have to free(buffer), but for completeness sake ;)
    free(buffer); buffer = NULL;
}
