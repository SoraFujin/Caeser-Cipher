Caesar Cipher Implementation

A versatile and efficient implementation of the Caesar Cipher encryption algorithm in C, featuring multiple character set support and flexible encryption modes.
Features
🔐 Multiple Character Sets

    Alphabets Only: Traditional Caesar cipher (A-Z, a-z)

    Alphabets + Digits: Extended to include numbers (0-9)

    Printable ASCII: All printable characters (32-126)

    Full ASCII: Complete ASCII range (0-127)

🎛️ Encryption Modes

    STRICT: Maintains original case for alphabets

    IGNORE: Converts everything to lowercase

    INCLUDE: Handles case as per input

📁 File Support

    Read encryption messages from text files

    Handle large files efficiently

    Proper memory management

Installation
Prerequisites

    GCC compiler

    GNU Make

    Git

Building from Source
bash

# Clone the repository
git clone https://github.com/SoraFujin/Caeser-Cipher.git
cd Caeser-Cipher

# Build the project
make

Manual Compilation
bash

gcc -o caeser src/caeser.c -Iinclude -Wall -Wextra -std=c99

Usage
Basic Encryption/Decryption
bash

# Encrypt a message
./caeser -e -s 3 -c alphabets message.txt

# Decrypt a message  
./caeser -d -s 3 -c digits encrypted.txt

Command Line Options
text

-e, --encrypt    Encrypt the input file
-d, --decrypt    Decrypt the input file
-s, --shift      Shift value (default: 3)
-c, --charset    Character set: alphabets, digits, printable, full
-m, --mode       Mode: strict, ignore, include
-o, --output     Output file (default: stdout)

Examples
bash

# Encrypt with digits support
./caeser -e -s 5 -c digits -m strict input.txt -o encrypted.txt

# Decrypt printable ASCII
./caeser -d -s 7 -c printable encrypted.txt

# Quick encryption (uses defaults)
./caeser -e message.txt

Project Structure
text

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

API Reference
Core Functions
c

/* Read file content into memory */
int read_file(const char *file_path);

/* Shift a single character based on parameters */
char shift_char(char c, int shift, enum Mode mode, int decrypt, enum CharSet charset);

/* Process entire input string */
void caeser(char *input, char *output, int shift, enum Mode mode, int decrypt, enum CharSet charset);

Enums
c

enum Mode { STRICT, IGNORE, INCLUDE };
enum CharSet { ALPHABETS_ONLY, ALPHABETS_AND_DIGITS, FULL_ASCII, PRINTABLE_ASCII };

Examples
Sample Usage
c

// Encrypt a string
char *encrypted = malloc(strlen(input) + 1);
caeser(input, encrypted, 3, STRICT, 0, ALPHABETS_AND_DIGITS);

// Decrypt a string  
char *decrypted = malloc(strlen(encrypted) + 1);
caeser(encrypted, decrypted, 3, STRICT, 1, ALPHABETS_AND_DIGITS);

Testing

The implementation includes built-in testing that demonstrates all character sets:
bash

make test

This will run encryption and decryption on sample messages using all supported character sets.
Performance

    Efficient memory management with proper allocation/deallocation

    O(n) time complexity for encryption/decryption

    Handles large files with stream processing

    Minimal memory footprint

Security Notes

⚠️ Important: The Caesar cipher is a classical encryption method and is not secure for modern cryptographic purposes. This implementation is intended for:

    Educational purposes

    Understanding basic cryptography concepts

    Academic projects

    Learning C programming

Do not use for sensitive data encryption.
Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

    Fork the repository

    Create a feature branch (git checkout -b feature/amazing-feature)

    Commit your changes (git commit -m 'Add amazing feature')

    Push to the branch (git push origin feature/amazing-feature)

    Open a Pull Request

License

This project is licensed under the MIT License - see the LICENSE file for details.
Author

Ahmad - SoraFujin
Acknowledgments

    Inspired by classical cryptography techniques

    Built for educational purposes in C programming

    Thanks to the open source community for best practices

