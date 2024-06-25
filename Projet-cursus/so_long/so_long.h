#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"

typedef struct s_smap
{
	char *map;
	char **vmap;
	char wall;
	char player;
	char collecte;
	char floor;
	char exit;
	int nb_colecte;
	unsigned int heigth;
	unsigned int width;
}	t_map;

#endif