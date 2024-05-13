/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:56:53 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/13 13:12:38 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sort(t_stack **lst)
{
	t_stack *temp;
	t_stack *next;

	if (!(*lst) || !(*lst)->next)
		return (0);
	temp = (*lst);
	while (temp && temp->next)
    {
        next = temp->next;
        if (temp->nbr > next->nbr)
            return (0); 
        temp = temp->next; 
	}
	return (1);
}