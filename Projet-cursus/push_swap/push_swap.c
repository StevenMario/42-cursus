/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:46:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/24 10:03:11 by mrambelo         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else
	{
		a = check_valid(argv, argc);
		if (a == NULL)
			return (1);
		else
			push_swap(&a,&b);
	}
	return (0);
}
