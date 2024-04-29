/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:10:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/04/29 22:11:47 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int checker(char **str)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (str[i] != NULL)
    {
            while (str[i][j] != '\0')
            {
                if (ft_isdigit(str[i][j]) || str[i][j] == ' ' || (str[i][j] == '-' && ft_isdigit(str[i][j])))
                {
                    j++;
                }    
                else
                   return (0);
            }
            if (ft_strncmp(str[i] , "",2) == 0 || ft_strncmp(str[i] , " ",2) == 0)
                return 0;
            j = 0;
            i++;
    }
    return (1);
}