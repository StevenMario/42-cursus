/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:56:53 by mrambelo          #+#    #+#             */
/*   Updated: 2024/06/01 10:55:30 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **lst)
{
	t_stack	*biggest;

	biggest = find_biggest(*lst);
	if (biggest == *lst)
		rotate_a(lst);
	else if ((*lst)->next == biggest)
		reverse_rotate_a(lst);
	if ((*lst)->nbr > (*lst)->next->nbr)
		swap_a(lst);
	set_index_and_median(*lst);
}

void	sort_all(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len((*a));
	if (len_a-- > 3 && !is_sort(a))
		push_b(b, a);
	if (len_a-- > 3 && !is_sort(a))
		push_b(b, a);
	while (len_a-- > 3 && !is_sort(a))
	{
		init_stack_a((*a), (*b));
		move_a_to_b(a, b);
	}
	sort_three(a);
	while ((*b))
	{
		init_stack_b((*a), (*b));
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
			sort_all(a, b);
		}
	}
}
