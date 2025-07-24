#include "main.h"

/**
 * handle_format - handles format specifiers for _printf
 * @format: format string
 * @i: pointer to current index in format
 * @args: argument list
 * Return: number of characters printed, or -1 on error
 */

int handle_format(const char *format, int *i, va_list args)
{
	int count = 0;

	if (format[*i + 1])
	{
		(*i)++;
		if (format[*i] == 'c')
			count += print_char(args);
		else if (format[*i] == 's')
			count += print_string(args);
		else if (format[*i] == '%')
			count += print_percent();
		else if (format[*i] == 'd' || format[*i] == 'i')
			count += print_int(args);
		else
		{
			write(1, "%", 1);
			write(1, &format[*i], 1);
			count += 2;
		}
	}
	else
		return (-1);

	return (count);
}

/**
 * _printf - printf function
 * @format: format string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, res;

	if (!format)
		return (-1);
	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			res = handle_format(format, &i, args);
			if (res == -1)
			{
				va_end(args);
				return (-1);
			}
			count += res;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
