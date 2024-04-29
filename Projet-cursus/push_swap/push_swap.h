/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:47:04 by mariosteven       #+#    #+#             */
/*   Updated: 2024/04/29 13:34:38 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
    int nbr;
    int index;

    struct s_stack *target;
    struct s_stack *next;
    struct s_stack *prev;
}   t_stack;

int checker(char **str);
void print_error(void);

#endif