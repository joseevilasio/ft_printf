# ft_printf
'Because ft_putnbr() and ft_putstr() aren’t enough'. Project is part of the course of 42 school.
The ft_printf was designed to have function similar to standard C printf.

## Compile
To compile the library, simply use the makefile targets on the command line within the 'src' folder.
```
./src/make re
```

## Tests
My tests.
```
./tests/make run
```
In addition to my own tests, tests were conducted using the [Francinette](https://github.com/xicodomingues/francinette) tool for the library.

🚩 *So far it has not been tested by Moulinette*.

## Usage

• Prints a single character. 🏳️ [flag -> %c]
```
> ft_printf("%c %c", 65, 'a');
$A a
```
• Prints a string (as defined by the common C convention). 🏳️ [flag -> %s]
```
> ft_printf("%s", "Hello World!");
$Hello World!
```
• The void * pointer argument has to be printed in hexadecimal format. 🏳️ [flag -> %p]
```
> ft_printf("%p", &pointer);
$0x7fff92232427
```
• Prints a decimal (base 10) number. 🏳️ [flag -> %d]
```
> ft_printf("%d", -2147483648);
$-2147483648
```
• Prints an integer in base 10. 🏳️ [flag -> %i]
```
> ft_printf("%i", 1942);
$1942
```
• Prints an unsigned decimal (base 10) number. 🏳️ [flag -> %u]
```
> ft_printf("%u", 42);
$42
```
• Prints a number in hexadecimal (base 16) lowercase format. 🏳️ [flag -> %x]
```
> ft_printf("%x, 27754);
$6c6a
```
• Prints a number in hexadecimal (base 16) uppercase format. 🏳️ [flag -> %X]
```
> ft_printf("%X, 27754);
$6C6A
```
• Prints a percent sign. 🏳️ [flag -> %%]
```
> ft_printf("%%");
$%
```