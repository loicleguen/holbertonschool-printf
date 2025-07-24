## TOP
<img src= "https://github.com/loicleguen/holbertonschool-printf/blob/main/holberton.png">

# _printf - Recreation of printf function in C

## Table of contents
**[Description](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#-description)**
**[Authors](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#-authors)**
**[General requirement](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#general-requirements)**
**[Functions supported](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#%EF%B8%8F-functions-supported)**
**[Exemple of use](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#-example-of-use)**
**[Flowchart](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#flowchart)**

---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## 📚 Description

This project aims to **recreate the `printf` function** from the standard C language library. It is an exercise designed to provide in-depth understanding of:

- Variadic functions (`stdarg.h`)
- Formatting management of a string
- Writing to the standard output (`write`)
- Working as a pair and the modular organization of a project

Project carried out in pairs as part of the Holberton curriculum.

---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## 👥 Authors

- **[Yanis Leroy](https://github.com/LEROY-Yanis)**  
- **[Loic Le Guen](https://github.com/loicleguen)**

---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## General requirements

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you     do we won’t take them into account). We will use our own main.c files at compilation; do not push your own main.c file. Our main.c files might be different from    the one shown in the examples
- The prototypes of all your functions should be included in your header file called main.h
- Don’t forget to push your header file
- All your header files should be include guarded

---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## 🛠️ Functions supported

The `_printf` function supports the following format specifiers:

|**Specifier**  | **Description**                     |
|---------------|-------------------------------------|
| `%c`          | Prints a **character**              |
| `%s`          | Prints a **string**                 |
| `%%`          | Prints the `%` character            |
| `%d`, `%i`    | Prints a **signed integer**         |

Undefined behaviors (such as %r) are printed as-is, just like `printf` does.

---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## 🧪 Example of use

```c
#include "main.h"

int main(void)
{
    int len;

    len = _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    _printf("Negative:[%d]\n", -762534);
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    return (0);
}
```
---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## Flowchart

<img src= "https://github.com/loicleguen/holbertonschool-printf/blob/main/Flowchartprintf.drawio.png">

---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## Snippets

Exemple our printf function
```c
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
```
Exemple of our handle_format function
```c
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
```
Exemple of our print_char function who whrite a character
```c
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
```

