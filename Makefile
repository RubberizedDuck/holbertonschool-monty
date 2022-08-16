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
	pall.c

all:
	$(BETTY) $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

quick:
	$(CC) $(SRC) -o $(TARGET)

clean:
	$(RM) *~ \#*\# \.\#* \
	$(TARGET)

re:	clean all

val:
	$(VALGRIND)
