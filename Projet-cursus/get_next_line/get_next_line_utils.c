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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_i;
	size_t	s2_i;

	s1_i = ft_strlen(s1);
	s2_i = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * s1_i + s2_i + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_i + 1);
	ft_strlcat(str, s2, s2_i + s1_i + 1);
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	else
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	if (j < size)
	{
		while (src[i] != '\0' && i + j < size - 1)
		{
			dst[j + i] = src[i];
			i++;
		}
		dst[j + i] = '\0';
		while (src[i] != '\0')
			i++;
	}
	else
	{
		while (src[i] != '\0')
			i++;
		return (i + size);
	}
	return (i + j);
}
char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup_src;
	char	*csrc;

	csrc = (char *)src;
	dup_src = malloc(sizeof(char) *(ft_strlen(csrc) + 1));
	if (!dup_src)
	{
		dup_src = NULL;
		return (0);
	}
	i = 0;
	while (csrc[i] != '\0')
	{
		dup_src[i] = csrc[i];
		i++;
	}
	dup_src[i] = '\0';
	return (dup_src);
}
