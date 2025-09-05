# Caesar Cipher Implementation
A versatile and efficient implementation of the Caesar Cipher encryption algorithm in C, featuring multiple character set support and flexible encryption modes.
Features

## Encryption Modes
	STRICT: Maintains original case for alphabets
	IGNORE: Converts everything to lowercase
	INCLUDE: Handles case as per input

File Support
	`Read encryption messages from text files`<br>
	`Handle large files efficiently`<br>
	`Proper memory management`<br>

# Installation
## Prerequisites
	GCC compiler
	GNU Make
	Git

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

## Project Structure
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
	Efficient memory management with proper allocation/deallocation
	O(n) time complexity for encryption/decryption
	Handles large files with stream processing
	Minimal memory footprint

# Security Notes
***Important: The Caesar cipher is a classical encryption method and is not secure for modern cryptographic purposes. This implementation is intended for:***
	`Educational purposes`
	`Understanding basic cryptography concepts`
	`Academic projects`
	`Learning C programming`
***Do not use for sensitive data encryption.***
---

# Author
**Ahmad Diab**
Acknowledgments
	`Inspired by classical cryptography techniques`<br>
	`Built for educational purposes in C programming`<br>
	`Thanks to the open source community for best practices`<br>

