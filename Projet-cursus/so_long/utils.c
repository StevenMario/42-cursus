/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:14:50 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/16 10:00:54 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image(t_data *win)
{
	destroy(win, win->wall, 4);
	destroy(win, win->mur_coter, 4);
	destroy(win, win->obstacle, 3);
	destroy(win, win->player_down, 4);
	destroy(win, win->player_left, 4);
	destroy(win, win->player_right, 4);
	destroy(win, win->player_top, 4);
	mlx_destroy_image(win->mlx_ptr, win->player);
	mlx_destroy_image(win->mlx_ptr, win->door);
	mlx_destroy_image(win->mlx_ptr, win->ground);
	mlx_destroy_image(win->mlx_ptr, win->collect);
}

int	get_pos_x(t_map *map, char c)
{
	int	x;
	int	y;

	y = 0;
	while (map->vmap[y])
	{
		x = 0;
		while (map->vmap[y][x])
		{
			if (map->vmap[y][x] == c)
				return (x);
			x++;
		}
		y++;
	}
	return (x);
}

int	get_pos_y(t_map *map, char c)
{
	int	x;
	int	y;

	y = 0;
	while (map->vmap[y])
	{
		x = 0;
		while (map->vmap[y][x])
		{
			if (map->vmap[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return (y);
}

void	destroy(t_data *win, void **image, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		mlx_destroy_image(win->mlx_ptr, image[i]);
		i++;
	}
}
