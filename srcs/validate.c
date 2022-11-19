#include "so_long.h"

int check_fextension(char *file)
{
    if (!ft_strncmp(ft_strchr(file, '.'), ".ber", 4))
        return (0);
    return (1);
}

static int  check_charactor(t_data data)
{
    int i;

    i = 0;
    while (data.filedata[i])
    {
        if (data.filedata[i] != '\n')
        {
            if (ft_strchr("01CEP", data.filedata[i]) == NULL
            || ft_strchr(data.filedata, '0') == NULL)
            {
                ft_printf("file>>>%s\n", ft_strchr("01CEP", data.filedata[i]));
                return (-1);
            }
        }
        i++;
    }
    return (0);
}

static int  check_rec(t_data data)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (data.filedata[i])
    {
        if (data.filedata[i] == '\n')
        {
            if (len != data.map.width)
                return (-1);
            len = 0;
        }
        else
            len++;
        i++;
    }
    return (0);
}

static int check_wall(t_map mapdata)
{
    int i;
    int j;

    i = 0;
    while (i < mapdata.hight)
    {
        if (mapdata.grid[i][0] != '1'
            || mapdata.grid[i][mapdata.width - 1] != '1')
            return (-1);
        i++;
    }
    j = 0;
    while (j < mapdata.width)
    {
        if (mapdata.grid[0][j] != '1'
            || mapdata.grid[mapdata.hight - 1][j] != '1')
            return (-1);
        j++;
    }
    return (0);
}

static void    check_path(t_map *mapdata)
{
    int     i;
    int     j;

    i = 0;
    mapdata->C = 0;
    mapdata->E = 0;
    mapdata->P = 0;
    while (i < mapdata->hight)
    {
        j = 0;
        while (j < mapdata->width)
        {
            if(mapdata->grid[i][j]) 
            {
                if(mapdata->grid[i][j] == 'P')
                    mapdata->P++;
                if(mapdata->grid[i][j] == 'C') 
                    mapdata->C++;
                if(mapdata->grid[i][j] == 'E')
                    mapdata->E++;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void    validate_map(t_data data)
{
    check_path(&data.map);
    if (check_charactor(data) < 0)
        error_file("Error\n The map can be composed of only these 01CEP");
    if (data.map.E != 1 || data.map.P != 1)
        error_file("Error\n The map contain 1 exit and 1 starting position");
    if (data.map.C < 1)
        error_file("Error\n The map contain  at least 1 collectible");
    if (check_rec(data) < 0)
        error_file("Error\n The map must be rectangular");
    if (check_wall(data.map) < 0)
        error_file("Error\n The map must be closed/surrounded by walls");
}