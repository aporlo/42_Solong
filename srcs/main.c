#include "so_long.h"


int main(int argc, char **argv)
{
    char   **mapfile;
    t_data  data;
    // void	*mlx;
	// void	*mlx_win;
    t_image	img;
    // char	*relative_path = "images/wall.xpm";
    // int		img_width;
	// int		img_height;

    if (argc == 1)
        error_file("Error\n no args");
    if (argc == 2)
    {
        read_map(&data, argv[1]);
        printf("hello");
    }
        
        // mapfile = argv[1];
    ft_printf("h1>>%d\n", data.map.height);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 800, 600, "Aporlo World");
    create_floor(&data, img);
    create_wall(&data, img);
    create_item(&data, img);
    create_tree(&data, img);
    // img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    // mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(data.mlx);
}