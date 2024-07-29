#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int nb_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	current_time;
	int nb_of_philo_msut_eat;
}	t_info;

typedef struct s_philo
{
	int id_philo;
	int nb_fork;
	pthread_t  	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print_lock;
	t_info *info;
}	t_philo;

int	is_number(char *str);
int	check_arg(char **argv);
int	ft_atoi(const char *str);
long	ft_atol(const char *str);

#endif