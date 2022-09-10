# Simple Shell
This project is the most important of the first trimester of ALX & Holberton School, is the consolidation of everything we learned in the quarter about System engineering & DevOps and Low-level programming & Algorithm.
Using C programming language, we develop our own Shell.

### Description
The shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.

___
### Installation
You can install the simple shell cloning this repo:

$ git clone https://github.com/harkinder-dark/simple_shell.git

Next you can compile the files with this command:

$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

finally you can run our Shell writing:

./hsh

### Files
| File Name | Description |
| ------ | ------ |
built_in.c | Handle built-ins |
built_ins.c | Handle all built-ins, handle changing directory and finding path |
 cmd_args.c | function to count delims of string |
| cmd_runs.c | Executes programs, verify the locations and handles all functions |
| cmd_sys.c | handle command call system execute |


### Built with
This project was built and development with:
- `C programming language:` is a general-purpose, procedural computer programming language supporting structured programming, lexical variable scope, and recursion, while a static type system prevents unintended operations.
- `Ubuntu 14.04 LTS:` Operating system tester and working.