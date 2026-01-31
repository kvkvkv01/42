*This project has been created as part of the 42 curriculum by caualves*

# ft_printf

## Description

`ft_printf` is a custom implementation of the standard C library function `printf()`.

The goal of this project is to recreate the `printf()` function from the C standard library, implementing the core conversion specifiers: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%`.

This project envolves:
- Variadic functions;
- String formatting and parsing;
- Number base conversions (decimal, hexadecimal);
- Memory management;
- Library creation.

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

### Conversions

- **`%c`**: `write()`;
- **`%s`**: `ft_pustr()`;
- **`%p`**: Pointer address conversion using `unsigned long long` and hexadecimal base conversion with `0x` prefix;
- **`%d` / `%i`**: Signed integer conversion with `ft_itoa()`;
- **`%u`**: Unsigned integer conversion with `ft_utoa()`;
- **`%x` / `%X`**: Hexadecimal conversion using recursive base conversion with lowercase/uppercase alphabets;



