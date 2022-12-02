#include "so_long.h"

void    render_player(t_data *data, t_player *p)
{
    mlx_put_image_to_window(data->mlx, data->mlx_win, p->img.ptr, p->v.y*PIXEL, p->v.x*PIXEL);
}

void    render_exit(t_data *data, t_player *e)
{
    mlx_put_image_to_window(data->mlx, data->mlx_win, e->img.ptr, e->v.y*PIXEL, e->v.x*PIXEL);
}

void    render_floor(t_data *data, t_list *floor)
{
    t_pix   *temp;

    while (floor != NULL)
    {
        temp = (t_pix *)floor->content;
        mlx_put_image_to_window(data->mlx, data->mlx_win, temp->img.ptr, temp->v.y*PIXEL, temp->v.x*PIXEL);
        floor = floor->next;
    }
}