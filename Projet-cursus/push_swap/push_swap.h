/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:47:04 by mariosteven       #+#    #+#             */
/*   Updated: 2024/04/30 12:45:14 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "./libft/libft.h"
 typedef struct s_stack
{
    struct s_stack  *prev;    
    void            *data;
    struct s_stack  *next;
}   t_stack;

int checker(char **str);
void print_error(void);
int ft_ispace(char *str);

#endif
