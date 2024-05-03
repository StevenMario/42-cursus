/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:47:04 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/03 13:43:48 by mrambelo         ###   ########.fr       */
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

int checker(char **str);
void print_error(void);
int ft_ispace(char *str);
int check_double(int *nbr,char **new_str);
int size_new_str(char **new_str);
char **check_arg(char **argv);
int *char_to_int(char **new_str);

#endif
