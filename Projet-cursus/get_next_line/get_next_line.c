/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steven <steven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:50:40 by mrambelo          #+#    #+#             */
/*   Updated: 2024/03/05 10:17:35 by steven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *line_static;
	char *line;
	char *buf;
	
	buf = (char *)malloc(BUFFER_SIZE + 1) * sizeof(char);
	if (!buf)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(line_static[fd]);
		free(buf);
		return NULL;
	}
}
