#include "../include/caeser.h"

size_t length;
char* message;
char* encrypted_buffer;
char* decrypted_buffer;
int shift = 1;

int read_file(const char *file_path)
{
    FILE *file = fopen(file_path, "r");
    if(!file) {
        fprintf(stderr, "Error opening file %s: %s", file_path, strerror(errno));
        return -1;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    rewind(file);

    message = malloc(length + 1);
    if(!message) {
        fprintf(stderr, "[Error] allocating memory for message: %s", strerror(errno));
        fclose(file);
        return -1;
    }
    fread(message, 1, length, file);
    message[length] = '\0';

    fclose(file);
    return 0;
}

char shift_char(char c, int shift, enum Mode mode, int decrypt, enum CharSet charset) {
    if (decrypt) {
        shift = -shift;
    }

    unsigned char uc = (unsigned char)c;

    switch (charset) {
        case ALPHABETS_ONLY:
            if((uc >= 'a' && uc <= 'z') || (uc >= 'A' && uc <= 'Z')) {
                int is_upper = (uc >= 'A' && uc <= 'Z');
                char lower = tolower(uc);
                int index = (lower - 'a' + shift + 26) % 26;

                if(mode == STRICT)
                    return is_upper ? index + 'A' : index + 'a';
                if(mode == IGNORE)
                    return index + 'a';
                if(mode == INCLUDE)
                    return is_upper ? index + 'A' : index + 'a';
            }
            break;

        case ALPHABETS_AND_DIGITS:
            if((uc >= 'a' && uc <= 'z') || (uc >= 'A' && uc <= 'Z')) {
                int is_upper = (uc >= 'A' && uc <= 'Z');
                char lower = tolower(uc);
                int index = (lower - 'a' + shift + 26) % 26;

                if(mode == STRICT)
                    return is_upper ? index + 'A' : index + 'a';
                if(mode == IGNORE)
                    return index + 'a';
                if(mode == INCLUDE)
                    return is_upper ? index + 'A' : index + 'a';
            }
            else if (uc >= '0' && uc <= '9') {
                int index = (uc - '0' + shift + 10) % 10;
                return index + '0';
            }
            break;

        case FULL_ASCII:
            if (uc <= 127) {
                int index = (uc + shift + 128) % 128;
                return (char)index;
            }
            break;

        case PRINTABLE_ASCII:
            if (uc >= 32 && uc <= 126) {
                int index = (uc - 32 + shift + 95) % 95;
                return index + 32;
            }
            break;
    }
    
    return c;
}

void caeser(char *input, char *output, int shift, enum Mode mode, int decrypt, enum CharSet charset) {
    for(size_t i = 0; i < length; i++) {
        output[i] = shift_char(input[i], shift, mode, decrypt, charset);
    }
    output[length] = '\0';
}

void print_char_set_info(enum CharSet charset) {
    switch (charset) {
        case ALPHABETS_ONLY:
            printf("Character Set: Alphabets only (A-Z, a-z)\n");
            break;
        case ALPHABETS_AND_DIGITS:
            printf("Character Set: Alphabets and digits (A-Z, a-z, 0-9)\n");
            break;
        case FULL_ASCII:
            printf("Character Set: Full ASCII (0-127)\n");
            break;
        case PRINTABLE_ASCII:
            printf("Character Set: Printable ASCII (32-126)\n");
            break;
    }
}

int main() 
{
    if (read_file("/home/ahmad/Projects/Encryption/Caeser/src/message.txt") != 0) {
        return 1;
    }
    
    printf("Original message: %s\n\n", message);

    enum CharSet charsets[] = {ALPHABETS_ONLY, ALPHABETS_AND_DIGITS, PRINTABLE_ASCII, FULL_ASCII};
    const char* charset_names[] = {"Alphabets Only", "Alphabets + Digits", "Printable ASCII", "Full ASCII"};
    
    for (int i = 0; i < 4; i++) {
        printf("=== %s ===\n", charset_names[i]);
        print_char_set_info(charsets[i]);
        
        encrypted_buffer = malloc(length + 1);
        caeser(message, encrypted_buffer, shift, IGNORE, 0, charsets[i]);
        printf("Encrypted: %s\n", encrypted_buffer); 

        decrypted_buffer = malloc(length + 1);
        caeser(encrypted_buffer, decrypted_buffer, shift, IGNORE, 1, charsets[i]);
        printf("Decrypted: %s\n\n", decrypted_buffer); 

        free(encrypted_buffer);
        free(decrypted_buffer);
    }

    free(message);
    return 0;
}
