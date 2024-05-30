/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:56:53 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/30 15:20:36 by mrambelo         ###   ########.fr       */
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
	int len_a;


	len_a = stack_len((*a));
	if  (len_a-- > 3 && !is_sort(a))
		push_b(b,a);
	if  (len_a-- > 3 && !is_sort(a))
		push_b(b,a);
	while (len_a-- > 3 && !is_sort(a))
	{
		init_stack_a((*a),(*b));
		move_a_to_b(a, b);
	}
	sort_three(a);
	while ((*b))
	{
		init_stack_b((*a),(*b));
		move_b_to_a(a, b);
	}
	set_index_and_median((*a));
	min_on_top(a);
	ft_lstclear(a);
}

void	push_swap(t_stack **a, t_stack **b)
{
	if (is_sort(a) == 1)
		printf("OK pour le trie");
	else
	{
		if (stack_len((*a)) == 2)
		{
			if (is_sort(a) != 1)
				swap_a(a);
		}
		else if (stack_len((*a)) == 3)
		{
			while (is_sort(a) != 1)
				sort_three(a);
		}
		if (stack_len((*a)) > 3)
		{
			sort_all(a,b);
		}
	}
}
