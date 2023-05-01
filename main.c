#include "main.h"

/**
 *main - Entry point
 *
 *Return: Always 0
 */
#include <stdio.h>

int main() {
    printf("Test case 1:\n");
    printf("Expected output: No special character.No special character.\n");
    _printf("%S", "No special character.");
    
    printf("\nTest case 2:\n");
    printf("Expected output: \\x0A\\x0A\n");
    _printf("%S", "\n");
    
    printf("\nTest case 3:\n");
    printf("Expected output: \\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x01\\x02\\x03\\x04\\x05\\x06\\x07\n");
    _printf("%S", "\x01\x02\x03\x04\x05\x06\x07");
    
    printf("\nTest case 4:\n");
    printf("Expected output: Could you print some non-prntable characters?\nSure:\\x1F\\x7F\\x0A\nThanks!\n");
    _printf("Could you print some non-prntable characters?\n%S\nThanks!\n", "Sure:\x1F\x7F\n");
    
    printf("\nTest case 5:\n");
    printf("Expected output: - What did you say?\n- \n- That's what I thought.\n");
    _printf("- What did you say?\n- %S\n- That's what I thought.\n", "");

    return 0;
}
