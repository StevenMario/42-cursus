/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:56:23 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/18 11:01:37 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_map *map)
{
	free(map->map);
	ft_free_str(map->vmap);
	ft_free_str(map->map_copy);
}

void	free_all(t_data *win)
{
	free_image(win);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	ft_free(win->map);
	free(win);
}
