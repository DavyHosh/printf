#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing the directives
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	printed_chars = handle_print(format, args);
	va_end(args);

	return (printed_chars);
}

/**
 * handle_print - Handles the format string and prints accordingly
 * @format: Format string containing the directives
 * @args: List of arguments
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int handle_print(const char *format, va_list args)
{
	int i = 0, printed_chars = 0;
	char buffer[BUFFER_SIZE] = {0}; /* BUFFER_SIZE is a defined constant */

	if (format == NULL)
		return (-1);

	while (format[i])
	{
		if (format[i] != '%')
		{
			printed_chars += _putchar(format[i]);
			i++;
			continue;
		}

		i++;

		switch (format[i])
		{
			case 'c':
				printed_chars += _putchar(va_arg(args, int));
				break;
			case 's':
				printed_chars += _puts(va_arg(args, char *));
				break;
			case '%':
				printed_chars += _putchar('%');
				break;
			default:
				printed_chars += _putchar('%');
				printed_chars += _putchar(format[i]);
		}

		i++;
	}

	return (printed_chars);
}

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: On success, returns the number of characters written.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Writes a string to stdout
 * @str: The string to print
 *
 * Return: On success, returns the number of characters written.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _puts(char *str)
{
	int i, len = 0;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		len += _putchar(str[i]);

	return (len);
}
