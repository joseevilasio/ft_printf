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

## Bonus

'#' Efeito apenas em x X

'+' Efeito em d e i

' ' Efeito em d e i

'0' Add 0 a esquerda em d i x X u

flags: Define opções de formatação, como alinhamento, preenchimento com zeros, exibição de sinal e outros. Por exemplo, você pode usar -, +, 0, #, ou ' '.

width: Especifica a largura mínima do campo de saída. Se o argumento for menor que essa largura, ele será preenchido com espaços à esquerda (ou à direita, dependendo da flag -). Você pode especificar o número mínimo de caracteres a serem impressos.

.precision: Controla o número de dígitos a serem impressos após o ponto decimal (para números de ponto flutuante) ou o número mínimo de dígitos a serem impressos (para inteiros). Para strings, especifica o número máximo de caracteres a serem impressos.

length: Especifica o tamanho do argumento. Por exemplo, h para short int, l para long int, ll para long long int, z para size_t, j para intmax_t, t para ptrdiff_t, entre outros.
specifier: Indica o tipo de dados do argumento a ser impresso. Por exemplo, d para inteiros decimais, f para números de ponto flutuante, s para strings, c para caracteres, p para ponteiros, entre outros.