/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:11:59 by mariosteven       #+#    #+#             */
/*   Updated: 2024/07/11 19:29:17 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_wall_image(t_data *game)
{
	// game->wall[0] = mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur/mur_coter.xpm", 
	// &game->img_height, &game->img_width);
	game->wall[0] = mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur/wall.xpm", 
	&game->img_height, &game->img_width);
	game->wall[1] = mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur/wall_left.xpm", 
	&game->img_height, &game->img_width);
	game->wall[2] = mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur/wall_right.xpm", 
	&game->img_height, &game->img_width);
	game->wall[3] = mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur/wall_top.xpm", 
	&game->img_height, &game->img_width);
	game->mur_coter[0] = mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur/coter_gauche_haut.xpm", 
	&game->img_height, &game->img_width);
	game->mur_coter[1] = mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur/coter_droite_haut.xpm", 
	&game->img_height, &game->img_width);
	game->mur_coter[2] = mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur/coter_gauche_bas.xpm", 
	&game->img_height, &game->img_width);
	game->mur_coter[3] = mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur/coter_droite_bas.xpm", 
	&game->img_height, &game->img_width);
}


void init_ground_and_collect_image(t_data *game)
{
	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "img_xpm/mur/ground.xpm", 
	&game->img_height, &game->img_width);
	// game->collect[0] = mlx_xpm_file_to_image(game->mlx_ptr,"img_xpm/collecte/collect1.xpm",
	// &game->img_height, &game->img_width);
	// game->collect[1] = mlx_xpm_file_to_image(game->mlx_ptr,"img_xpm/collecte/collect2.xpm",
	// &game->img_height, &game->img_width);
	// game->collect[2] = mlx_xpm_file_to_image(game->mlx_ptr,"img_xpm/collecte/collect3.xpm",
	// &game->img_height, &game->img_width);
	// game->collect[3] = mlx_xpm_file_to_image(game->mlx_ptr,"img_xpm/collecte/collect4.xpm",
	// &game->img_height, &game->img_width);
	// game->collect[4] = mlx_xpm_file_to_image(game->mlx_ptr,"img_xpm/collecte/collect5.xpm",
	// &game->img_height, &game->img_width);
	// game->collect[5] = mlx_xpm_file_to_image(game->mlx_ptr,"img_xpm/collecte/collect6.xpm",
	// &game->img_height, &game->img_width);
}

void init_player(t_data *game)
{
    game->player = mlx_xpm_file_to_image(game->mlx_ptr,"img_xpm/perso_down/perso_down1.xpm",
	&game->img_height, &game->img_width);
}
void init_obstacle(t_data *game)
{
    game->obstacle[0] = mlx_xpm_file_to_image(game->mlx_ptr,"img_xpm/obstacle/obstacle1.xpm",
	&game->img_height, &game->img_width);
    game->obstacle[1] = mlx_xpm_file_to_image(game->mlx_ptr,"img_xpm/obstacle/obstacle2.xpm",
	&game->img_height, &game->img_width);
    game->obstacle[2] = mlx_xpm_file_to_image(game->mlx_ptr,"img_xpm/obstacle/obstacle3.xpm",
	&game->img_height, &game->img_width);
}

void init_door(t_data *game)
{
    game->door = mlx_xpm_file_to_image(game->mlx_ptr,"img_xpm/door/exit.xpm",
	&game->img_height, &game->img_width);
}