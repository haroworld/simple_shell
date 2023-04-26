#include "shell.h"

/**
 * interactive - if shell is interactive mode return true
 * @info: struct
 *
 * Return: if interactive mode 1, otherwise 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - if character is a delimeter
 * @c: charavter to check
 * @delim: delim string
 * Return: 1 if true, if false 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - alphabetic character check
 *@c: input character
 *Return: if c is alphabetic return 1, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - program to converts a string to an integer
 *@s: string to be converted
 *Return: if no numbers in string return 0, converted number otherwise
 */

int _atoi(char *s)
{
	int x, signage = 1, flagcheck = 0, output;
	unsigned int result = 0;

	for (x = 0;  s[x] != '\0' && flagcheck != 2; x++)
	{
		if (s[x] == '-')
			signage *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flagcheck = 1;
			result *= 10;
			result += (s[x] - '0');
		}
		else if (flagcheck == 1)
			flagcheck = 2;
	}

	if (signage == -1)
		output = -result;
	else
		output = result;

	return (output);
}
