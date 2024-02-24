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
	char	a[];
	char	*str;
	
	a = {c, '\0'};
	str = ft_strtrim(s,a);
	return (str);
	
}

int	col_len(char *str,char c)
{
	int	i;
	int	len;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c)
			len++;
		i++;
	}
	return (len);
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
			result[o][j] = str[i];
		else if (str[i] == c & str[i + 1] != c)
		{
			j = 0;
			o++;
		}
		i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	char	*str;
	char	**result;
	int	o;	

	i = 0;
	o = 0;
	str = rm_end_start_c(s,a);
	result = (char **)malloc(sizeof(char *)*col_len(str,c));
	while (str[i] != '\0')
	{
		if(str[i] != c)
			j++;
		else if (str[i] == c & str[i + 1] != c)
		{
			result[o++] = (char *)malloc(sizeof(char) * j + 1);
			j = 0;
		}
		i++;
	}
	return (ft_fill(str,c,result));
}
int main()
{
	char const *s = "   akory iaby asdasd asdasd  ";
	char c = ' ';
	char **str = ft_split(*s,c);
	int i = 0;
	while (str[i] != '\0')
	{
		printf("%s\n",str[i]);
		i++;
	}
	return 0;
}
