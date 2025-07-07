#include "libftprintf.h"


int ft_printf(const char * str, ...)
{
    va_list args;
    va_start(args,str);
    int i ;

    i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == '%')
        {
            i++;
            if(str[i] == 'd' || str[i] == 'i')
                ft_putstr(my_itoa(va_arg(args,int)));
            else if(str[i] == 'u')
                ft_putstr(my_itoa(va_arg(args,unsigned int)));
            else if(str[i] == 's')
                ft_putstr(va_arg(args,char * ));
            else if(str[i] == '%')
                write(1,"%",1);
            else if(str[i] == 'c')
            {
                int c = va_arg(args,int);
                write(1,&c,1);
            }
            else if(str[i] == 'x')
                ft_putstr(to_hexa(va_arg(args,unsigned int),'x'));
            else if(str[i] == 'X')
                ft_putstr(to_hexa(va_arg(args,unsigned int),'X'));
            else if(str[i] == 'p')
            {
                void * ptr = va_arg(args, void*);
                unsigned int uinteger = (unsigned int)ptr;
                ft_putstr(to_hexa_padding(uinteger,'x'));
            }
        }
        else
            write(1,&(str[i]),1);
        i++;
    }
}

int main()
{
    char* str = "oui";
    int nb = 17;
    int* ptr = &nb;
    unsigned int uint = 25924465;

    ft_printf("fausse = str = %s int = %i uint = %u char= %c\n",str,2,3,'a');
    printf("vraie = str = %s int = %i uint = %u char= %c\n",str,2,3,'a');

    ft_printf("test ft_printf = %%\n");
    printf("test printf = %%\n");

    printf("vraie = %u en hexadecimal = %s\n",uint,to_hexa(uint,'X'));
    ft_printf("fausse = %u en hexadecimal = %s\n",uint,to_hexa(uint,'X'));

    ft_printf("hexa x faux = %x\n",uint);
    printf("hexa x vrai = %x\n",uint);
    ft_printf("hexa X faux = %X\n",uint);
    printf("hexa X vrai = %X\n",uint);

    ft_printf("ptr faux = %p\n",str);
    printf("ptr vrai = %p\n",str);
    ft_printf("ptr faux = %p\n",nb);
    printf("ptr vrai = %p\n",nb);


    return 0;
}