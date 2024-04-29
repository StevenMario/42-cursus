/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:10:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/04/29 12:59:21 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int checker(char **str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] != NULL)
    {
        while (str[i][j] != '\0')
        {
            if ((str[i][j] >= '0' && str[i][j] <= '9') || str[i][j] == '-')
                j++;
            else
                return (0);
        }
        j = 0;
        i++;
    }
    return (1);
}