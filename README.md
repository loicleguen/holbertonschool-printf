# _printf - Recréation de la fonction printf en C

## Table des matière
**[Description](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#-description)**
**[Authors](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#-authors)**
**[Functions supported](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#%EF%B8%8F-functions-supported)**
**[Exemple of use](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#-example-of-use)**
**[Flowchart](https://github.com/loicleguen/holbertonschool-printf/blob/main/README.md#flowchart)**

---

## 📚 Description

This project aims to **recreate the `printf` function** from the standard C language library. It is an exercise designed to provide in-depth understanding of:

- Variadic functions (`stdarg.h`)
- Formatting management of a string
- Writing to the standard output (`write`)
- Working as a pair and the modular organization of a project

Project carried out in pairs as part of the Holberton curriculum.

---

## 👥 Authors

- **[Yanis Leroy](https://github.com/LEROY-Yanis)**  
- **[Loic Le Guen](https://github.com/loicleguen)**

---

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

## 🧪 Example of use

```c
#include "main.h"

int main(void)
{
    int count;

    count = _printf("%cello, our names are %s and %s, we have respectively %d and %i years.\n", 'H', "Le Guen", "Leroy", 37, 17);
    _printf("Nombre de caractères affichés : %d\n", count);
    return (0);
}
```
---

## Flowchart

<img src= "https://github.com/loicleguen/holbertonschool-printf/blob/main/Flowchartprintf.drawio.png">

---
