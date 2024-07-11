/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:11:55 by mariosteven       #+#    #+#             */
/*   Updated: 2024/07/11 10:55:41 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_wall_to_window(char map, int x, int y,t_data *game)
{
	if (map == '1' && ( y == 0 ))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->wall[3], x * 64, y * 64);
	}
	else if (map == '1' && ( y == game->map_height - 1))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->wall[0], x * 64, y * 64);
	}
	else if (map == '1' && ( x == 0))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->wall[1], x * 64, y * 64);
	}
	else if (map == '1' && ( x == game->map_width - 1))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->wall[2], x * 64, y * 64);
	}
}
  
void put_side_wall_to_window(char map, int x, int y,t_data *game)
{
	if (map == '1' && (y == 0 && x == 0))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->mur_coter[0], x * 64, y *64);
	}
	else if (map == '1' && (y == 0 && x == game->map_width - 1))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->mur_coter[1], x * 64, y *64);
	}
	else if (map == '1' && (y == game->map_height - 1 && x == 0))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->mur_coter[2], x * 64, y *64);
	}
	else if (map == '1' && (y == game->map_height - 1 && x == game->map_width - 1))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->mur_coter[3], x * 64, y *64);
	}
}



void put_ground_and_collecte(char map, int x, int y,t_data *game)
{
	if (map == '0')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->ground, x * 64, y * 64);
	}
	if (map == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->collect, x * 64, y * 64);
	}
}

void put_player_to_window(char map, int x, int y,t_data *game)
{
	if (map == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->player, x * 64, y * 64);
	}
}

void put_obstacle_to_window(char map, int x, int y,t_data *game)
{
	static int i;
	if (map == '1' && ((y >= 1 && y < game->map_height - 1)
	&& (x >= 1 && x < game->map_width - 1)))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->obstacle[i], x * 64, y * 64);
		i++;
		if (i == 4)
			i = 0;
	}
}

void put_door_to_window(char map, int x, int y,t_data *game)
{
	if (map == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->door, x * 64, y * 64);
	}
}

void fill_window(char map, int x, int y,t_data *game)
{
	put_wall_to_window(map,x,y,game);
	put_side_wall_to_window(map,x,y,game);
	put_ground_and_collecte(map,x,y,game);
	put_player_to_window(map,x,y,game);
	put_obstacle_to_window(map,x,y,game);
	put_door_to_window(map,x,y,game);
}

void ft_put_image(t_map *map,t_data *game)
{
	int x;
	int y;

	y = 0;
	init_wall_image(game);
	init_ground_and_collect_image(game);
	init_player(game);
	init_obstacle(game);
	init_door(game);
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
	win_game->map_height = map->heigth;
	win_game->map_width = map->width;
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

