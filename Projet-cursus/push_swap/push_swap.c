/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:46:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/10 14:01:34 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void fill_stack_a(int *new_arg,char **argv)
{
	int i;
	t_stack *a;
//	t_stack *tmp;
	t_stack	*temp;
	
	a = ft_double_lstnew(new_arg[0]);
	i = 1;
	while (i < size_new_str(argv))
	{

		ft_lstadd_back(&a, ft_double_lstnew(new_arg[i]));
		i++;
	}
	temp = a;
	while (temp)
	{
		printf("[%d]\n", temp->nbr);
		temp = temp->next;
	}
	temp = NULL;
	reverse_rotate(&a);
	printf("A apres rotation; \n");
	temp = a;
	while (temp)
	{
		printf("[%d]\n", temp->nbr);
		temp = temp->next;
	}
	free(new_arg);
	free(*argv);
	free(argv);
	// tmp = NULL;
	// while (a)
	// {
	// 	tmp = a;
	// 	a = a->next;
	// 	if (tmp->prev)
	// 		free(tmp->prev);
	// 	if (tmp->next)
	// 		free(tmp->next);
	// 	if (tmp->target_node)
	// 		free(tmp->target_node);
	// 	free(tmp);
	// }
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
	free_split(new_str);
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
	free(str);
	return (new_str);

}

int main(int argc, char **argv)
{
	int	*new_arg;                                                                             

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
				fill_stack_a(new_arg,check_arg(argv));
			}
		}
	}
	return (0);
}