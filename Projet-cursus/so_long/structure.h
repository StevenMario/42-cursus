/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:51:12 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/16 10:02:47 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_smap
{
	char			*map;
	char			**vmap;
	char			**map_copy;
	char			wall;
	char			player;
	char			collecte;
	char			floor;
	char			exit;
	int				nb_colecte;
	unsigned int	heigth;
	unsigned int	width;
}	t_map;

typedef struct s_data
{
	int		img_width;
	int		img_height;
	int		map_width;
	int		map_height;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall[4];
	void	*mur_coter[4];
	void	*player;
	void	*player_top[4];
	void	*player_right[4];
	void	*player_left[4];
	void	*player_down[4];
	void	*obstacle[3];
	void	*collect;
	void	*door;
	void	*ground;
	t_map	*map;
}	t_data;

#endif