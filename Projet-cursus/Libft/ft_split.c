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

char *rm_end_start_c(char const *s, char c)
{
	char	a[2];
	char	*str;
	
	a[0] = c;
	a[1] = '\0';
	str = ft_strtrim(s,a);
	
	return (str);
	
}

int	col_len(char *str,char c)
{
	int	i;
	int	len;
	
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c)
			len++;
		i++;
	}
	return (len + 1);
}
char	**ft_fill(char *str,char c,char **result)
{
	int	i;
	int	o;
	int	j;
	
	i = 0;
	o = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			result[o][j] = str[i];
			j++;
		}	
		else if (str[i] == c && str[i + 1] != c)
		{
			result[o][j] = '\0'; 
			j = 0;
			o++;
		}
		i++;
	}
	result[o] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	char	*str;
	char	**result;
	char	**last_str;
	int	o;

	i = 0;
	o = 0;
	
	str = rm_end_start_c(s,c);
	result = (char **)malloc(sizeof(char *) * (col_len(str,c) + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
	{
		if(str[i] != c)
			j++;
			
		else if (str[i] == c && str[i + 1] != c)
		{
			
			result[o++] = (char *)malloc(sizeof(char) * j + 1);
			j = 0;

		}
		i++;
	}
	last_str = ft_fill(str, c, result);
	if (last_str)
		printf("not OK");
	return (last_str);
}
int main()
{
    char const *s = "   akory iaby asdasd asdasd rerze ";
    char c = ' ';
    char **str = ft_split(s, c);
    int i =  0;

    while (str[i]) {
        printf("%s\n", str[i]);
        free(str[i]); // Libérer chaque sous-chaîne
        i++;
    }
    free(str); // Libérer le tableau de pointeurs

    return  0;
}
