#include "main.h"

/**
 * _printf - printf function
 * @format: format string
 * @...: number of parameters stored
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);
	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				i++;
				if (format[i] == 'c')
					count += print_char(args);
				else if (format[i] == 's')
					count += print_string(args);
				else if (format[i] == '%')
					count += print_percent();
				else if (format[i] == 'd' || format[i] == 'i')
					count += print_int(args);
				else
				{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
				}
			}
			else
			{
				va_end(args);
				return (-1);
			}
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
