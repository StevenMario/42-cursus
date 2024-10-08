/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:05:27 by mariosteven       #+#    #+#             */
/*   Updated: 2024/08/26 09:29:53 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(const char *str)
{
	long	i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

long	ft_get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		printf("gettimeofday() error\n");
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(long millisecondes, t_philo *philo)
{
	long	start;

	start = ft_get_current_time();
	while ((ft_get_current_time() - start) < millisecondes)
	{
		if (check_status(philo) == 1)
			break ;
		usleep(1);
	}
	return (0);
}

void	ft_printf_status(int status, t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(&philo->info->mutex);
	current_time = ft_get_current_time() - philo->info->start_time;
	if (!check_status(philo))
	{
		if (status == TAKE_FORK)
			printf("\033[38;5;245m%ld  %d has taken a fork\n", current_time,
				philo->id_philo);
		else if (status == EAT)
			printf("\033[34m%ld  %d is eating\n", current_time,
				philo->id_philo);
		else if (status == SLEEP)
			printf("\033[32m%ld  %d is sleeping\n", current_time,
				philo->id_philo);
		else if (status == THINK)
			printf("\033[38;5;213m%ld  %d is thinking\n", current_time,
				philo->id_philo);
	}
	pthread_mutex_unlock(&philo->info->mutex);
}
