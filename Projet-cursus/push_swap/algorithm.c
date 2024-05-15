/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:56:53 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/15 13:28:22 by mrambelo         ###   ########.fr       */
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

int is_three(t_stack **lst)
{
	int i;
	t_stack *temp;

	i = 0;
	temp = (*lst);
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void sort_three(t_stack **lst)
{
    t_stack *tmp;
    t_stack *next_lst;
    t_stack *next_next_lst;
    if (!*lst)
        return;

    tmp = *lst;
    next_lst = (*lst)->next;
	next_next_lst = next_lst->next;
    if (tmp->nbr > next_lst->nbr && tmp->nbr > next_next_lst->nbr)
        rotate_a(lst);
    else if (tmp->nbr < next_lst->nbr && tmp->nbr < next_next_lst->nbr)
        swap_a(lst);
    else if (tmp->nbr > next_lst->nbr && tmp->nbr < next_next_lst->nbr)
        swap_a(lst);
    else if (tmp->nbr < next_lst->nbr && tmp->nbr > next_next_lst->nbr)
        rotate_a(lst);
}