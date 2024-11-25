#ifndef TEXT_TO_BINARY_H
#define TEXT_TO_BINARY_H

/**
 * Public API for the text_to_binary library.
 * Provides functionality to convert text strings into binary representations
 * and binary strings into hexadecimal representations.
 */

/**
 * Converts a text string into a binary representation.
 *
 * Each character in the input text string is converted into its
 * corresponding 8-bit binary representation, and the binary values
 * are concatenated into a single string.
 *
 * @param text The input text string (null-terminated).
 * @return A dynamically allocated binary string representation of the text.
 *         The caller is responsible for freeing the allocated memory.
 *         Returns NULL if the input is NULL or memory allocation fails.
 */
char *textToBinary(const char *text);

/**
 * Converts a binary string into a hexadecimal representation.
 *
 * The binary string must have a length that is a multiple of 4,
 * as each 4 bits (a nibble) corresponds to one hexadecimal digit.
 * For example, "01001000" (binary) becomes "48" (hexadecimal).
 *
 * @param binary The input binary string (null-terminated).
 * @return A dynamically allocated hexadecimal string representation
 *         of the binary string. The caller is responsible for freeing
 *         the allocated memory. Returns NULL if the input is NULL,
 *         the length is not a multiple of 4, or memory allocation fails.
 */
char *binaryToHex(const char *binary);

#endif // TEXT_TO_BINARY_H
