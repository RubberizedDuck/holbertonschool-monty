# Compiling for monty are as follows;
# gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c90 -g
RM=rm -rf

TARGET=monty
SRC=	main.c \
	error_functions.c \
	push.c \
	pall.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

quick:
	$(CC) $(SRC) -o $(TARGET)

clean:
	$(RM) *~ \#*\# \.\#* \
	$(TARGET)

re:	clean all
