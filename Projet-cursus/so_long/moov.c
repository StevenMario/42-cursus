/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:33:24 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/16 11:07:09 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_finished(t_data *game)
{
	free_all(game);
	ft_printf("FINISHED !!!\n");
	exit(1);
}

void	moov_top(t_data *game, int x, int y)
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
	if (game->map->vmap[y - 1][x] == 'E')
		is_finished(game);
	game->map->vmap[y][x] = '0';
	game->map->vmap[y - 1][x] = 'P';
}

void	moov_right(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_right[0], x * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_right[1], x * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->ground, x * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_right[2], (x + 1) * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_right[3], (x + 1) * 64, y * 64);
	if (game->map->vmap[y][x + 1] == 'E')
		is_finished(game);
	game->map->vmap[y][x] = '0';
	game->map->vmap[y][x + 1] = 'P';
}

void	moov_left(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_left[0], x * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_left[1], x * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->ground, x * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_left[2], (x - 1) * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_left[3], (x - 1) * 64, y * 64);
	if (game->map->vmap[y][x - 1] == 'E')
		is_finished(game);
	game->map->vmap[y][x] = '0';
	game->map->vmap[y][x - 1] = 'P';
}

void	moov_down(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_down[0], x * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_down[1], x * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->ground, x * 64, y * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_down[2], x * 64, (y + 1) * 64);
	usleep(50000);
	mlx_do_sync(game->mlx_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_down[3], x * 64, (y + 1) * 64);
	if (game->map->vmap[y + 1][x] == 'E')
		is_finished(game);
	game->map->vmap[y][x] = '0';
	game->map->vmap[y + 1][x] = 'P';
}
