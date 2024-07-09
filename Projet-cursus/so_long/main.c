#include "so_long.h"

int ft_put_image(t_data *game)
{
	int x;
	int y;
	int width = 64 , height = 64;

	x = 0;
	y = 0;
	game->img =  mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,game->img,x,y);
	return 1;
}

int 	ft_start_game(t_map *map)
{
	t_data *win_game;

	win_game = malloc (sizeof(t_data));
	win_game->mlx_ptr = mlx_init();
	if (!win_game->mlx_ptr)
	{
		ft_free(map);
		return (0);
	}
	win_game->win_ptr = mlx_new_window(win_game->mlx_ptr, map->width * 64 \
	,map->heigth * 64, "so_long");
	if (!win_game->win_ptr)
	{
		free(win_game->win_ptr);
		ft_free(map);
		return (0);
	}
	ft_put_image(win_game);
	mlx_loop(win_game->mlx_ptr);
	return 1;
}

int main(int argc,char **argv)
{
	t_map map;

	if (argc != 2)
	{
		ft_printf("[Error].Please check argument !\n");
		return (1);
	}
	else 
	{
		if (check_map_name(argv[1]) == 0)
			return (1);
		if (!check_map(argv[1],&map))
			return (1);
		if (!is_solvable(&map))
			return (1);	
		else 
			ft_start_game(&map);
			
	}
	return (0);
}

