#ifndef CAESER_H
#define CAESER_H
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

enum Mode {
    STRICT,
    IGNORE,
    INCLUDE
};

enum CharSet {
    ALPHABETS_ONLY,       // Only alphabets (A-Z, a-z)
    ALPHABETS_AND_DIGITS, // Alphabets and digits (A-Z, a-z, 0-9)
    FULL_ASCII,           // All ASCII characters (0-127)
    PRINTABLE_ASCII       // Printable ASCII characters (32-126)
};

// Function declarations
int read_file(const char *file_path);
char shift_char(char c, int shift, enum Mode mode, int decrypt, enum CharSet charset);
void caeser(char *input, char *output, int shift, enum Mode mode, int decrypt, enum CharSet charset);

#endif
