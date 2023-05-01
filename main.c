#include "main.h"

/**
 *main - Entry point
 *
 *Return: Always 0
 */
int main(void)
{
    int score = 0;
    int expected_score = 56;
    char *expected_output = "\x01\x02\x03\x04\x05\x06\x07\x01\x02\x03\x04\x05\x06\x07";
    char *output;

    // Test case 1
    output = _printf("%S", "No special character.");
    if (strcmp(output, "No special character.No special character.") == 0)
    {
        score += 14;
    }
    free(output);

    // Test case 2
    output = _printf("%S", "\n");
    if (strcmp(output, "\x0A\x0A") == 0)
    {
        score += 14;
    }
    free(output);

    // Test case 3
    output = _printf("%S", "\x01\x02\x03\x04\x05\x06\x07");
    if (strcmp(output, expected_output) == 0)
    {
        score += 14;
    }
    free(output);

    // Test case 4
    expected_output = "Could you print some non-prntable characters?\nSure:\x1F\x7F\x0A\nThanks!\n";
    output = _printf("Could you print some non-prntable characters?\n%S\nThanks!\n", "Sure:\x1F\x7F\n");
    if (strcmp(output, expected_output) == 0)
    {
        score += 14;
    }
    free(output);

    // Output final score
    printf("Final score: %d/%d\n", score, expected_score);

    return 0;
}
