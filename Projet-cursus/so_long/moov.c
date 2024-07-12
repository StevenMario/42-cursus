/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:33:24 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/12 15:05:22 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void moov_top(t_data *game,int x,int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
	game->player_top[0], x * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
	game->player_top[1], x * 64, y * 64);
	usleep(50000); 
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
	game->ground, x * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
	game->player_top[2], x * 64, (y - 1) * 64);
	usleep(50000); 
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
	game->player_top[3], x * 64, (y - 1) * 64);
	game->map->vmap[y][x] = '0';
	game->map->vmap[y - 1][x] = 'P';
}