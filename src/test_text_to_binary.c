#include "text_to_binary.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Test the textToBinary and binaryToHex functions.
 */
int main() {
  // Test input string
  const char *testString = "PHP sucks";

  // Convert the text to binary
  printf("=== Testing textToBinary ===\n");
  char *binary = textToBinary(testString);
  if (binary == NULL) {
    printf("Error: Memory allocation failed or invalid input.\n");
    return 1;
  }

  // Print the binary representation
  printf("\nBinary representation of '%s':\n%s\n", testString, binary);

  // Convert the binary to hexadecimal
  printf("\n=== Testing binaryToHex ===\n");
  char *hex = binaryToHex(binary);
  if (hex == NULL) {
    printf("Error: Conversion to hexadecimal failed.\n");
    free(binary);
    return 1;
  }

  // Print the hexadecimal representation
  printf("\nHexadecimal representation of binary:\n%s\n", hex);

  // Free the dynamically allocated memory
  free(binary);
  free(hex);

  return 0;
}
