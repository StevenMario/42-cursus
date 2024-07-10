/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:15:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/10 21:39:59 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stddef.h>

typedef struct s_smap
{
	char *map;
	char **vmap;
	char **map_copy;
	char wall;
	char player;
	char collecte;
	char floor;
	char exit;
	int nb_colecte;
	unsigned int heigth;
	unsigned int width;
}	t_map;

typedef struct s_data
{
	int			img_width;
	int 		img_height;
	int			map_width;
	int 		map_height;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*wall[5];
	void		*player;
	void		*obstacle[4];
	void		*collect;
	void		*door;
	void		*ground;
}	t_data;

char *init_map(int fd);
int is_solvable(t_map *fullmap);
int check_map_name(char *map);
int map_is_valid(char *str);
int check_width_and_fill(t_map *full_map);
int check_border_is_wall(char **str);
int check_map(char *str,t_map *full_map);
void ft_free(t_map *map);
void load_map(t_map *full_map);
void init_wall_image(t_data *game);
void init_player(t_data *game);
void init_obstacle(t_data *game);
void init_door(t_data *game);
void init_ground_and_collect_image(t_data *game);

#endif