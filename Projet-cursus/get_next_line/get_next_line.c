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

char	*helper(char *stat, char *buff)
{
	char	*join;
	
	join = ft_strjoin(stat, buff);
	free(stat);
	return (join);
}

char	*fill_line_buffer(int fd, char *line_static)
{
	ssize_t	nbyte;
	char	*buffer;

	if (!line_static)
		line_static = ft_calloc(1,sizeof(char));
	if (!line_static)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(line_static);
		return (NULL);
	}
	nbyte = 1;
	while (nbyte)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
		{
			free(buffer);
			free(line_static);
			return (NULL);
		}
		buffer[nbyte] = '\0';
		line_static = helper(line_static, buffer);
		if (ft_strchr(line_static, '\n'))
			break ;
	}
	free(buffer);
	return (line_static);
}

char	*extract_line(char *line_static)
{
	int	i;
	int	len;
	char	*line;

	i = -1;
	len = 0;
	if (!line_static || !(*line_static))
		return (NULL);
	while (line_static[len] && line_static[len] != '\n')
		len++;
	if (line_static[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (++i < len)
		line[i] = line_static[i];
	line[i] = '\0';
	return (line);
}

char	*new_line_static(char *line_static)
{
	int		i;
	int		len;
	char		*new_line;

	i = 0;
	len = 0;
	if (!line_static)
		return (NULL);
	if (!*line_static)
	{
		free(line_static);
		return (NULL);
	}
	while (line_static[len] != '\n' && line_static[len] != '\0')
		len++;
	if (line_static[len] == '\n')
		len++;
	new_line = (char *)malloc(sizeof(char) *(ft_strlen(line_static) - len + 1));
	if (!new_line)
	{
		free(line_static);
		return (NULL);
	}
	while (line_static[len + i] != '\0')
	{
		new_line[i] = line_static[len + i];
		i++;
	}
	new_line[i] = '\0';
	if (new_line[0] == '\0')
	{
		free(line_static);
		free(new_line);
		return (NULL);
	}
	free(line_static);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_static;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_static = fill_line_buffer(fd, line_static);
	if (!line_static)
		return (NULL);
	line = extract_line(line_static);
	line_static = new_line_static(line_static);
	return (line);
}

