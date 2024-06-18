#include "minitalk.h"


void stock_char(char c, pid_t pid)
{
	static char *str;
	char tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	if (str == NULL)
		str = ft_strdup("");
	str = ft_strjoin(str,tmp);
	if (c == '\0')
	{
		ft_printf("%s\n",str);
        kill(pid,SIGUSR1);
		free(str);
		str = NULL;
	}

}

void signal_handler(int signum, siginfo_t *info,void *context)
{
	static int i;
	static char c;
    

    
	(void)context;
    if (signum == SIGUSR1)
		c |= 1 << (7 - i);
	i++;
	if ( i > 7)
	{
		stock_char(c,info->si_pid);
		i = 0;
		c = 0;
	}
}

int    main(void)
{
	struct sigaction action;

    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = signal_handler;
    sigemptyset(&action.sa_mask);
    ft_printf("#==================================================#\n");
	ft_printf("        Welcome to mrambelo's mintalk server        \n");
	ft_printf("        Server PID :  %d    \n",getpid());
	ft_printf("#==================================================#\n");
	sigaction(SIGUSR1, &action,NULL);
	sigaction(SIGUSR2, &action,NULL);
	while (1)
	{
		
	}
}