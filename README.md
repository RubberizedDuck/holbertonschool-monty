<h1>C - Stacks, Queues - LIFO, FIFO</h1>
<h3>By Dylan Anderson, Gem Phan and Luke Hackett</h2>

# The Monty language #
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files ##
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```
## Compilation and Output ##
The Monty program will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty
```
* Any output must be printed on ```stdout```
* Any error message must be printed on ```stderr```
## Usage ##
```
./monty file
```
* Where ```file``` is the path to the file containing Monty byte code
* The error message ```USAGE: monty file``` will display if the user does not give any file or more than one argument to your program
* The error message ```Error: Can't open file <file>``` will be shown if, for any reason, it’s not possible to open the file (where ```<file>``` is the name of file)
* The error message ```L<line_number>: unknown instruction <opcode>``` will pop up if the file contains an invalid instruction
* The error message ```Error: malloc failed``` will be printed if you can't malloc anymore
