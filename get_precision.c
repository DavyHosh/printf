#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the index in the format string.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision); /* Add parentheses here. */

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			/* Advance the index to read the width value from va_arg. */
			curr_i++;

			precision = va_arg(list, int);
			break;
		}
		else
		{
			/* Exit the loop if the character is not a digit or '*'. */
			break;
		}
	}

	*i = curr_i - 1;

	return (precision); /* Add parentheses here. */
}
