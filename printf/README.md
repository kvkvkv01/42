*This project has been created as part of the 42 curriculum by caualves*

# ft_printf

## Description

`ft_printf` is a custom implementation of the standard C library function `printf()`. This project is part of the 42 curriculum and focuses on learning variadic functions in C, which allow functions to accept a variable number of arguments.

The goal of this project is to recreate the `printf()` function from the C standard library, implementing the core conversion specifiers: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%`. The implementation does not include buffer management like the original `printf()`, making it a simplified but functional version.

This project demonstrates understanding of:
- Variadic functions;
- String formatting and parsing;
- Number base conversions (decimal, hexadecimal);
- Memory management;
- Library creation using `ar` command.

## Instructions

### Compilation

To compile the library, simply run:

```bash
make
```

This will create `libftprintf.a` at the root of the repository.

### Usage

To use `ft_printf` in your project:

1. Include the header file:
```c
#include "ft_printf.h"
```

2. Compile your program with the library:
```bash
cc your_program.c -L. -lftprintf -o your_program
```

### Makefile Rules

- `make` or `make all`: Compiles the library;
- `make clean`: Removes object files (`.o`);
- `make fclean`: Removes object files and the library;
- `make re`: Recompiles everything from scratch.

### Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! The number is %d\n", "World", 42);
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Hex lowercase: %x, uppercase: %X\n", 255, 255);
    return (0);
}
```

## Resources

### Documentation and References

- [C Variadic Functions](https://en.cppreference.com/w/c/variadic);
- [printf() Manual](https://man7.org/linux/man-pages/man3/printf.3.html);
- [stdarg.h Reference](https://en.cppreference.com/w/c/variadic);
- [Number Base Conversion Algorithms](https://en.wikipedia.org/wiki/Positional_notation).

### AI Usage

This project was implemented without the use of AI tools. All code was written manually to ensure proper understanding of variadic functions, string parsing, and number conversion algorithms. The implementation follows 42's learning philosophy of building strong foundations through hands-on practice.

## Algorithm and Data Structure

### Algorithm Overview

The `ft_printf` function uses a **parsing-based approach** with a **state machine** pattern:

1. **Format String Parsing**: The function iterates through the format string character by character;
2. **Conversion Detection**: When a `%` is encountered, the next character determines the conversion type;
3. **Argument Retrieval**: Variadic macros (`va_arg`) retrieve the appropriate argument type;
4. **Formatting and Output**: Each conversion handler formats and writes the output.

### Data Structures

The implementation uses minimal data structures:
- **Character arrays (strings)**: For storing intermediate formatted numbers;
- **Variadic argument list (`va_list`)**: For accessing variable arguments;
- **Integer counters**: For tracking the number of characters printed.

### Key Design Decisions

1. **Modular Conversion Handlers**: Each conversion specifier has its own function (`ft_print_char`, `ft_print_string`, etc.), making the code maintainable and extensible.

2. **Recursive Base Conversion**: For hexadecimal and pointer conversions, a recursive approach is used to convert numbers to different bases. This simplifies the implementation and handles edge cases like zero naturally.

3. **Dynamic Memory for Numbers**: Signed and unsigned integers are converted to strings using `ft_itoa` and `ft_utoa`, which allocate memory dynamically. This memory is freed immediately after printing to prevent leaks.

4. **Error Handling**: The function returns `-1` on error (matching `printf` behavior) and propagates errors through the call chain. Each `write` call is checked for failure.

5. **Null Pointer Handling**: For `%s` conversion, if a `NULL` pointer is passed, the string `"(null)"` is printed, matching the behavior of the original `printf()`.

### Conversion Implementations

- **`%c`**: Direct character output using `write()`;
- **`%s`**: String output with null pointer handling;
- **`%p`**: Pointer address conversion using `unsigned long long` and hexadecimal base conversion with `0x` prefix;
- **`%d` / `%i`**: Signed integer conversion using `ft_itoa()` which handles negative numbers;
- **`%u`**: Unsigned integer conversion using `ft_utoa()`;
- **`%x` / `%X`**: Hexadecimal conversion using recursive base conversion with lowercase/uppercase alphabets;
- **`%%`**: Literal percent sign output.



