/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:47:04 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/06 10:59:28 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "./libft/libft.h"
 typedef struct s_stack
{
	int			nbr;
	int			index;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack  *next;
}   t_stack;

int	checker(char **str);
int ft_ispace(char *str);
int size_new_str(char **new_str);
int *char_to_int(char **new_str);
int check_double(int *nbr,char **new_str);
char **check_arg(char **argv);
t_stack *ft_double_lstnew(int nbr);
t_stack *ft_lstlast(t_stack *lst);
void print_error(void);
void fill_stack_a(int *new_arg,char **argv);

void ft_lstadd_back(t_stack **lst, t_stack *new);
void ft_lstdelone(t_stack *lst, void (*del)(void *));
void ft_lstclear(t_stack **lst, void (*del)(void *));

#endif
