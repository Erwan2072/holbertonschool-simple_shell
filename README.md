# ***Simple Shell***

<img src ="https://github.com/Erwan2072/holbertonschool-simple_shell/blob/main/img/joshua-laborne-simple-shell-erwan-lebreton.png">

##CONTENTS
- [DESCRIPTION](#description)
- [FLOWCHART](#flowchart)
- [REQUIREMENTS](#requirements)
- [COMPILATION CMD](#compilation-cmd)
- [EXAMPLES](#examples)
- [MAN PAGE](#man-page)
- [CHECK MEMORY LEAKS](#check-memory-leaks)
- [AUTHORS](#authors)

##  DESCRIPTION

The shell is a command-line interface enabling the user to interact with a computer's operating system. It acts as a layer of abstraction between the user and the operating system kernel, enabling the user to execute commands, launch programs, navigate directories, manage files and processes, and automate tasks using scripts.

The shell is a powerful tool for interacting with a command-line operating system, enabling users to execute commands, launch programs, navigate directories, manage files and processes, and automate tasks.

[*Return Contents*](#contents)

##  FLOWCHART

[*Contents*](#contents)

##  REQUIREMENTS

compiler, list of authorized functions

_Compiler :_GNU

_List of authorized functions :

```

  	All Functions from string.h
	access (man 2 access)
	chdir (man 2 chdir)
	close (man 2 close)
	closedir (man 3 closedir)
	execve (man 2 execve)
	exit (man 3 exit)
	_exit (man 2 _exit)
	fflush (man 3 fflush)
	fork (man 2 fork)
	free (man 3 free)
	getcwd (man 3 getcwd)
	getline (man 3 getline)
	getpid (man 2 getpid)
	isatty (man 3 isatty)
	kill (man 2 kill)
	malloc (man 3 malloc)
	open (man 2 open)
	opendir (man 3 opendir)
	perror (man 3 perror)
	printf (man 3 printf)
	fprintf (man 3 fprintf)
	vfprintf (man 3 vfprintf)
	sprintf (man 3 sprintf)
	putchar (man 3 putchar)
	read (man 2 read)
	readdir (man 3 readdir)
	signal (man 2 signal)
	stat (__xstat) (man 2 stat)
	lstat (__lxstat) (man 2 lstat)
	fstat (__fxstat) (man 2 fstat)
	strtok (man 3 strtok)
	wait (man 2 wait)
	waitpid (man 2 waitpid)
	wait3 (man 2 wait3)
	wait4 (man 2 wait4)
	write (man 2 write)
```
[*Return Contents*](#contents)

### COMPILATION CMD

```
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
[*Return Contents*](#contents)

### EXAMPLES

_Interactive :_

```
$ ls
AUTHORS  README.md  _getenv.c  _which.c  execute.c  hsh  man_simple_sell  parsing_args.c  readline.c  shell.c  shell.h
$ exit
root@5c5a57f010d74674ba5a58fcbe9e77ff-2377118072:/holbertonschool-simple_shell#
```
_Non-interactive :_

```
echo "/bin/ls" | ./hsh
AUTHORS  README.md  _getenv.c  _which.c  execute.c  hsh  man_simple_sell  parsing_args.c  readline.c  shell.c  shell.h
root@5c5a57f010d74674ba5a58fcbe9e77ff-2377118072:/holbertonschool-simple_shell#

```
[*Return Contents*](#contents)

## MAN PAGE

The command to use the man page is :
```
	man ./man_simple_shell
```
[*Return Contents*](#contents)

### CHECK MEMORY LEAKS

_Interactive :_
```
	Valgrind ./hsh
```
_Interactive detailed:_
```
valgrind --leak-check=full  --show-leak-kinds=all --track-origins=yes --verbose ./hsh
```
_Non-interactive :_
```
echo "/bin/ls" | valgrind ./hsh
```
_Non-interactive detailed:_

```
echo "/bin/ls" | valgrind --leak-check=full  --show-leak-kinds=all --track-origins=yes --verbose ./hsh
```

[*Return Contents*](#contents)

## AUTHORS

Joshua Laborne [@Jlaborne](https://github.com/Jlaborne)
Erwan Lebreton [@Erwan2072](https://github.com/Erwan2072)
