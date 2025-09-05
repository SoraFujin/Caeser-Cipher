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

// Function declarations
int read_file(const char *file_path);
char shift_char(char c, int shift, enum Mode mode, int decrypt);
void caeser(char *input, char *output, int shift, enum Mode mode, int decrypt);

#endif
