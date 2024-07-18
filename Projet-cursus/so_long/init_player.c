/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:36:05 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/18 10:22:39 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_data *game)
{
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_down/perso_down1.xpm",
			&game->img_height, &game->img_width);
}

void	init_player_top(t_data *game)
{
	game->player_top[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_top/perso_top1.xpm",
			&game->img_height, &game->img_width);
	game->player_top[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_top/perso_top2.xpm",
			&game->img_height, &game->img_width);
	game->player_top[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_top/perso_top3.xpm",
			&game->img_height, &game->img_width);
	game->player_top[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_top/perso_top4.xpm",
			&game->img_height, &game->img_width);
}

void	init_player_right(t_data *game)
{
	game->player_right[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_right/perso_right1.xpm",
			&game->img_height, &game->img_width);
	game->player_right[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_right/perso_right2.xpm",
			&game->img_height, &game->img_width);
	game->player_right[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_right/perso_right3.xpm",
			&game->img_height, &game->img_width);
	game->player_right[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_right/perso_right4.xpm",
			&game->img_height, &game->img_width);
}

void	init_player_left(t_data *game)
{
	game->player_left[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_left/perso_left1.xpm",
			&game->img_height, &game->img_width);
	game->player_left[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_left/perso_left2.xpm",
			&game->img_height, &game->img_width);
	game->player_left[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_left/perso_left3.xpm",
			&game->img_height, &game->img_width);
	game->player_left[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_left/perso_left4.xpm",
			&game->img_height, &game->img_width);
}

void	init_player_down(t_data *game)
{
	game->player_down[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_down/perso_down1.xpm",
			&game->img_height, &game->img_width);
	game->player_down[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_down/perso_down2.xpm",
			&game->img_height, &game->img_width);
	game->player_down[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_down/perso_down3.xpm",
			&game->img_height, &game->img_width);
	game->player_down[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"img_xpm/perso_down/perso_down4.xpm",
			&game->img_height, &game->img_width);
}
