#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *, ...);
char *my_itoa(int value);
void ft_putstr(char* str);
char* to_hexa(unsigned int nb, char type);
char* to_hexa_padding(unsigned int nb, char type);