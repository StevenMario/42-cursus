/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:16:04 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/18 11:47:49 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_name(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	if (map[i] == 'r' && map[i - 1] == 'e'
		&& map[i - 2] == 'b' && map[i - 3] == '.')
		return (1);
	ft_printf("[Error].Please check mapname !\n");
	return (0);
}

int	check_exit_player_and_collecte(t_map *full_map)
{
	int	i;
	int	exit;
	int	player;

	player = 0;
	exit = 0;
	i = 0;
	while (full_map->map[i])
	{
		if (full_map->map[i] == 'E')
			exit++;
		if (full_map->map[i] == 'P')
			player++;
		if (full_map->map[i] == 'C')
			full_map->nb_colecte++;
		i++;
	}
	if (exit > 1 || player != 1 || full_map->nb_colecte == 0)
		return (0);
	return (1);
}

void	fill_and_init_map(t_map *full_map, int fd)
{
	full_map->map = init_map(fd);
	full_map->vmap = ft_split(full_map->map, '\n');
	full_map->map_copy = ft_split(full_map->map, '\n');
}

int	map_is_so_big(t_map *full_map)
{
	if (full_map->width * 64 > 1920 || full_map->heigth * 64 > 1080)
	{
		ft_printf("[Error].Your map is too big !\n");
		ft_free(full_map);
		return (0);
	}
	return (1);
}

int	check_map(char *str, t_map *full_map)
{
	int	fd;

	load_map(full_map);
	fd = open(str, O_RDONLY);
	if (fd >= 3)
	{
		fill_and_init_map(full_map, fd);
		if (!map_is_valid(full_map->map) || !check_width_and_fill(full_map))
		{
			ft_printf("[Error].Please check your map !\n");
			return (ft_free(full_map), 0);
		}
		if (!map_is_so_big(full_map))
			return (0);
		if (!check_border_is_wall(full_map->vmap)
			|| !check_exit_player_and_collecte(full_map))
		{
			ft_printf("[Error].Please check your map !\n");
			return (ft_free(full_map), 0);
		}
		return (1);
	}
	else
		return (0);
}
