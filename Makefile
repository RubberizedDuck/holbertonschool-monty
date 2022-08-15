# Compiling for monty are as follows;
# gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c90

TARGET=monty
SRC=	#files to be compiled

all: 1

1:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
