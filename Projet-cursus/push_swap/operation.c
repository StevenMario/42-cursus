/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:20:25 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/31 13:19:35 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **a)
{
	t_stack *temp;

	if (*a == NULL || (*a)->next == NULL)
		return;
	temp = (*a)->next;
	(*a)->next = temp->next;
	(*a)->prev = temp;
	(*a)->next->prev = (*a);
	temp->prev = NULL;
	temp->next = (*a);
	

	(*a) = temp;
}

void push(t_stack **lst, t_stack **new)
{
	t_stack *temp;

	if (!(*new))
		return;
	temp = (*new);
	(*new) = temp->next;
	if ((*lst) == NULL)
	{
		(*lst) = temp;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
	}
	else
	{
		temp->next = *lst;
		(*lst)->prev = temp;
		(*lst) = temp;
		(*lst)->prev = NULL;
	}
	if (*new)
		(*new)->prev = NULL;
}

void rotate(t_stack **lst)
{
	t_stack *temp;
	t_stack *last;

	if (!(*lst))
		return;
	last = ft_lstlast(lst);
	*lst = (*lst)->next;
	last->next = (*lst)->prev;
	temp = last->next;
	temp->prev = last;
	temp->next = NULL;
	(*lst)->prev = NULL;
}

void reverse_rotate(t_stack **lst)
{
	t_stack *last;
	
	if (!(*lst) || !(*lst)->next)
		return;
	last = ft_lstlast(lst);
	last->prev->next = NULL;
	last->next = (*lst);
	last->prev = NULL;
	// if (stack_len((*lst)) == 3)
	// 	(*lst)->next = temp;
	*lst = last;
	last->next->prev = last;
	
}
