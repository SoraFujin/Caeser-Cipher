#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Please provide the file path with the number of shifts\n");
        printf("Usage: %s <file-path> <number-of-shifts>\n", argv[0]);
        return 1;
    }

    int shift = strtol(argv[2], NULL, 10);  // base 10
    char *file_path = argv[1];
    FILE *file = fopen(file_path, "rb");
    if(file == NULL) {
        perror("Error opening file");
        return -1;
    }

    fseek(file, 0, SEEK_END); // Move the pointer to the end of the file
    size_t length = ftell(file); // Get the position inside the file 
    rewind(file); // Reset the position to the start of the file.

    char *buffer = malloc(length + 1); // Create a buffer to save the data inside
    if(!buffer) {
        perror("Error allocating memory for buffer");
        fclose(file);
        return -1;
    }

    fread(buffer, 1, length, file); //Read the data from the file and save it inside the buffer
    buffer[length] = '\0';
    fclose(file);

    printf("Data inside the file: %s\n", buffer);

    // A != a, strict mode so it encrypt it differently
    char *encBuffer = malloc(length + 1);
    for(size_t i = 0; i < length; i++) {
        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
            encBuffer[i] = ((buffer[i] - 'a' + shift) % 26) + 'a';
        } else if (buffer[i] <= 'A' && buffer[i] >= 'Z') {
            encBuffer[i] = ((buffer[i] - 'A' + shift) % 26) + 'A';
        } else {
            encBuffer[i] = buffer[i];
        }
    }
    encBuffer[length] = '\0';

    char *decBuffer = malloc(length + 1);
    for(size_t i = 0; i < length; i++) {
        /*
         *
         * encBuffer = 72 // H
         * A = 65
         * 72 + 65 = 137
         * 137 - 25 =  112
         * 112 % 26 = 8
         * 8 + 65 = 73
         *
         * */
        if(encBuffer[i] >= 'a' && encBuffer[i] <= 'z'){
            decBuffer[i] = ((encBuffer[i] + 'a' - shift + 26) % 26) + 'a';
        } else if (encBuffer[i] >= 'A' && encBuffer[i] <= 'Z') {
            decBuffer[i] = ((encBuffer[i] + 'A' - shift + 26) % 26) + 'A';
        } else {
            decBuffer[i] = encBuffer[i];
        }
    }
    decBuffer[length] = '\0';

    printf("encrypted buffer: %s\n", encBuffer); 
    printf("decrypted buffer: %s\n", decBuffer); 

    return 0;
}
