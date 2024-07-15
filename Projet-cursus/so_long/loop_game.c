/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:03:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/15 12:29:29 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void count_step(void)
{
	static int i;
	ft_printf("Step = %d\n",i);
	i++;
}


int	handle_input(int keysym, t_data *data)
{
    int y;
	int x;

	x = get_pos_x(data->map, 'P');
	y = get_pos_y(data->map, 'P');
	if (keysym == 65307)
	{
		free_all(data);
		exit(1);
	}
	else if (keysym == 119 && data->map->vmap[y - 1][x] != '1')
	{
		if ((data->map->vmap[y - 1][x] == 'E' && data->map->nb_colecte > 0))
			return (0);
		if (data->map->vmap[y - 1][x] == 'C')
			data->map->nb_colecte--;
		moov_top(data,x,y);
		count_step();
	}	
	else if (keysym == 100 && data->map->vmap[y][x + 1] != '1')
	{
		if ((data->map->vmap[y][x + 1] == 'E' && data->map->nb_colecte > 0))
			return (0);
		if (data->map->vmap[y][x + 1] == 'C')
			data->map->nb_colecte--;
		moov_right(data,x,y);
		count_step();
	}
	else if (keysym == 97 && data->map->vmap[y][x - 1] != '1' )
	{
		if ((data->map->vmap[y][x - 1] == 'E' && data->map->nb_colecte > 0))
			return (0);
		if (data->map->vmap[y][x - 1] == 'C')
			data->map->nb_colecte--;
		moov_left(data,x,y);
		count_step();
	}
	else if (keysym == 115 && data->map->vmap[y + 1][x] != '1')
	{
		if (data->map->vmap[y + 1][x] == 'E' && data->map->nb_colecte > 0)
			return (0);
		if (data->map->vmap[y + 1][x] == 'C')
			data->map->nb_colecte--;
		moov_down(data,x,y);
		count_step();
	}
    return (0);
}

int close_window(t_data *win)
{
	free_all(win);
	exit(0);
}

void loop_game(t_data *win_game)
{
	ft_put_image(win_game);
	mlx_hook(win_game->win_ptr, 17, 0,close_window,win_game);
	mlx_key_hook(win_game->win_ptr, handle_input, win_game);
	mlx_loop(win_game->mlx_ptr);
}