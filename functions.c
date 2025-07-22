#include "main.h"

/**
 * print_char - prints a character
 * @args: argument list
 * Return: number of characters printed
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @args: argument list
 * Return: number of characters printed
 */

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (!str)
		str = "NULL";
	while (str[len])
		write(1, &str[len++], 1);

	return (len);
}

/**
 * print_percent - prints a percent sign
 * Return: number of characters printed
 */

int print_percent(void)
{
	return (write(1, "%", 1));
}

/**
 * print_int - prints a signed integer
 * @args: argument list
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0, div = 1;
	unsigned int num;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}
	while (num / div >= 10)
		div *= 10;
	while (div > 0)
	{
		char digit = '0' + (num / div);

		write(1, &digit, 1);
		count++;
		num %= div;
		div /= 10;
	}
	return (count);
}
