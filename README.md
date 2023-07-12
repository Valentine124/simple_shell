# 0x16. C - Simple Shell

<img src="https://miro.medium.com/v2/resize:fit:720/format:webp/1*WqxZ99tyXrI3aIYW8lLoHA.png" width="300px" height="300px" align="center">

#### A Shell is a program that takes the command inputs written from the user’s keyboard and passes them to the machine to execute them through the kernel. It also verifies if the command input from the user is correct.

<hr>

## Contributors

|Name|Email|
| --- | --- |
| Uka chibuike .V | kaluvalentine60@gmail.com |
| Richard Lawrence | richard.obomanu818@gmail.com |

<hr>

## Compilation

#### The program should be copiled with

> gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o hsh

## Output

* The shell have exact output as the `sh` (`bin/sh`)
* The only different is when error is printed, the name of the program is equivalent to the argv[0] (see below)

###### Example of an error in `sh`

```shell
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

<hr>

###### Example of an error in the program `hsh`

```shell
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

<hr>

## Testing

###### The program should work like this in interactive mode

```shell
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
###### But also in non-interactive mode

```shell
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
