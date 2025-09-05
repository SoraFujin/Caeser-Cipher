# Caesar Cipher Implementation
A versatile and efficient implementation of the Caesar Cipher encryption algorithm in C, featuring flexible encryption modes.

# Encryption Modes
1. STRICT: Maintains original case for alphabets
2. IGNORE: Converts everything to lowercase
3. INCLUDE: Handles case as per input

# File Support
1. Read encryption messages from text files
2. Handle large files efficiently
3. Proper memory management

# Installation
## Prerequisites
1. GCC compiler
2. Git

## Clone the repository
``` bash
git clone https://github.com/SoraFujin/Caeser-Cipher.git
cd Caeser-Cipher
```

## Manual Compilation
```bash
gcc -o caeser src/caeser.c -Iinclude -Wall -Wextra -std=c99
```

# Project Structure
```text
Caeser-Cipher/
├── include/
│   └── caeser.h          # Header file with enums and declarations
├── src/
│   └── caeser.c          # Main implementation file
├── messages/
│   └── message.txt       # Sample message file
├── Makefile              # Build configuration
├── LICENSE               # MIT License
└── README.md             # This file
```

# API Reference
## Core Functions
```c
/* Read file content into memory */
int read_file(const char *file_path);

/* Shift a single character based on parameters */
char shift_char(char c, int shift, enum Mode mode, int decrypt);

/* Process entire input string */
void caeser(char *input, char *output, int shift, enum Mode mode, int decrypt);
```
## Enums
```c
enum Mode { STRICT, IGNORE, INCLUDE };
```

# Examples
## Sample Usage
```c
// Encrypt a string
char *encrypted = malloc(strlen(input) + 1);
caeser(input, encrypted, 3, STRICT, 0);

// Decrypt a string  
char *decrypted = malloc(strlen(encrypted) + 1);
caeser(encrypted, decrypted, 3, STRICT, 1);
```

# Performance
- Efficient memory management with proper allocation/deallocation
- O(n) time complexity for encryption/decryption
- Handles large files with stream processing
- Minimal memory footprint

# Security Notes
***Important: The Caesar cipher is a classical encryption method and is not secure for modern cryptographic purposes. This implementation is intended for:***
1. Educational purposes
2. Understanding basic cryptography concepts
3. Academic projects
4. Learning C programming
<br>
***Do not use for sensitive data encryption.***
---

# Author
**Ahmad Diab**
Acknowledgments
1. Inspired by classical cryptography techniques
2. Built for educational purposes in C programming

