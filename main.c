#include "main.h"

/**
 *main - Entry point
 *
 *Return: Always 0
 */

int main(void)
{
    int score = 0;
    char *output;

    /* Test case 1 */
    output = _printf("%S", "No special character.");
    if (output == NULL)
        score += 14;
    else if (strcmp(output, "No special character.No special character.") == 0)
        score += 14;
    printf("Score: %d out of 14 points\n\n", score);
    
    /* Test case 2 */
    output = _printf("%S", "\n");
    if (output == NULL)
        score += 14;
    else if (strcmp(output, "\x0A\x0A") == 0)
        score += 14;
    printf("Score: %d out of 14 points\n\n", score);

    /* Test case 3 */
    output = _printf("%S", "\x01\x02\x03\x04\x05\x06\x07");
    if (output == NULL)
        score += 14;
    else if (strcmp(output, "\x01\x02\x03\x04\x05\x06\x07\x01\x02\x03\x04\x05\x06\x07") == 0)
        score += 14;
    printf("Score: %d out of 14 points\n\n", score);

    /* Test case 4 */
    output = _printf("Could you print some non-prntable characters?\n%S\nThanks!\n", "Sure:\x1F\x7F\n");
    if (output == NULL)
        score += 14;
    else if (strcmp(output, "Could you print some non-prntable characters?\nSure:\x1F\x7F\x0A\nThanks!\n") == 0)
        score += 14;
    printf("Score: %d out of 14 points\n\n", score);

    return (score);
}
