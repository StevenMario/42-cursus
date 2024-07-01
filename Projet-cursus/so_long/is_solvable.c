/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:38:57 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/01 11:02:05 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_pos_x(t_map *fullmap, char c)
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

int get_pos_y(t_map *fullmap, char c)
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

int ft_get_near(t_map *fullmap, unsigned int x, unsigned int y)
{
	if (x + 1 <= fullmap->width && fullmap->vmap[y][x + 1] == 'F')
		return 1;
	if (fullmap->vmap[y][x - 1] == 'F')
		return 1;
	if (fullmap->vmap[y - 1][x] == 'F')
		return 1;
	if (y + 1 < fullmap->heigth && fullmap->vmap[y + 1][x] == 'F')
		return 1;
	return 0;
}

void fill_map(t_map *fullmap, unsigned int x, unsigned int y)
{
	fullmap->vmap[y][x] = 'F';
}

// void ft_recursive_map(t_map *fullmap)
// {
// 	unsigned int x;
// 	unsigned int y;

// 	y = 1;
// 	while (y < fullmap->heigth - 1)
// 	{
// 		x = 1;
// 		while (x < fullmap->width - 1)
// 		{
// 			// printf(" get nrear %d\n",ft_get_near(fullmap,x,y));
// 			if (ft_get_near(fullmap, x, y) && fullmap->vmap[y][x] != '1' && fullmap->vmap[y][x] != 'F')
// 			{
// 				fill_map(fullmap, x, y);
// 				// ft_recursive_map(fullmap);
// 			}
// 			printf("x = %d\n", x);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void ft_fill(t_map *fullmap, unsigned int x, unsigned int y)
{
	if (y < 1 || y >= fullmap->heigth - 1 || x < 1 || x >= fullmap->width - 1 || (fullmap->vmap[y][x] != '0' && fullmap->vmap[y][x] != 'C' && fullmap->vmap[y][x] != 'E'))
		return;
	fill_map(fullmap, x, y);
	ft_fill(fullmap, x - 1, y);
	ft_fill(fullmap, x + 1, y);
	ft_fill(fullmap, x, y - 1);
	ft_fill(fullmap, x, y + 1);
}

int is_solvable(t_map *fullmap)
{
	unsigned int player_x;
	unsigned int player_y;
	int i = 0;
	t_map tmp;

	tmp = *fullmap;
	player_x = get_pos_x(&tmp, 'P');
	player_y = get_pos_y(&tmp, 'P');
	fill_map(&tmp, player_x, player_y);
	ft_fill(&tmp, 1, 1);
	//ft_recursive_map(&tmp);
	while (tmp.vmap[i])
	{
		printf("%s\n", tmp.vmap[i]);
		i++;
	}
	return 1;
}