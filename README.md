# Simple Shell

Educational command-line shell prototype developed as part of the Holberton School curriculum.

## Project overview

The program demonstrates a small interactive loop that reads a command, splits it into whitespace-delimited arguments, and launches external programs with the POSIX process APIs.

The current implementation includes:

- An interactive prompt (`Shellinator$>`).
- External command execution through `fork()`, `execvp()` and `waitpid()`.
- A built-in `cd` command using `chdir()`.
- A built-in `exit` command.
- Basic input handling with `getline()`.
- A separate SIGINT handler implementation.

This is a learning prototype, not a production shell or a complete POSIX shell.

## Source layout

| File | Responsibility |
| --- | --- |
| `conf.c` | Program entry point |
| `lsh_loop.c` | Interactive command loop |
| `read_line.c` | Reads a line from standard input |
| `divide.c` | Splits input into whitespace-delimited tokens |
| `execute_command.c` | Handles built-ins and launches external commands |
| `signal.c` | Contains a basic SIGINT handler |
| `shell.h` | Shared declarations and system headers |
| `my_pid.c` | Separate process-ID experiment; has its own `main()` |

## Current limitations

The implementation is intentionally small. It does not currently provide a complete shell grammar or claim support for:

- Quoted arguments and escaped whitespace.
- Pipes, redirection, command chaining or environment expansion.
- Globbing, aliases, command history or job control.
- Full POSIX signal and terminal handling.

The signal setup function is defined separately; its integration into the main loop should be verified before relying on Ctrl+C behavior.

## Repository hygiene

Generated editor swap files and a previously committed compiled executable have been removed. Keep build outputs, editor temporary files, local configuration and credentials out of version control.

## Contributors

- Alexis Rodriguez
- Bryan Aleman
- Micke Lucas

## Status

Historical educational project. The source is preserved for reference and learning; no current automated test suite or production-readiness claim is made.
