#include <stddef.h>
#include <sys/random.h>

#include "userheader.h"

/// Generate a random ascii character inclusively bound by %32 and %126
/// Could be more optimized
char gen_random_char() {
    const int UPPER_BOUND = '~' + 1; // Upper-bound is exclusive
    const int LOWER_BOUND = ' ';
    
    // 'Buffer' for single random int
    int random_number;
    // Generate a random number (Linux specific?)
    getrandom(&random_number, 1, GRND_RANDOM);

    // Constrain random_number to bounds (inclusive)
    random_number = (random_number % (UPPER_BOUND - LOWER_BOUND)) + LOWER_BOUND;

    return (char)random_number;
}

// TODO: fix inconsistency with file-name and function-name
// Might want to eventually account for some errors with a return enum
void gen_string(char buffer[], size_t GEN_LENGTH) {
    // Generate the contents of the string
   for (size_t i = 0; i < GEN_LENGTH - 1; i++) {
       buffer[i] = gen_random_char();
   }

   // Null-terminate the string
   buffer[GEN_LENGTH - 1] = '\0';
}
