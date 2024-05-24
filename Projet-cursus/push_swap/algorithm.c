/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:56:53 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/24 11:11:11 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*next_lst;
	t_stack	*next_next_lst;

	if (!*lst)
		return ;
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
		reverse_rotate_a(lst);
}

void	sort_all(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	push_b(b, a);
	temp = (*b);
	while (temp)
	{
		printf(" Voici B[%d]\n", temp->nbr);
		temp = temp->next;
	}
	ft_lstclear(b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*smalest;

	if (is_sort(a) == 1)
		printf("OK");
	else
	{
		if (stack_len(a) == 2)
		{
			if (is_sort(a) != 1)
				swap_a(a);
		}
		else if (stack_len(a) == 3)
		{
			while (is_sort(a) != 1)
				sort_three(a);
		}
		else
		{
			sort_all(a,b);
		}
	}
	temp = (*a);
	while (temp)
	{
		printf("[%d]\n", temp->nbr);
		temp = temp->next;
	}
	smalest = find_smallest((*a));
	printf("Le plus petit dans stack a est {%d}\n",smalest->nbr);
	ft_lstclear(a);
}
