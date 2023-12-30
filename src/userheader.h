#ifndef USERHEADER_DOT_H
#define USERHEADER_DOT_H

#include <stddef.h>

/// Takes an input length and generates a null-terminated string
///     that has the same length (usable characters will be one less than input)
///
/// param buffer: the buffer to write the resulting string to
///
/// param GEN_LENGTH: the length of the string to generate 
///     * Remember to account for the null terminator
///
/// # Example:
/// ```
///     char buffer[10];
///     gen_string(buffer, 10);
///     printf("%s", buffer) // Prints result of `gen_string`
/// ```
void gen_string(char buffer[], size_t GEN_LENGTH);

#endif /* USERHEADER_DOT_H */
