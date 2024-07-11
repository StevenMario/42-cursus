/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:45:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/07/11 14:44:08 by mariosteven      ###   ########.fr       */
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
	// int i;
    // i = 0;
    if (map == '0')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->ground, x * 64, y * 64);
	}
	if (map == 'C')
	{
		// while(1)
        // {
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		    game->collect[0], x * 64, y * 64);
            // i++;
        //     if (i == 6)
        //         i = 0;
        // }
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
		if (i == 3)
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