/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:38:57 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/01 13:01:53 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_wall(t_map *fullmap ,unsigned int x, unsigned int y)
{
	if (fullmap->map_copy[y][x] != '0' && fullmap->map_copy[y][x] != 'C' 
		&& fullmap->map_copy[y][x] != 'E' && fullmap->map_copy[y][x] != 'P')
		return (1);
	return 0;
}

void ft_fill(t_map *fullmap, unsigned int x, unsigned int y)
{
	if (y < 1 || y >= fullmap->heigth - 1 || x < 1 
		|| x >= fullmap->width - 1 || is_wall(fullmap,x,y))
		return;
	fullmap->map_copy[y][x] = 'F';
	ft_fill(fullmap, x - 1, y);
	ft_fill(fullmap, x + 1, y);
	ft_fill(fullmap, x, y - 1);
	ft_fill(fullmap, x, y + 1);
}

int is_solvable(t_map *fullmap)
{
	int i;
	int j;
	
	i = 0;
	
	ft_fill(fullmap, 1, 1);
	while (fullmap->map_copy[i])
	{
		j = 0;
		while (fullmap->map_copy[i][j])
		{
			if (fullmap->map_copy[i][j] == 'C' || fullmap->map_copy[i][j] == 'P'
				|| fullmap->map_copy[i][j] == 'E')
			{
				ft_free(fullmap);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}