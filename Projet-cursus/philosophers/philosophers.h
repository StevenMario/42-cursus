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
	pthread_mutex_t	*fork;
	pthread_mutex_t	eat_lock;
	t_philo *philosophe;
};

int	is_number(char *str);
int	check_arg(char **argv);
int	ft_atoi(const char *str);
int	ft_usleep (long millisecondes);
int init_fork_mutex(t_info **info);
int init_all(char **argv,t_info **info);
int init_struct(char **argv,t_info **info);
long	ft_atol(const char *str);
long ft_get_current_time(void);
void	ft_printf_status(int status,t_philo *philo);

#endif

