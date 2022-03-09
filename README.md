# strace
{EPITECH} | Second year | Unix porgraming -  Instrumentation

strace traces a program in real time and displays all of the system calls it executes in their order of appearance.

Develop an alternative to strace that implementing the following options:
 - -p: force a specific PID instead of executing a command
 - -s: display the detailled arguments (see below).

By default, your strace must only display the arguments and return values in hexadecimal form.
If the system call has a void return value, display a question mark.
With -s option, your program must be as close as possible to the strace command on your system,
and therefore display the following:

- integers in decimal form,
- pointers on a character string in the form of a character string,
- detailed structures (value for each field).

See the subject for further details !

========================

Grade : C | Mark : 17.3

| Category      | Percentage | Tests     | Crash ? |
|---------------|------------|-----------|---------|
| Parameters    | 100%       | 2/2       | x       |
| Return value  | 100%       | 3/3       | x       |
| Rigour        | 100%       | 2/2       | x       |
| syscall name  | 100%       | 3/3       | x       |
| **End score** | **100%**   | **10/10** | **No**  |

Made with Quentin TREHEUX ([LuciferBahamut](https://github.com/LuciferBahamut))

Beware of -42 Epitech students !!!
