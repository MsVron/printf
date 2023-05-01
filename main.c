#include "main.h"

/**
 *main - Entry point
 *
 *Return: Always 0
 */
int main(void)
	{
		int len;
		int len2;
		int score = 0;
		char _buffer[1024];
		char str[] = "No special character.";
		char str2[] = "\n";
		char str3[] = "\x01\x02\x03\x04\x05\x06\x07";
		char str4[] = "Sure:\x1F\x7F\n";
		char expected1[] = "No special character.No special character.";
		char expected2[] = "\x0A\x0A";
		char expected3[] = "\x01\x02\x03\x04\x05\x06\x07\x01\x02\x03\x04\x05\x06\x07";
		char expected4[] = "Could you print some non-prntable characters?\nSure:\x1F\x7F\x0A\nThanks!\n";

		/*Test case 1 */
		len = _printf("%S", "No special character.");
		len2 = sprintf(_buffer, "%s", "No special character.No special character.");
		if (len != len2 || strcmp(_buffer, expected1) != 0)
		{
			printf("Correct output - case: _printf(\"%%S\", \"No special character.\");\n\n");
			printf("Score: %d out of 14 points\n\n", score);
			printf("Reason:\n");
			printf("msg -[Got]\n%S%s\n", "No special character.", _buffer);
			printf("Lengths differ.\n\n");
			return (0);
		}

		score += 4;

		/*Test case 2 */
		len = _printf("%S", "\n");
		len2 = sprintf(_buffer, "%s", "\x0A\x0A");
		if (len != len2 || strcmp(_buffer, expected2) != 0)
		{
			printf("Correct output - case: _printf(\"%%S\", \"\\n\");\n\n");
			printf("Score: %d out of 14 points\n\n", score);
			printf("Reason:\n");
			printf("msg -[Got]\n%S%s\n", "\n", _buffer);
			printf("Lengths differ.\n\n");
			return (0);
		}

		score += 4;

		/*Test case 3 */
		len = _printf("%S", "\x01\x02\x03\x04\x05\x06\x07");
		len2 = sprintf(_buffer, "%s", "\x01\x02\x03\x04\x05\x06\x07\x01\x02\x03\x04\x05\x06\x07");
		if (len != len2 || strcmp(_buffer, expected3) != 0)
		{
			printf("Correct output - case: _printf(\"%%S\", \"\\x01\\x02\\x03\\x04\\x05\\x06\\x07\");\n\n");
			printf("Score: %d out of 14 points\n\n", score);
			printf("Reason:\n");
			printf("msg -[Got]\n%S%s\n", "\x01\x02\x03\x04\x05\x06\x07", _buffer);
			printf("Lengths differ.\n\n");
			return (0);
		}

		score += 4;

		/*Test case 4 */
		len = _printf("Could you print some non
			/*Test case 4 */
			len = _printf("Could you print some non-prntable characters?\n%S\nThanks!\n", "Sure:\x1F\x7F\n"); len2 = sprintf(_buffer, "%s", "Could you print some non-prntable characters?\nSure:\x1F\x7F\nThanks!\n");
			if (len != len2 || strcmp(_buffer, expected4) != 0)
			{
				printf("Correct output - case: _printf("
					Could you print some non - prntable characters ? \n % % S\ nThanks!\n ", "
					Sure : \x1F\ x7F\ n ");\n\n");
				printf("Score: %d out of 14 points\n\n", score);
				printf("Reason:\n");
				printf("msg -[Got]\n%s%S%s\n", "Could you print some non-prntable characters?\n", "Sure:\x1F\x7F\x0A", "\nThanks!\n");
				printf("Lengths differ.\n\n");
				return (0);
			}

			score += 2; printf("Score: %d out of 14 points\n\n", score);
			return (0);
		}
