#include "so_long.h"

int main(int argc,char **argv)
{
	t_map map;

	if (argc != 2)
	{
		ft_printf("[Error].Please check argument !\n");
		return (1);
	}
	else 
	{
		if (check_map_name(argv[1]) == 0)
		{	
			ft_printf("[Error].Please check mapname !\n");
			return (1);
		}
		if (!check_map(argv[1],&map))
			return (1);
		if (!is_solvable(&map))
			printf("map is not solvable\n");
		else 
			printf("map is  solvable");	
		//ft_free(&map);
			
	}
	return (0);
}

