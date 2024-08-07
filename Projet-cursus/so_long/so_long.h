/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:15:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/18 11:52:49 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stddef.h>
# include "structure.h"

char	*init_map(int fd);
int		is_solvable(t_map *fullmap);
int		check_map_name(char *map);
int		map_is_valid(char *str);
int		check_width_and_fill(t_map *full_map);
int		check_border_is_wall(char **str);
int		check_map(char *str, t_map *full_map);
int		get_pos_x(t_map *map, char c);
int		get_pos_y(t_map *map, char c);
void	ft_free(t_map *map);
void	load_map(t_map *full_map);
void	init_player_top(t_data *game);
void	init_wall_image(t_data *game);
void	load_map(t_map *full_map);
void	moov_top(t_data *game, int x, int y);
void	init_player_right(t_data *game);
void	moov_right(t_data *game, int x, int y);
void	init_player(t_data *game);
void	init_obstacle(t_data *game);
void	init_door(t_data *game);
void	init_player_left(t_data *game);
void	moov_left(t_data *game, int x, int y);
void	moov_down(t_data *game, int x, int y);
void	init_player_down(t_data *game);
void	ft_put_image(t_data *game);
void	free_image(t_data *win);
void	free_all(t_data *win);
void	loop_game(t_data *win_game);
void	init_ground_and_collect_image(t_data *game);
void	put_door_to_window(char map, int x, int y, t_data *game);
void	put_obstacle_to_window(char map, int x, int y, t_data *game);
void	moove_top_and_down(t_data *data, int key, int *x, int *y);
void	moove_left_and_right(t_data *data, int key, int *x, int *y);
void	put_player_to_window(char map, int x, int y, t_data *game);
void	put_ground_and_collecte(char map, int x, int y, t_data *game);
void	put_side_wall_to_window(char map, int x, int y, t_data *game);
void	put_wall_to_window(char map, int x, int y, t_data *game);
void	destroy(t_data *win, void **image, int len);

#endif