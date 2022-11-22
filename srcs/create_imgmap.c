#include "so_long.h"

void    create_floor(t_data *data, t_image image)
{
    int     x;
    int     y;

    x = 0;
    image.addr = "images/floor.xpm";
    image.img = mlx_xpm_file_to_image(data->mlx, image.addr, &image.w, &image.h);
    while(x < data->map.height)
    {
        ft_printf("h2>>%d\n", data->map.height);
        y = 0;
        while (y < data->map.width)
        {
            if(data->map.grid[x][y]) 
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, image.img, y*PIXEL, x*PIXEL);
            }
            y++;
        }
        x++;
    }
}

void    create_wall(t_data *data, t_image image)
{
    int     x;
    int     y;

    x = 0;
    image.addr = "images/wall.xpm";
    image.img = mlx_xpm_file_to_image(data->mlx, image.addr, &image.w, &image.h);
    while(x < data->map.height)
    {
        ft_printf("h2>>%d\n", data->map.height);
        y = 0;
        while (y < data->map.width)
        {
            if(data->map.grid[x][y]) 
            {
                print_grid(data->map);
                // printf("", data->map.grid[x][y]);
                if (data->map.grid[x][y] == '1')
                {
                    ft_printf("x>>%d\n", x);
                    ft_printf("y>>%d\n", y);
                    mlx_put_image_to_window(data->mlx, data->mlx_win, image.img, y*PIXEL, x*PIXEL);
                }
            }
            y++;
        }
        x++;
    }
}
void    create_item(t_data *data, t_image image)
{
    int     x;
    int     y;

    x = 0;
    image.addr = "images/carrot.xpm";
    image.img = mlx_xpm_file_to_image(data->mlx, image.addr, &image.w, &image.h);
    while(x < data->map.height)
    {
        ft_printf("h2>>%d\n", data->map.height);
        y = 0;
        while (y < data->map.width)
        {
            if(data->map.grid[x][y]) 
            {
                print_grid(data->map);
                // printf("", data->map.grid[x][y]);
                if (data->map.grid[x][y] == 'C')
                {
                    ft_printf("x>>%d\n", x);
                    ft_printf("y>>%d\n", y);
                    mlx_put_image_to_window(data->mlx, data->mlx_win, image.img, y*PIXEL, x*PIXEL);
                }
            }
            y++;
        }
        x++;
    }
}

void    create_tree(t_data *data, t_image image)
{
    int     x;
    int     y;

    x = 4;
    y = 5;
    image.addr = "images/tree.xpm";
    image.img = mlx_xpm_file_to_image(data->mlx, image.addr, &image.w, &image.h);
    if (data) 
        mlx_put_image_to_window(data->mlx, data->mlx_win, image.img, y*PIXEL, x*PIXEL);
}
