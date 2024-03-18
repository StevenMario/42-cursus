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
#include <stdio.h>
char	*get_next_line(int fd)
{
	static char *line_static = NULL;
	char *line;
	char *buffer;
	
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(line_static);
		free(buffer);
		return NULL;
	}
	line_static = fill_line_buffer(fd,buffer,line_static);
	if (*line_static == '\0')
	{
		free(line_static);
		return (line_static = '\0');
	}
	line = extract_line(line,line_static);
	line_static = new_line_static(line_static);
	return (line);
}
char	*fill_line_buffer(int fd, char *buffer, char *line_static)
{
	ssize_t	nbyte;
	
	nbyte = 1;
	if (!line_static)
		line_static = '\0';
	while (nbyte > 0)
	{
		nbyte = read(fd,buffer,BUFFER_SIZE);
		if (nbyte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbyte] = '\0';
		line_static = ft_strjoin(line_static, buffer);
		if (ft_strchr(buffer,'\n'))
			break;
	}
	free(buffer);
	return (line_static);
}

char	*new_line_static(char *line_static)
{
	int	len;
	int	i;
	char	*new_line_static;
	
	len = 0;
	i = 0;
	if (line_static == NULL)
		return (NULL);
	while (line_static[len] != '\n' && line_static[len] != '\0')
		len++;
	if (line_static[len] == '\n')
		len++;
	new_line_static = (char *)malloc(sizeof(char) *(ft_strlen(line_static) - len + 1));
	if (!new_line_static)
		return (NULL);
	while (line_static[len + i] != '\0')
	{
		new_line_static[i] == line_static[len + i];
		i++;
	}
	free(line_static);
	new_line_static[i] = '\0';
	return (new_line_static);
}

char	*extract_line(char *line, char *line_static)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (line_static[len] && line_static[len] != '\n')
		len++;
	if (line_static == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = line_static[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
int main()
{
	char *str;
	int fd;
	
	fd = open("test.txt",O_RDONLY);
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
	return 0;
}
