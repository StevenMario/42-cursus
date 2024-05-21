/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:46:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/21 09:43:02 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	*fill_stack_a(int *new_arg, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*temp;

	a = ft_double_lstnew(new_arg[0]);
	i = 1;
	while (i < size_new_str(argv))
	{
		ft_lstadd_back(&a, ft_double_lstnew(new_arg[i]));
		i++;
	}
	if (is_sort(&a) == 1)
		printf("OK");
	else
	{
		if (is_three(&a) == 3)
		{
			while (is_sort(&a) != 1)
				sort_three(&a);
		}
	}
	temp = a;
	while (temp)
	{
		printf("[%d]\n", temp->nbr);
		temp = temp->next;
	}
	ft_lstclear(&a);
	free(new_arg);
	free_split(argv);
	return (a);
}

/*void push_swap(t_stack **a)
{
	t_stack *temp;

	if (is_sort(a) == 1)
		printf("OK");
	else
	{
		if (is_three(a) == 3)
		{
			while (is_sort(a) != 1)
				sort_three(a);
		}
	}
	temp = (*a);
	while (temp)
	{
		printf("[%d]\n", temp->nbr);
		temp = temp->next;
	}
	ft_lstclear(a);
}*/

int	*convert_str(char **str)
{
	int	i;
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

int	*char_to_int(char **new_str)
{
	int	*new_arg;

	new_arg = convert_str(new_str);
	if (new_arg == NULL || check_double(new_arg, new_str) == 0)
	{
		free_split(new_str);
		free(new_arg);
		return (NULL);
	}
	free_split(new_str);
	return (new_arg);
}

int	check_valid(char **argv,int argc)
{
	int 	*new_arg;
	//t_stack *a;

	if (argc > 1)
	{
		if (!checker(argv))
		{
			print_error();
			return (0);
		}
		else
		{
			new_arg = char_to_int(check_arg(argv));
			if (new_arg == NULL)
			{
				print_error();
				return (0);
			}
			fill_stack_a(new_arg, check_arg(argv));
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	//int	*new_arg;
	//t_stack *a;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else
	{
		
		if (check_valid(argv,argc) == 0)
			return (1);
		/*else
		{
			a = check_valid(argv,argc);
			push_swap(&a);
		}*/
	}
	return (0);
}
