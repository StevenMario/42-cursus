/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:21:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/21 13:00:07 by mrambelo         ###   ########.fr       */
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
			printf("free = {%d} {%p}\n",temp->nbr,temp);
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

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
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

int	*convert_str(char **str)
{
	int	i;
	int	*nbr;

	i = 0;
	while (str[i] != NULL)
		i++;
	nbr = malloc(sizeof(int) * i);
	i = 0;
	while (str[i] != NULL)
	{
		if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
			return (NULL);
		nbr[i] = (int)ft_atoi(str[i]);
		i++;
	}
	return (nbr);
}
