#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 *main - Entry point
 *
 *Return: Always 0
 */
int main(void)
{
    char *str1 = "No special character.";
    char *str2 = "\n";
    char *str3 = "\x01\x02\x03\x04\x05\x06\x07";
    char *str4 = "Sure:\x1F\x7F\n";
    char *str5 = "";

    printf("Testing case: _printf(\"%%S\", \"No special character.\");\n");
    printf("Expected output: No special character.\n");
    printf("Got output: ");
    print_string(str1);
    printf("\n\n");

    printf("Testing case: _printf(\"%%S\", \"\\n\");\n");
    printf("Expected output: \\x0A\\x0A\n");
    printf("Got output: ");
    print_string(str2);
    printf("\n\n");

    printf("Testing case: _printf(\"%%S\", \"\\x01\\x02\\x03\\x04\\x05\\x06\\x07\");\n");
    printf("Expected output: \\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x01\\x02\\x03\\x04\\x05\\x06\\x07\n");
    printf("Got output: ");
    print_string(str3);
    printf("\n\n");

    printf("Testing case: _printf(\"Could you print some non-prntable characters?\\n%%S\\nThanks!\\n\", \"Sure:\\x1F\\x7F\\n\");\n");
    printf("Expected output: Could you print some non-prntable characters?\nSure:\\x1F\\x7F\\x0A\nThanks!\n");
    printf("Got output: ");
    print_string(str4);
    printf("\n\n");

    printf("Testing case: _printf(\"- What did you say?\\n- %%S\\n- That's what I thought.\\n\", \"\");\n");
    printf("Expected output: - What did you say?\n-\n- That's what I thought.\n");
    printf("Got output: ");
    print_string(str5);
    printf("\n\n");

    return (0);
}
