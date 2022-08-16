# Compiling for monty are as follows;
# gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c90 -g
RM=rm -rf

TARGET=monty
SRC=	main.c \
	error_functions.c \
	push.c \

all: 1

1:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	$(RM) *~ \#*\# \.\#* \
	$(TARGET)
