# Linked
### A generic C linked list library

Linked is a simple general purpose linked list library made in C. The library was made to be compliant with the EPITECH school coding-style rules.

## Dependencies

- [GNU Compiler Collection](https://gcc.gnu.org/) (11.4.0)
- [GNU Make](https://www.gnu.org/software/make/) (4.3)
- [Criterion](https://github.com/Snaipe/Criterion) (2.4.2) (for unit tests)

## Building

to build the library you can use the included Makefile:

```sh
make
```

It will then build the `liblinked.a` binary

## Installing

You can install the library into your system using the following command:

```sh
make install
```

You can then uninstall it using:

```sh
make uninstall
```

## Usage

Once installed or built, you can use the library by including the library header in your source files:

```c
#include <linked.h>
```

and add the library to the linker when compiling:

```sh
gcc myfile.c -llinked
```
