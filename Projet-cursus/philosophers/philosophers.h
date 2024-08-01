#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int id_philo;
	int l_fork;
	int r_fork;
	int	nb_eat;
	pthread_t  	philo;
}	t_philo;

typedef struct s_info
{
	int		nb_philo;
	int		status;
	long	start_time;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	current_time;
	int		nb_of_philo_msut_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	dead_lock;
	t_philo *philosophe;
}	t_info;

int	is_number(char *str);
int	check_arg(char **argv);
int	ft_atoi(const char *str);
int init_fork_mutex(t_info **info);
int init_other_mutex(t_info **info);
int init_all(char **argv,t_info **info);
int init_struct(char **argv,t_info **info);
long	ft_atol(const char *str);

#endif

