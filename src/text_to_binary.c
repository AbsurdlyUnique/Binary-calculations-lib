#include "text_to_binary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Converts a text string into a binary representation and explains each step clearly.
 *
 * @param text The input text string.
 * @return A dynamically allocated binary string representation of the text.
 *         The caller is responsible for freeing the memory.
 */
char* textToBinary(const char* text) {
    if (text == NULL) {
        return NULL;
    }

    size_t length = strlen(text);

    // Allocate memory for the binary string
    char* binary = malloc(length * 8 + 1);
    if (binary == NULL) {
        return NULL;
    }

    binary[0] = '\0'; // Initialize the binary string

    // Convert each character to binary
    for (size_t i = 0; i < length; ++i) {
        char bin[9]; // Temporary storage for one character's binary
        printf("\nConverting '%c' (ASCII: %d):\n", text[i], text[i]);

        // Explain the process of determining each binary digit
        for (int bit = 7; bit >= 0; --bit) {
            int shifted = text[i] >> bit; // Divide the number by 2^bit
            int result = shifted & 1;    // Check if the remainder is 1 or 0

            // Simple output for non-technical users
            printf("  Is %d big enough to include %d? %s\n",
                   text[i], 1 << bit, (result ? "Yes, so the bit is 1" : "No, so the bit is 0"));

            bin[7 - bit] = result ? '1' : '0'; // Store the bit as '1' or '0'
        }

        bin[8] = '\0'; // End the binary string for this character
        printf("  Binary for '%c': %s\n", text[i], bin);

        strcat(binary, bin); // Add this binary value to the final result
    }

    printf("\nFinal Binary String for the whole text: %s\n", binary);
    return binary;
}

/**
 * Converts a binary string into a hexadecimal representation and explains each step clearly.
 *
 * @param binary The input binary string.
 * @return A dynamically allocated hexadecimal string representation of the binary string.
 *         The caller is responsible for freeing the memory.
 */
char* binaryToHex(const char* binary) {
    if (binary == NULL || strlen(binary) % 4 != 0) {
        printf("Error: Binary string is either NULL or not a multiple of 4.\n");
        return NULL;
    }

    size_t binaryLength = strlen(binary);
    size_t hexLength = binaryLength / 4;

    // Allocate memory for the hex string
    char* hex = malloc(hexLength + 1);
    if (hex == NULL) {
        return NULL;
    }

    // Explain how binary is converted to hexadecimal
    for (size_t i = 0; i < hexLength; ++i) {
        char nibble[5];
        strncpy(nibble, binary + i * 4, 4); // Take 4 bits (one nibble)
        nibble[4] = '\0'; // End the nibble string

        printf("\nConverting Nibble: %s\n", nibble);

        // Convert the nibble to a number and explain
        int value = 0;
        for (int j = 0; j < 4; ++j) {
            int bitValue = nibble[j] - '0'; // Convert '0' or '1' to a number
            int multiplier = 1 << (3 - j); // Equivalent to 2^(3-j)
            int addition = bitValue * multiplier;

            printf("  For bit %d (%c): %d x %d = %d\n",
                   j + 1, nibble[j], bitValue, multiplier, addition);

            value += addition; // Add the calculated value
        }

        // Convert the value to hexadecimal
        hex[i] = (value < 10) ? ('0' + value) : ('A' + value - 10);
        printf("  Hexadecimal Character: %c\n", hex[i]);
    }

    hex[hexLength] = '\0'; // End the hexadecimal string
    printf("\nFinal Hexadecimal String: %s\n", hex);

    return hex;
}
