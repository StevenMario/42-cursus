/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:14:50 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/12 12:57:12 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free(t_map *map)
{
	free(map->map);
	ft_free_str(map->vmap);
	ft_free_str(map->map_copy);
}

void free_image(t_data *win)
{
	destroy(win,win->wall,4);
	destroy(win,win->mur_coter,4);
 	destroy(win,win->obstacle,3);
	mlx_destroy_image(win->mlx_ptr,win->player);
	mlx_destroy_image(win->mlx_ptr,win->door);
	mlx_destroy_image(win->mlx_ptr,win->ground);
	mlx_destroy_image(win->mlx_ptr,win->collect);
}

void destroy(t_data *win,void **image,int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		mlx_destroy_image(win->mlx_ptr,image[i]);
		i++;
	}
}

void free_all(t_data *win)
{
	free_image(win);
	mlx_destroy_window(win->mlx_ptr,win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	ft_free(win->map);
	free(win);
}