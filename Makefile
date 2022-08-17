# Compiling for monty are as follows;
# gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c90 -g
RM=rm -rf
VALGRIND=valgrind --leak-check=full --show-leak-kinds=all ./monty 
BETTY=betty

TARGET=monty
SRC=	main.c \
	error_functions.c \
	push.c \
	pall.c \
	pint.c \
	free_list.c

MONTY00=bytecodes/00.m

MONTY01=bytecodes/01.m

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

val 0 1:

0:
	$(VALGRIND) $(MONTY00)

1:
	$(VALGRIND01) $(MONTY01)

quick:
	$(CC) $(SRC) -o $(TARGET)

betty:
	$(BETTY) $(SRC)

clean:
	$(RM) *~ \#*\# \.\#* \
	$(TARGET)

re:	clean all
