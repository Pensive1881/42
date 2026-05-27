*This project has been created as part of the 42 curriculum by acasper, rrajni*

# MINISHELL

## Description


## Instructions
### Compile

```zsh
make
```

### Run minishell

```zsh
./minishell
```

### Clean object files

```zsh
make clean
```

### Remove object files and executable

```zsh
make fclean
```

### Recompile everything

```zsh
make re
```

### Example Usage

```shell
minishell$ echo hello world
hello world

minishell$ ls -l | grep minishell

minishell$ export USERNAME=marvin

minishell$ echo $USERNAME
marvin
```

### Supported Features

```md
- pipes (`|`)
- redirections (`<`, `>`, `>>`)
- heredocs (`<<`)
- environment variables (`$VAR`)
- signal handling
- builtins
```

## Resources

### Shell Behavior

- Bash manual
- POSIX shell specification

### System Calls

- fork
- execve
- wait / waitpid
- pipe
- dup / dup2

### Parsing

- tokenization
- ASTs
- quote handling
- environment expansion

### Debugging

- valgrind
- gdb
```

## AI Usage

