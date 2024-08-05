/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:14:01 by mrambelo          #+#    #+#             */
/*   Updated: 2024/08/05 20:24:58 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_eat(t_philo *philo)
{
	int	l_fork;
	int r_fork;

	l_fork = philo->id_philo - 1;
	r_fork = philo->id_philo % philo->info->nb_philo;

	if (philo->id_philo % 2 == 0)
	{
		pthread_mutex_lock(&philo->info->fork[l_fork]);
		ft_printf_status(TAKE_FORK,philo);
		pthread_mutex_lock(&philo->info->fork[r_fork]);
		ft_printf_status(TAKE_FORK,philo);
	}
	else 
	{
		pthread_mutex_lock(&philo->info->fork[r_fork]);
		ft_printf_status(TAKE_FORK,philo);
		pthread_mutex_lock(&philo->info->fork[l_fork]);
		ft_printf_status(TAKE_FORK,philo);
	}
	ft_printf_status(EAT,philo);
	philo->nb_eat++;
	if (nb)
	printf("id_philo = %d,  nb_eat = %d\n",philo->id_philo,philo->nb_eat);
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->info->fork[l_fork]);
	pthread_mutex_unlock(&philo->info->fork[r_fork]);
}

void ft_sleep(t_philo *philo)
{
	//pthread_mutex_lock(&philo->info->print_lock);
	ft_printf_status(SLEEP,philo);
	ft_usleep(philo->info->time_to_sleep);
	//pthread_mutex_unlock(&philo->info->print_lock);
}

void ft_think(t_philo *philo)
{
	/*long	time_to_think;

	time_to_think = philo->info->time_to_die - 
		(philo->info->time_to_eat + philo->info->time_to_sleep);*/
	//pthread_mutex_lock(&philo->info->print_lock);
	ft_printf_status(THINK,philo);
	//ft_usleep(time_to_think);
	//pthread_mutex_unlock(&philo->info->print_lock);
}

void *routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id_philo % 2 == 0)
		usleep(1000);
	while (1)
	{
		ft_think(philo);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return NULL;
}



int ft_start(t_info **info)
{
	int	i;

	i = 0;
	(*info)->philosophe = malloc(sizeof(t_philo) * (*info)->nb_philo);
	(*info)->start_time = ft_get_current_time();
	while (i < (*info)->nb_philo)
	{
		(*info)->philosophe[i].id_philo = i + 1;
		(*info)->philosophe[i].info = (*info);
		if (pthread_create(&(*info)->philosophe[i].philo,NULL,&routine, &(*info)->philosophe[i]) != 0)
			return (0);
		i++;	
	}
	i = 0;
	while (i < (*info)->nb_philo)
	{
	if (pthread_join((*info)->philosophe[i].philo,NULL) != 0)
			return (0);
		i++;
	}
	return (1);	
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
			if (!init_all(argv,&info))
				return (1);
			ft_start(&info);
		}
	}
	else
	{
		printf("[Error].Please check the number of arguments!\n");
		return (1);
	}
}