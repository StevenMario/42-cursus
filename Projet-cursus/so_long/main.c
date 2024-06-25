#include "so_long.h"

int check_map_name(char *map)
{
	int i;
	i = 0;
	while (map[i])
		i++;
	i--;
	if (map[i] == 'r' && map[i - 1] == 'e'
		&& map[i - 2] == 'b' && map[i - 3] == '.')
		return (1);
	return 0;
}

char *init_map(int fd)
{
	char *map;
	char *buf;

	map = ft_strdup("");
	buf = ft_strdup("");
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break;
		map = ft_strjoin(map, buf);
		free(buf);
	}
	return (map);
}

void load_map(t_map *bmap)
{
	bmap->map = NULL;
	bmap->vmap = NULL;
	bmap->wall = '1';
	bmap->player = 'P';
	bmap->collecte = 'C';
	bmap->floor = '0';
	bmap->exit = 'E';
	bmap->nb_colecte = 0;
	bmap->heigth = 0;
	bmap->width = 0;
}

int check_map(char *str)
{
	t_map bmap;
	int fd ;
	
	load_map(&bmap);
	fd = open(str,O_RDONLY);
	if (fd >= 3)
	{
		bmap.map = init_map(fd);
		// check_map_width(map->vmap);
		printf("%s",bmap.map);
		
		return (1);
	}
	else
		return (0);
}


int main(int argc,char **argv)
{
	if (argc != 2)
	{
		ft_printf("[Error].Please check argument !");
		return (1);
	}
	else 
	{
		if (check_map_name(argv[1]) == 0)
		{	
			ft_printf("[Error].Please check mapname !");
			return (1);
		}
		else
			check_map(argv[1]);
	}
	return (0);
}

