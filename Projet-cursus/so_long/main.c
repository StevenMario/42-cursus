#include "so_long.h"

void fill_window(char map, int x, int y,t_data *game)
{
	
	if (map == '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img, x * 64, y *64);
	}
	else if (map == '0')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img, x * 64, y * 64);
	}
	else if (map == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img, x * 64, y * 64);
	}
	else if (map == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img, x * 64, y * 64);
	}
	else if (map == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img, x * 64, y * 64);
	}
	//return 1;
}

void ft_put_image(t_map *map,t_data *game)
{
	int x;
	int y;

	y = 0;
	game->img = mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur/ice_wall.xpm", \
	&game->img_height, &game->img_width);
	while (map->vmap[y])
	{
		x = 0;
		while (map->vmap[y][x])
		{
			fill_window(map->vmap[y][x],x,y,game);
			x++;
		}
		y++;
	}
	//return 1;
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
		mlx_destroy_display(win_game->win_ptr);
		free(win_game->win_ptr);
		ft_free(map);
		return (0);
	}
	ft_put_image(map,win_game);
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

