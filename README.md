## TOP
<p align="center">
	<img src= "https://github.com/loicleguen/holbertonschool-printf/blob/main/holberton.png">
</p>

# _printf - Recreation of printf function in C

## Table of contents
- **[Description](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#-description)**
- **[Compilation](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#compilation)**
- **[General requirement](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#general-requirements)**
- **[Functions supported](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#%EF%B8%8F-functions-supported)**
- **[Execute command Man page](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#-execute-command-man-page)**
- **[Flowchart](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#flowchart)**
- **[Exemple of use](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#-example-of-use)**
- **[Snippets](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#snippets)**
- **[Using valgrind to detect memory leaks](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#using-valgrind-to-detect-memory-leaks)**
- **[Link to our code of printf](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#link-to-our-code-of-printf)**
- **[Authors](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#-authors)**


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

## Compilation

gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c



---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## General requirements

- Allowed Editors: vi, vim, emacs.
- Compilation Environment: Ubuntu 20.04 LTS.
- C Compiler: gcc with options -Wall -Werror -Wextra -pedantic -std=gnu89.
- End of File: All files must end with a newline.
- README.md File: Mandatory at the root of the project folder.
- Code Style: Conforms to Betty style (checked with betty-style.pl and betty-doc.pl).
- Global Variables: Forbidden.
- Number of Functions per File: No more than 5 functions per file.
- main.c Files: Must not be pushed into the root repository. Test files with main can be placed in a separate folder (test/).
- Header File: main.h must contain the prototypes of all functions and be include-guarded.

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

## 🧪 Execute command Man page

man ./man_3_printf.3 

---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## Flowchart

<img src= "https://github.com/loicleguen/holbertonschool-printf/blob/main/Flowchartprintf.drawio.png">

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

STDOUT
Let's try to printf a simple sentence.
Length:[39, 39]
Negative:[-762534]
Character:[H]
String:[I am a string !]
Percent:[%]
Len:[12]

```


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
---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## Using valgrind to detect memory leaks

	valgrind ./a.out 
	==49754== HEAP SUMMARY:
	==49754==     in use at exit: 0 bytes in 0 blocks
	==49754==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
	==49754== 
	==49754== All heap blocks were freed -- no leaks are possible
	==49754== 
	==49754== For lists of detected and suppressed errors, rerun with: -s
	==49754== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## Link to our code of printf

- - **[main.h](https://github.com/loicleguen/holbertonschool-printf/blob/main/main.h)**
- - **[functions.c](https://github.com/loicleguen/holbertonschool-printf/blob/main/functions.c)**
- - **[printf.c](https://github.com/loicleguen/holbertonschool-printf/blob/main/printf.c)**
- - **[man page of printf](https://github.com/loicleguen/holbertonschool-printf/blob/main/man_3_printf.3)**

---

**[TOP](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#top)**

## 👥 Authors

- **[Yanis Leroy](https://github.com/LEROY-Yanis)**  
- **[Loic Le Guen](https://github.com/loicleguen)**
