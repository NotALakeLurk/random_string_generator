#include <stdio.h>

#include "userheader.h"

int main() {
    char line[255];
    // Get the desired length from the user
    int desired_length;

    fputs("Enter the desired length of your random string: ", stdout);

    for (;;) {
        if (!fgets(line, sizeof(line), stdin)) {
            return -1;
        }
        
        if (1 == sscanf(line, "%d", &desired_length) && desired_length > 0) {
            break;
        }

        fputs("Please enter a valid number: ", stdout);
    }
    
    // Generate the string and print 
    char buffer[desired_length + 1];
    gen_string(buffer, desired_length + 1);
    printf("%s\n", buffer);
}
