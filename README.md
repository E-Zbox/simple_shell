# C - Simple Shell

### Table of Contents

-	[Description](#description)
	-	[Backgroud Context](#background-context)
	-	[Compilation](#compilation)
-	[Testing](#testing)
	-	[Output](#output)
-	[List of allowed functions and system calls](#list-allowed-functions-system-calls)
-	[Authors](#authors)

## Description

### Background Context

A simple UNIX command interpreter

### Compilation

``` shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### Testing

How the shell works in interactive mode:

``` shell
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

In non-interactive mode:

``` shell
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### Output

-	Unless specified otherwise, your program **must have the exact same output** as `sh` (`/bin/sh`) as well as the exact same error output.
-	The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]` (See below)

Example of error with `sh`:

``` shell
o "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

Same error with your program `hsh`:

``` shell
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## List of allowed functions and system calls

-	`access`, `chdir`, `close`
-	`closedir`, `execve`, `exit`
-	`_exit`, `fflush`, `fork`
-	`free`, `getcwd`, `getline`
-	`getpid`, `isatty`, `kill`
-	`malloc`, `open`, `opendir`
-	`perror`, `read`, `readdir`
-	`signal`, `stat`, `lstat`
-	`fstat`, `strtok`, `wait`
-	`waitpid`, `wait3`
-	`wait4`, `write`

## AUTHORS

Ononogbu Ebenezer

Adetunji Adebowale

