#include "../include/caeser.h"

size_t length;
char* message;
char* encrypted_buffer;
char* decrypted_buffer;
int shift = 1;

int read_file(const char *file_path)
{
    FILE *file = fopen(file_path, "rw");
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
    }
    fread(message, 1, length, file);
    message[length] = '\0';

    return 0;
}

char shift_char(char c, int shift, enum Mode mode, int decrypt) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        int is_upper = (c >= 'A' && c <= 'Z');

        char lower = tolower(c);

        if(decrypt) shift = -shift;

        int index = (lower - 'a' + shift + 26) % 26;

        if(mode == STRICT)
            return is_upper ? index + 'A' : index + 'a';
        if(mode == IGNORE)
            return index + 'a';
        if(mode == INCLUDE)
            return is_upper ? index + 'A' : index + 'a';
    }
    return c;
}

char check_digit() 
{
    return 0;
}

void caeser(char *input, char *output, int shift, enum Mode mode, int decrypt) {
    for(size_t i = 0; i < length; i++) {
        output[i] = shift_char(input[i], shift, mode, decrypt);
    }
    output[length] = '\0';
}

int main() 
{
    read_file("/home/ahmad/Projects/Encryption/Caeser/src/message.txt");
    encrypted_buffer = malloc(length + 1);
    caeser(message, encrypted_buffer, shift, IGNORE, 0); // encrypt
    printf("Message Encrypted strict mode: %s\n", encrypted_buffer); 

    decrypted_buffer = malloc(length + 1);
    caeser(encrypted_buffer, decrypted_buffer, shift, IGNORE, 1); // decrypt
    printf("Message Decrypted: %s\n", decrypted_buffer); 

    return 0;
}
