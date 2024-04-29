/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:46:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/04/29 14:40:07 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int i;
    char **str;

    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
        return (1);
    else 
    {
        if (argc == 2 ||(argv[1][0] != '\0'))
            str = ft_split(argv[1], ' ');
        a = 
        /*i = checker(str);
        if (!i)
        {
            print_error();
            return (1);
        }
        if (argc > 2)
        {
            while (argv[i] != NULL)
            {

            }
        }*/
    }
    return (0);
}