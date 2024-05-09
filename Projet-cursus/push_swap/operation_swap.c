/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:20:25 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/09 13:33:51 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **a)
{
	t_stack *temp;
	
	if (*a == NULL || (*a)->next == NULL) {
		return;
	}
	temp = (*a)->next;
	(*a)->next = temp->next;
	(*a)->prev = temp;
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
		*lst = temp;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
	}
	else
	{
		temp->next = *lst;
		(*lst)->prev = temp;
		*lst = temp;
		(*lst)->prev = NULL;
	}
	(*new)->prev = NULL;
}
