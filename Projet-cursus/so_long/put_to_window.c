/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:45:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/07/16 10:09:03 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_obstacle_to_window(char map, int x, int y, t_data *game)
{
	static int	i;

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

void	put_door_to_window(char map, int x, int y, t_data *game)
{
	if (map == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->door, x * 64, y * 64);
	}
}

void	fill_window(char map, int x, int y, t_data *game)
{
	put_wall_to_window(map, x, y, game);
	put_side_wall_to_window(map, x, y, game);
	put_ground_and_collecte(map, x, y, game);
	put_player_to_window(map, x, y, game);
	put_obstacle_to_window(map, x, y, game);
	put_door_to_window(map, x, y, game);
}

void	init_image(t_data *game)
{
	init_wall_image(game);
	init_ground_and_collect_image(game);
	init_player(game);
	init_obstacle(game);
	init_player_top(game);
	init_player_right(game);
	init_player_left(game);
	init_player_down(game);
	init_door(game);
}

void	ft_put_image(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	init_image(game);
	while (game->map->vmap[y])
	{
		x = 0;
		while (game->map->vmap[y][x])
		{
			fill_window(game->map->vmap[y][x], x, y, game);
			x++;
		}
		y++;
	}
}
