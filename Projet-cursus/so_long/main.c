#include "so_long.h"

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

