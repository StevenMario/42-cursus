#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
    int nb_philo;
    int nb_fork;
    int nb_of_philo_must_eat;
} t_philo;

int	is_number(char *str);
int	check_arg(char **argv);
int	ft_atoi(const char *str);

#endif