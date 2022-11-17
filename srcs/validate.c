#include "so_long.h"
int checkfile(char *av)
{
    int fd;
    if (check_fextension(av))
        error_file("Error\nfile extention is not .ber");
    fd = open(av, O_RDONLY);
    if (fd < 0)
    {
        perror(av);
        exit(EXIT_FAILURE);
    }
}

int check_fextension(char *file)
{
    printf("file is %s\n", file);
    if (!ft_strncmp(ft_strchr(file, '.'), ".ber", 4))
        return (0);
    return (1);
}

// size_t	ft_strlenn(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	if (!s)
// 		return (len);
// 	while (s[len] != '\0' || s[len] != '\n')
// 		len ++;
// 	return (len);
// }

// int check_map(int fd)
// {
//     char    *line;
//     int     t_size;
    
//     line = get_next_line(fd);
//     t_size = ft_strlenn(line);
//     check_part(line);
//     while (line != NULL)
//     {
//         free(line);
//         line = get_next_line(fd);
//         check_part(line);
//         if (t_size != ft_strlenn(line))
//             error_line("Error\n the file not be exist", line);
//     }
//     if (check_part(NULL) < 1)
//         error_line("Error\n there must be at least one 'C'", line);
// }

// int check_part(char *line)
// {
//     int i;
//     int num_P;
//     int num_E;
//     int num_C;

//     i = 0;
//     num_E = 0;
//     num_P = 0;
//     num_C = 0;
//     while (line[i] != '\0' && line[i] != '\n' && line)
//     {
//         if (ft_strchr("01CEP", line[i] == NULL))
//             error_line("Error\n the map must to be 01CEP", line);
//         if (line[i] == 'E')
//             num_E++;
//         if (line[i] == 'P')
//             num_P++;
//         if (line[i] == 'C')
//             num_C++;
//     }
//     if (num_E > 1 || num_P >1)
//         error_line("Error\n The map must contain 1 exit or 1 starting", line);
//     return(num_C);
// }
