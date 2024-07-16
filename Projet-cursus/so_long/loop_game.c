/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:03:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/16 11:11:32 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_data *data)
{
	int	y;
	int	x;

	x = get_pos_x(data->map, 'P');
	y = get_pos_y(data->map, 'P');
	if (keysym == 65307)
	{
		free_all(data);
		exit(1);
	}
	else if (keysym == 119 || keysym == 115)
		moove_top_and_down(data, keysym, &x, &y);
	else if (keysym == 100 || keysym == 97)
		moove_left_and_right(data, keysym, &x, &y);
	return (0);
}

int	close_window(t_data *win)
{
	free_all(win);
	exit(0);
}

void	loop_game(t_data *win_game)
{
	ft_put_image(win_game);
	mlx_hook(win_game->win_ptr, 17, 0, close_window, win_game);
	mlx_key_hook(win_game->win_ptr, handle_input, win_game);
	mlx_loop(win_game->mlx_ptr);
}
