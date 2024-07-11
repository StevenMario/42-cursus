/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:11:55 by mariosteven       #+#    #+#             */
/*   Updated: 2024/07/11 12:46:06 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



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

