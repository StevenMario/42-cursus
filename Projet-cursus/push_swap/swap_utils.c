/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:21:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/23 21:21:45 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = new;
			new->prev = temp;
			new->next = NULL;
			break ;
		}
		temp = temp->next;
	}
}

t_stack	*ft_double_lstnew(int nbr)
{
	t_stack		*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->prev = NULL;
	new_stack->nbr = nbr;
	new_stack->next = NULL;
	return (new_stack);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	temp = (*lst);
	if (temp == NULL)
		return ;
	else
	{
		while (temp != NULL)
		{
			next = (temp)->next;
			free(temp);
			temp = next;
		}
		*lst = NULL;
	}
}

t_stack	*ft_lstlast(t_stack **lst)
{
	t_stack	*temp;

	if (!(*lst))
		return (NULL);
	temp = (*lst);
	while (temp)
	{
		temp = temp->next;
		if (temp->next == NULL)
			return (temp);
	}
	return (temp);
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
