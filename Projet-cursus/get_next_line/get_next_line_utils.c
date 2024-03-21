/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steven <steven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:50:40 by mrambelo          #+#    #+#             */
/*   Updated: 2024/03/05 10:17:35 by steven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int searchChar)
{
	int		i;
	char	letter;

	i = 0;
	letter = (char)searchChar;
	while (((char *)str)[i] != '\0')
	{
		if (((char *)str)[i] == letter)
			return ((char *)str + i);
		i++;
	}
	if (((char *)str)[i] == '\0' && searchChar == '\0')
		return ((char *)str + i);
	return (0);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	size_t	total_size;
	char	*byte_ptr;
	void	*ptr;

	total_size = elementCount * elementSize;
	ptr = malloc(total_size);
	if (ptr != NULL)
	{
		byte_ptr = (char *)ptr;
		while (total_size-- > 0)
			*byte_ptr++ = 0;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int	i;
	int	j;
	size_t	s1_i;
	size_t	s2_i;

	i = 0;
	j = 0;
	s1_i = ft_strlen(s1);
	s2_i = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * s1_i + s2_i + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

