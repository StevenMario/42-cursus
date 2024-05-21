/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:46:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/21 13:48:52 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*fill_stack_a(int *new_arg, char **argv)
{
	int		i;
	t_stack	*a;

	a = ft_double_lstnew(new_arg[0]);
	i = 1;
	while (i < size_new_str(argv))
	{
		ft_lstadd_back(&a, ft_double_lstnew(new_arg[i]));
		i++;
	}
	free(new_arg);
	free_split(argv);
	return (a);
}

void push_swap(t_stack *a)
{
	t_stack *temp;

	if (is_sort(&a) == 1)
		printf("OK");
	else
	{
		if (is_three(&a) == 3)
		{
			while (is_sort(&a) != 1)
				sort_three(&a);
		}
		else 
		{
			sort_all(a);
		}
	}
	temp = a;
	while (temp)
	{
		printf("[%d]\n", temp->nbr);
		temp = temp->next;
	}
	ft_lstclear(&a);
}

void sort_all(t_stack **a)
{
	t_stack *b;
	t_stack *temp;

	b = NULL;
	push_b(&b,a);
	push_b(&b,a);
	temp = b;
	while (temp)
	{
		printf(" Voici B[%d]\n", temp->nbr);
		temp = temp->next;
	}
	ft_lstclear(&b);
}

t_stack	*check_valid(char **argv,int argc)
{
	int 	*new_arg;
	t_stack *a;

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
			a = fill_stack_a(new_arg, check_arg(argv));
			
		}
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack *a;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else
	{
		a = check_valid(argv,argc);
		if (a == NULL)
			return (1);
		else
			push_swap(a);
	}
	return (0);
}
