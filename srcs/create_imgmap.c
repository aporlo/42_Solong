#include "so_long.h"
void    print_linklist(t_list *profile);

void    create_floor(t_data *data, t_image image)
{
    int         x;
    int         y;
    t_pix       *content;
    t_list      *new_data;

    x = 0;
    data->floor = NULL;
    while(x < data->map.height)
    {
        y = 0;
        while (y < data->map.width)
        {
            if(data->map.grid[x][y]) 
            {
                content = malloc(sizeof(t_pix));
                content->v.x = x;
                content->v.y = y;
                content->img.ptr = mlx_xpm_file_to_image(data->mlx, "images/floor.xpm", &image.w, &image.h);
                new_data = ft_lstnew(content);
                ft_lstadd_back(&data->floor, new_data);
            }
            y++;
        }
        x++;
    }
    render_floor(data, data->floor);
}

void    create_wall(t_data *data, t_image image)
{
    int         x;
    int         y;
    t_pix       *content;
    t_list      *new_data;

    x = 0;
    data->wall = NULL;
    while(x < data->map.height)
    {
        y = 0;
        while (y < data->map.width)
        {
            if(data->map.grid[x][y]) 
            {
                if (data->map.grid[x][y] == '1')
                {
                    content = malloc(sizeof(t_pix));
                    content->v.x = x;
                    content->v.y = y;
                    content->img.ptr = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm", &image.w, &image.h);
                    new_data = ft_lstnew(content);
                    ft_lstadd_back(&data->wall, new_data);
                }
            }
            y++;
        }
        x++;
    }
    render_floor(data, data->wall);
}

void    create_item(t_data *data, t_image image)
{
    int         x;
    int         y;
    t_pix       *content;
    t_list      *new_data;

    x = 0;
    data->item = NULL;
    while(x < data->map.height)
    {
        y = 0;
        while (y < data->map.width)
        {
            if(data->map.grid[x][y]) 
            {
                if (data->map.grid[x][y] == 'C')
                {
                    content = malloc(sizeof(t_pix));
                    content->v.x = x;
                    content->v.y = y;
                    content->img.ptr = mlx_xpm_file_to_image(data->mlx, "images/carrot01.xpm", &image.w, &image.h);
                    new_data = ft_lstnew(content);
                    ft_lstadd_back(&data->item, new_data);
                }
            }
            y++;
        }
        x++;
    }
    render_floor(data, data->item);
}

void    create_player(t_data *data, t_image image)
{
    int     x;
    int     y;
    t_player    *p;

    x = 0;
    while(x < data->map.height)
    {
        y = 0;
        while (y < data->map.width)
        {
            if(data->map.grid[x][y]) 
            {
                if (data->map.grid[x][y] == 'P')
                {
                    p->addr = "images/01-player.xpm";
                    p->v.x = x;
                    p->v.y = y;
                    p->img.ptr = mlx_xpm_file_to_image(data->mlx, p->addr, &image.w, &image.h);
                }
            }
            y++;
        }
        x++;
    }
    render_player(data, p);
}

void    create_exit(t_data *data, t_image image)
{
    int     x;
    int     y;
    t_player    *e;

    x = 0;
    while(x < data->map.height)
    {
        y = 0;
        while (y < data->map.width)
        {
            if(data->map.grid[x][y]) 
            {
                if (data->map.grid[x][y] == 'E')
                {
                    e->addr = "images/door.xpm";
                    e->v.x = x;
                    e->v.y = y;
                    e->img.ptr = mlx_xpm_file_to_image(data->mlx, e->addr, &image.w, &image.h);
                }
            }
            y++;
        }
        x++;
    }
    render_player(data, e);
}

void    print_linklist(t_list *profile)
{
    t_pix    *temp;
    while(profile != NULL)
    {
        temp = (t_pix *)profile->content;
        printf("vector x is %d ,", temp->v.x);
        printf(" %d\n", temp->v.y);
        profile = profile->next;
    }
    printf("NULL\n");
}