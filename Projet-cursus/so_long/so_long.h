/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:15:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/10 12:36:25 by mrambelo         ###   ########.fr       */
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
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_wall[5];
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


#endif