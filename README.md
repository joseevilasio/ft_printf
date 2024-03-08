# ft_printf
'Because ft_putnbr() and ft_putstr() aren’t enough'. Project is part of the course of 42 school.
The ft_printf was designed to have function similar to standard C printf.

## Compile
To compile the library, simply use the makefile targets on the command line within the 'src' folder.
```
./src/make libft.a
```

## Tests
My tests were conducted using GTest. The prerequisites are to have CMake installed on your machine and to have already compiled the library.
```
./cmake -S . -B build && cmake --build build && ./build/all_tests
```
In addition to my own tests, tests were conducted using the [Francinette](https://github.com/xicodomingues/francinette) tool for the library.

🚩 *So far it has not been tested by Moulinette*.
