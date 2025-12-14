// mylib.c
#include <stdio.h>

void hello(const char* name) {
    printf("Hello, %s! From shared library.\n", name);
}
