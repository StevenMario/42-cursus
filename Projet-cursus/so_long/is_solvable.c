/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:38:57 by mrambelo          #+#    #+#             */
/*   Updated: 2024/06/29 12:56:57 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_pos_x(t_map *fullmap,char c)
{
	int x;
	int y;

	y = 0;
	while (fullmap->vmap[y])
	{
		x = 0;
		while (fullmap->vmap[y][x])
		{
			if (fullmap->vmap[y][x] == c)
				return (x);
			x++;
		}
		y++;
	}
	return 0;
}

int get_pos_y(t_map *fullmap,char c)
{
	int x;
	int y;

	y = 0;
	while (fullmap->vmap[y])
	{
		x = 0;
		while (fullmap->vmap[y][x])
		{
			if (fullmap->vmap[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return 0;
}

int is_solvable(t_map *fullmap)
{
	int player_x;
	int player_y;

	player_x = get_pos_x(fullmap,'P');
	player_y = get_pos_y(fullmap,'P');
	printf("player_x = %d   ,player_y = %d",player_x,player_y);
	return 1;
}