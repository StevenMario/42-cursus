/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:58:33 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/12 13:01:01 by mrambelo         ###   ########.fr       */
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