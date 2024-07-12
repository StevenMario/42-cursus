/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:03:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/12 13:04:28 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_data *data)
{
    //  printf("keysym = %d\n",keysym);
	//  printf("data = %d",data->img_height);
	if (keysym == 65307)
	{
		free_all(data);
		exit(1);
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
	mlx_key_hook(win_game->win_ptr, handle_input, win_game);
	mlx_hook(win_game->win_ptr, 17, 0,close_window,win_game);
	mlx_loop(win_game->mlx_ptr);
}