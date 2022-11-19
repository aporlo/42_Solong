#include "so_long.h"


int main(int argc, char **argv)
{
    char   **map;
    t_data  data;
    void	*mlx;
	void	*mlx_win;

    if (argc == 1)
        error_file("Error\n no args");
    if (argc == 2)
        map = read_map(data, argv[1]);
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}