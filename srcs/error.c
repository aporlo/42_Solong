#include "so_long.h"

void    error_line(char *msg, char *line)
{
    ft_putstr_fd(msg, STDERR_FILENO);
    free(line);
    exit(EXIT_FAILURE);
}

void    error_file(char *msg)
{
    ft_putstr_fd(msg, STDERR_FILENO);
    exit(EXIT_FAILURE);
}