#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>

//Shifts a single character forward by n positions in the alphabet.
// Preserves case; non-letters (spaces, punctuation, digits) pass through unchanged.
char encryptChar(char c, int n) {
    if (c >= 'A' && c <= 'Z') {
        /* (c - 'A') Converts the letter to a 0-25 position.
         + n applies the shift, then % 26 warps around the alphabet
         The extra "+ 26) % 26" handles negative shifts safely, since
         C++'s % operator can produce negative results for negative operands. */
        return ((c - 'A' + n) % 26 + 26) % 26 + 'A';
    }
    else if (c >= 'a' && c <= 'z') {
        // Same logic, but anchored to 'a' so the output stays lowercase
        return ((c - 'a' + n) % 26 + 26) % 26 + 'a';
    }
    else {
        // Not a letter - leave it alone (spaces, commas, digits, ETC.).
        return c;
    }
}

// Reverse of encryptChar": Shifts a character backward by n positions.
char decryptChar(char c, int n) {
    if (c >= 'A' && c <= 'Z') {
        // + 26 before % 26 keeps the value non-negative after subtracting n.
        return ((c - 'A' - n + 26) % 26) + 'A';
    }
    else if (c >= 'a' && c <= 'z') {
        return ((c - 'a' - n + 26) % 26) + 'a';
    }
    else {
        return c;
    }
}

int main() {
    int K {};                   // Shift amount (the cipher key)
    std::string text;           // The message to transform
    std::string mode;           // "Encryption" or "Decryption" selection

    std::cout << "Would you like to Encrypt or Decrypt? ";
    std::cin >> mode;

    /* cin >> leaves the trailing newline in the buffer, which would cause
    the next getline() to immediately return an empty string. This line
    discards everything up to and including that newline so getline works. */

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter text: ";
    std::getline(std::cin, text); // Getline so spaces in the message are preserved

    std::cout << "Enter shift amount: ";
    std::cin >> K;

    // Convert mode to lowercase so the comparison is case-insensitive
    std::transform(mode.begin(), mode.end(), mode.begin(), ::tolower);

    if (mode == "Encrypt" || mode == "e") {
        /* The & makes ch a reference to each character in text, so assignments
        modify the string in place rather than just modifying a local copy*/
        for (char& ch : text) {
            ch = encryptChar(ch, K);
        }
        std::cout << "Encrypted text: " << text << '\n';
    }
    else if (mode == "Decrypt" || mode == "d") {
        for (char& ch : text) {
            ch = decryptChar(ch, K);
        }
        std::cout << "Decrypted text: " << text << '\n';
    }
    else {
        // User types something other than "Encrypt" or "Decrypt".
        // Returning 1 signals an error exit code to the OS.
        std::cout << "Unknown mode: " << mode << '\n';
        return 1;
    }
    return 0;
}