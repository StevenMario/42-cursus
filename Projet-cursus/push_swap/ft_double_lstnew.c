/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:54:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/01 10:47:01 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_double_lstnew(t_stack **stack,void *data)
{
	t_stack   *new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
	{
		return (NULL);
	}
	new_stack->prev= NULL;
	new_stack->data = data;
	new_stack->next= NULL;
	return (new_stack);
}