/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:14:01 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/31 15:18:22 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_struct(char **argv,t_info **info)
{
	*info = malloc(sizeof(t_info));
	if (!*info)
		return (0);
	(*info)->nb_philo = ft_atoi(argv[1]);
	(*info)->time_to_die = ft_atol(argv[2]);
	(*info)->time_to_eat = ft_atol(argv[3]);
	(*info)->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		(*info)->nb_of_philo_msut_eat = ft_atoi(argv[5]);
	(*info)->status = 0;
	return (1);
}

int init_mutex(t_info **info)
{
	int i;

	i = 0;
	while (i <= (*info)->nb_philo)
	{
		(*info)->fork[i]; 
	}
}

int	main(int argc, char **argv)
{
	t_info *info;
	
	if (argc == 5 || argc == 6)
	{
		if (!check_arg(argv))
			printf("[Error].Please check the arguments!\n");
		else 
		{
			if (!init_struct(argv,&info))
			{
				free(info);
				printf("Allocation error!");
				return (1);
			}
			if (!init_mutex(&info))
			{
				free(info);
				printf("Allocation error!");
				return (1);
			}
			
		}	
	}
	else
	{
		printf("[Error].Please check the number of arguments!\n");
		return (1);
	}
}