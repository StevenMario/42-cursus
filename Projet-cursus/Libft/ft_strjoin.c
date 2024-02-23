/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:21:15 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/23 10:21:23 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_i;
	size_t	s2_i;
	
	s1_i = ft_strlen(s1);
	s2_i = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * s1_i + s2_i + 1);
	if (!s1 || !s2 || !str)
		return (NULL);
	ft_strlcpy(str,s1,s1_i + 1);
	size_t i = ft_strlcat(str + (s2_i), s2, s2_i + 1);
	printf("%ld", i);
	return (str);
}
int main() {
   const char s1[] = "akory "; 
   const char s2[] = "iaby";
   char *join;;
   join = ft_strjoin(s1,s2);
   printf("%s", join);

    return 0;
}
