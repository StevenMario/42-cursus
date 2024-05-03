/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:46:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/03 10:34:48 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// t_stack *fill_stack_a(char **str)
// {
//     int i;
//     i = 0;

//     while (str[i] != NULL)
//     {
		
//     }
// }
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

int main(int argc, char **argv)
{
	//t_stack *a;
	//t_stack *b;
	int j;
	int i;
	int	*new_arg;
	char *str;
	char **new_str;  
	                                                                              

	j = 2;
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
				str = ft_strdup(argv[1]);
				while (argv[j] != NULL)
				{
					str = ft_strjoin(str," ");
					str = ft_strjoin(str,argv[j++]);
				}
				new_str = ft_split(str,' ');
				new_arg = convert_str(new_str);
				if (new_arg == NULL || check_double(new_arg,new_str) == 0)
				{
					print_error();
					return (1);
				}
				while(i < size_new_str(new_str))
				{
					printf("%d \n",new_arg[i]);
					i++;
				}
				free(str);
				free(new_str);
			}
		}
	}
	return (0);
}
