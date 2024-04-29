/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:46:34 by mariosteven       #+#    #+#             */
/*   Updated: 2024/04/29 22:11:56 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    //t_stack *a;
    //t_stack *b;
    int i;
    int j;
    char *str;

    i = 0;
    j = 2;
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
        return (1);
    else 
    {
        if (argc > 1)
        {
            i= checker(argv);
            if (!i)
                print_error();
            else
            {
                str = ft_strdup(argv[1]);
                while (argv[j] != NULL)
                {
                    str = ft_strjoin(str," ");
                    str = ft_strjoin(str,argv[j++]);
                }
                    

                printf("%s",str);
            }
        }
    }
    return (0);
}