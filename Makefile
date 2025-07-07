NAME = libftprintf.a
FLAG = -Werror -Wextra -Wall

CFILE = printf.c\
		utils.c 

OFILE = printf.o\
		utils.o

all : NAME





clean : 
	rm -fd *.o 

fclean : clean
	rm *.a

re : fclean all

PHONY = all, clean, fclean, re 