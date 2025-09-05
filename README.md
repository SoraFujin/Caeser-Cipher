# Caesar Cipher Implementation
A versatile and efficient implementation of the Caesar Cipher encryption algorithm in C, featuring multiple character set support and flexible encryption modes.
Features

## Multiple Character Sets
	 Alphabets Only: Traditional Caesar cipher (A-Z, a-z)
	 Alphabets + Digits: Extended to include numbers (0-9)
	 Printable ASCII: All printable characters (32-126)
	 Full ASCII: Complete ASCII range (0-127)

## Encryption Modes
	STRICT: Maintains original case for alphabets
	IGNORE: Converts everything to lowercase
	INCLUDE: Handles case as per input

File Support
	`Read encryption messages from text files
	`Handle large files efficiently
	`Proper memory management

# Installation
## Prerequisites
	GCC compiler
	GNU Make
	Git

# Building from Source
bash
# Clone the repository
``` bash
git clone https://github.com/SoraFujin/Caeser-Cipher.git
cd Caeser-Cipher
```

# Manual Compilation
```bash
gcc -o caeser src/caeser.c -Iinclude -Wall -Wextra -std=c99
```

# Usage
Basic Encryption/Decryption
Project Structure
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
char shift_char(char c, int shift, enum Mode mode, int decrypt, enum CharSet charset);

/* Process entire input string */
void caeser(char *input, char *output, int shift, enum Mode mode, int decrypt, enum CharSet charset);
```
## Enums
```c
enum Mode { STRICT, IGNORE, INCLUDE };
enum CharSet { ALPHABETS_ONLY, ALPHABETS_AND_DIGITS, FULL_ASCII, PRINTABLE_ASCII };
```

# Examples
## Sample Usage
```c
// Encrypt a string
char *encrypted = malloc(strlen(input) + 1);
caeser(input, encrypted, 3, STRICT, 0, ALPHABETS_AND_DIGITS);

// Decrypt a string  
char *decrypted = malloc(strlen(encrypted) + 1);
caeser(encrypted, decrypted, 3, STRICT, 1, ALPHABETS_AND_DIGITS);
```

# Performance
	Efficient memory management with proper allocation/deallocation
	O(n) time complexity for encryption/decryption
	Handles large files with stream processing
	Minimal memory footprint

Security Notes

***Important: The Caesar cipher is a classical encryption method and is not secure for modern cryptographic purposes. This implementation is intended for:***
	`Educational purposes
	`Understanding basic cryptography concepts
	`Academic projects
	`Learning C programming
***Do not use for sensitive data encryption.***

# Author
Ahmad Diab
Acknowledgments
	`Inspired by classical cryptography techniques
	`Built for educational purposes in C programming
	`Thanks to the open source community for best practices
