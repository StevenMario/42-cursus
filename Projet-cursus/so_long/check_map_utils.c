/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:15:56 by mrambelo          #+#    #+#             */
/*   Updated: 2024/06/29 12:35:55 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *init_map(int fd)
{
	char *map;
	char *buf;

	map = ft_strdup("");
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break;
		map = ft_strjoin(map, buf);
		free(buf);
	}
	return (map);
}

void load_map(t_map *full_map)
{
	full_map->map = NULL;
	full_map->vmap = NULL;
	full_map->wall = '1';
	full_map->player = 'P';
	full_map->collecte = 'C';
	full_map->floor = '0';
	full_map->exit = 'E';
	full_map->nb_colecte = 0;
	full_map->heigth = 0;
	full_map->width = 0;
}

int check_width_and_fill(t_map *fullmap)
{
	int i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (fullmap->vmap[i] && fullmap->vmap[i + 1])
	{
		j = ft_strlen(fullmap->vmap[i]);
		k = ft_strlen(fullmap->vmap[i + 1]);
		if (j != k)
			return (0);
		i++;
	}
	fullmap->width = j;
	fullmap->heigth = i + 1;
	return (1);
}

int map_is_valid(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == 'P' || str[i] == 'C' 
			|| str[i] == '0' || str[i] == 'E' || str[i] == '\n')
			i++;
		else 
			return (0);
	}
	return (1);
}

int check_border_is_wall(char **str)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	while (str[i][j])
	{
		if (str[i][j] != '1')
			return 0;
		j++;
	}
	k = ft_strlen(str[i]) - 1;
	j = 0;
	while (str[i])
	{
		if (str[i][j] != '1' || str[i][k] != '1')
			return (0);
		i++;
	}
	i--;
	while (str[i][j])
	{
		if (str[i][j] != '1')
			return 0;
		j++;
	}
	return (1);
}

