/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:06:32 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/18 12:51:35 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_step(void)
{
	static int	i;

	ft_printf("Step = %d\n", i + 1);
	i++;
}

void	moove_top_and_down(t_data *data, int key, int *x, int *y)
{
	if (key == 119 && data->map->vmap[*y - 1][*x] != '1')
	{
		if ((data->map->vmap[*y - 1][*x] == 'E' && data->map->nb_colecte > 0))
			return ;
		if (data->map->vmap[*y - 1][*x] == 'C')
			data->map->nb_colecte--;
		moov_top(data, *x, *y);
		count_step();
	}
	else if (key == 115 && data->map->vmap[*y + 1][*x] != '1')
	{
		if (data->map->vmap[*y + 1][*x] == 'E' && data->map->nb_colecte > 0)
			return ;
		if (data->map->vmap[*y + 1][*x] == 'C')
			data->map->nb_colecte--;
		moov_down(data, *x, *y);
		count_step();
	}
}

void	moove_left_and_right(t_data *data, int key, int *x, int *y)
{
	if (key == 100 && data->map->vmap[*y][*x + 1] != '1')
	{
		if ((data->map->vmap[*y][*x + 1] == 'E' && data->map->nb_colecte > 0))
			return ;
		if (data->map->vmap[*y][*x + 1] == 'C')
			data->map->nb_colecte--;
		moov_right(data, *x, *y);
		count_step();
	}
	else if (key == 97 && data->map->vmap[*y][*x - 1] != '1' )
	{
		if ((data->map->vmap[*y][*x - 1] == 'E' && data->map->nb_colecte > 0))
			return ;
		if (data->map->vmap[*y][*x - 1] == 'C')
			data->map->nb_colecte--;
		moov_left(data, *x, *y);
		count_step();
	}
}
