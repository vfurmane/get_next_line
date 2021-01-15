# get_next_line

This is my 2nd project at @42Paris.

:timer_clock: : 4 days
:heavy_check_mark: : 115
:robot: : 1

## Usage

This project is a function. You need to compile your project with these dependencies (with or without `_bonus`, they are the same files).

Here is the function prototype:

```c
int	get_next_line(int fd, char **line);
```

You also need to specify a `BUFFER_SIZE` during compilation:

```shell
clang -D BUFFER_SIZE=XX get_next_line.c get_next_line_utils.c
```