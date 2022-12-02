#include "so_long.h"

int    linecount(char *file)
{
    int     line;

    line = 1;
    while (*file)
    {
        if (*file == '\n')
            line++;
        file++;
    }
    return (line);
}

static char   *get_filedata(char **data, char *file)
{
    char    *str;
    char    *temp;
    int     fd;
    
    fd = open(file, O_RDONLY);
    if (fd < 0)
        error_file("Error\n file not found");
    *data = ft_calloc(1, sizeof(char *));
    while(1)
    {
        temp = get_next_line(fd);
        if (!temp)
            break;
        str = *data;
        *data = ft_strjoin(str, temp);
        free(temp);
        free(str);
    }
    close(fd);
    return(*data);
}

size_t	ft_strlenn(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len] != '\n')
		len++;
	return (len);
}

void print_grid(t_map mapdata)
{
    int     i;
    int     j;

    i = 0;
    while (i < mapdata.height)
    {
        j = 0;
        while (j < mapdata.width)
        {
            ft_printf("%c", mapdata.grid[i][j]);
            j++;
        }
        ft_printf("%c", '\n');
        j = 0;
        i++;
    }
    
}

static char **creategrid(t_map mapdata, char *filedata)
{
    int     i;
    int     j;
    char    **grid;

    grid = malloc(sizeof(char *) * mapdata.height);
    i = 0;
    while (i < mapdata.height)
    {
        grid[i] = malloc(sizeof(char) * (mapdata.width));
        j = 0;
        while (j < mapdata.width)
        {
            grid[i][j] = *filedata;
            filedata++;
            j++;
            if (*filedata == '\n')
            {
                filedata += 1;
                break;
            }
            if (*filedata == '\0')
                break;
        }
        j = 0;
        i++;
    }
    return (grid);
}

static void set_mapdata(t_data *data)
{
    data->map.height = linecount(data->filedata);
    data->map.width = ft_strlenn(data->filedata);
    data->map.grid = creategrid(data->map, data->filedata);
    validate_map(*data);
}

void    read_map(t_data *data, char *file)
{
    int     fd;
    char    *str;
    char    *filedata;

    if (check_fextension(file))
        error_file("Error\n file extention not .ber"); 
    get_filedata(&data->filedata, file);
    set_mapdata(data);
    // print_grid(data->map);
}