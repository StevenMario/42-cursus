/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:46:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/03 13:40:19 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack *fill_stack(t_stack **a, int *nbr)
{
    int i;
	t_stack *new;

    i = 0;
	ft_double_lstnew(&a,int *data)
    while (i < size_new_str(check_arg(argv)))
    {
		new = ft_double_lstnew(&a,nbr[i])
		new->data[2] = i;
		if (new->next == NULL)
			ft
    }
}
void fill_stack_a(int *new_arg)
{
	int i;
	t_stack *a;

	*a = NULL;
	
}
int	*convert_str(char **str)
{
	int i;
	int	*nbr;

	i = 0;
	while (str[i] != NULL)
		i++;
	nbr = malloc(sizeof(int) * i);
	i = 0;
	while (str[i] != NULL)
	{
		if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
			return (NULL);
		nbr[i] = (int)ft_atoi(str[i]);
		i++;
	}
	return (nbr);
}

int *char_to_int(char **new_str)
{
	int	*new_arg;
	
	new_arg = convert_str(new_str);
	if (new_arg == NULL || check_double(new_arg,new_str) == 0)
	{
		return (NULL);
	}
	return (new_arg);
}

char **check_arg(char **argv)
{
	int j;
	char *str;
	char **new_str;  

	j = 2;
	str = ft_strdup(argv[1]);
	while (argv[j] != NULL)
	{			
		str = ft_strjoin(str," ");
		str = ft_strjoin(str,argv[j++]);
	}
	new_str = ft_split(str,' ');
	return (new_str);

}

int main(int argc, char **argv)
{
	int i;
	int	*new_arg;  
	                                                                              

	i = 0;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else 
	{
		if (argc > 1)
		{
			if (!checker(argv))
			{
				print_error();
				return (1);
			}
			else
			{
				new_arg = char_to_int(check_arg(argv));
				if (new_arg == NULL)
				{
					print_error();
					return (1);
				}
				while(i < size_new_str(check_arg(argv)))
				{
					printf("%d \n",new_arg[i]);
					i++;
				}
			}
		}
	}
	return (0);
}
