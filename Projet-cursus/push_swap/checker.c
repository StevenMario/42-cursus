/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:10:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/04/30 12:44:18 by mrambelo         ###   ########.fr       */
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
            if (ft_ispace(str[i]) == 0)
                return 0;
            while (str[i][j] != '\0')
            {
                if (ft_isdigit(str[i][j]) || str[i][j] == ' ' || (str[i][j] == '-' && ft_isdigit(str[i][j + 1])))
                    j++;  
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

int ft_ispace(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            j++;
        else 
            return 1;
        i++;
    }
    return 0;
}
