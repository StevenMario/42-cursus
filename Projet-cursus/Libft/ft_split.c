/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:17:15 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/24 09:17:18 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

char	**stock_world(char const *s, char c,char **result)
{
	int	i;
	int	j;
	int	k;
	
	i = 0;
	j = 0;
	k = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	**result;
	
	str = (char **)malloc(sizeof(char *) * (count_words(s,c) + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	result = stock_world(s, c, str);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

int main()
{
    char const *s = "   asdasd asdasd   ";
    char c = ' ';
    int i = count_words(s, c);
    printf("%d",i);

    return  0;
}
