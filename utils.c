#include "libftprintf.h"

char *my_itoa(int value) 
{
    int tmp = value;
    int length = (value <= 0) ? 1 : 0; 

    while (tmp != 0) {
        tmp /= 10;
        length++;
    }

    char *str = malloc(length + 1);
    if (!str) return NULL;
    str[length] = '\0';

    int is_negative = (value < 0);
    unsigned int n = is_negative ? -value : value;

    for (int i = length - 1; i >= 0; --i) {
        str[i] = '0' + (n % 10);
        n /= 10;
        if (n == 0 && is_negative && i > 0)
        {
            str[i - 1] = '-';
            break;
        }
    }
    return str;
}

void ft_putstr(char* str)
{
    int i;
    i = 0;
    while(str[i] != 0)
    {
        write(1,&(str[i]),1);
        i++;
    }
}

char* to_hexa_padding(unsigned int nb, char type)
{
    unsigned int tmp;
    unsigned int size;
    char* buffer;
    unsigned int i;

    size = 8;
    buffer = malloc((size+1)*sizeof(char));
    tmp = nb;
    buffer[size] = '\0';
    while(tmp >= 16)
    {
        size--;
        buffer[size] = (type == 'x') ? "0123456789abcdef"[tmp%16] : "0123456789ABCDEF"[tmp%16];
        tmp = tmp/16;
    }
    size--;
    buffer[size] = (type == 'x') ? "0123456789abcdef"[tmp%16] : "0123456789ABCDEF"[tmp%16];
    while(size > 0)
    {
        size--;
        buffer[size] = '0';
    }
    return(buffer);
}

char* to_hexa(unsigned int nb, char type)
{
    unsigned int len;
    unsigned int tmp;
    char* buffer;

    len = 1;
    tmp = nb;

    while(tmp >= 16)
    {
        tmp = tmp / 16;
        len++;
    }
    tmp = nb;
    buffer = (char*)malloc((len+1) * sizeof(char));
    buffer[len] = '\0';
    while(len > 0)
    {
        len--;
        buffer[len] = (type == 'x') ? "0123456789abcdef"[tmp%16] : "0123456789ABCDEF"[tmp%16];
        tmp /= 16;
    }
    return buffer;
}