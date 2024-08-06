/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:32 by mrambelo          #+#    #+#             */
/*   Updated: 2024/08/06 11:17:50 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H
# define EAT 0
# define TAKE_FORK 1
# define SLEEP 2
# define THINK 3
# define DEAD 4
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_info t_info;

typedef struct s_philo
{
	int id_philo;
	int	nb_eat;
	long last_eat;
	pthread_t  	philo;
	t_info		*info;
}	t_philo;

struct s_info
{
	int		nb_philo;
	int		status;
	long	start_time;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		nb_of_philo_must_eat;
	pthread_t  	check_death;
	pthread_mutex_t	*fork;
	pthread_mutex_t	eat_lock;
	t_philo *philosophe;
};

int	is_number(char *str);
int	check_arg(char **argv);
int	ft_atoi(const char *str);
int	ft_usleep (long millisecondes);
int	is_dead(t_philo *philo);
int	init_fork_mutex(t_info **info);
int	init_all(char **argv,t_info **info);
int	init_struct(char **argv,t_info **info);
long	ft_atol(const char *str);
long	ft_get_current_time(void);
void	ft_think(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_printf_status(int status,t_philo *philo);
void	ft_take_fork(t_philo *philo, int l_fork, int r_fork);
#endif

