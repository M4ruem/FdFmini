/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:37:00 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 16:57:35 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc_free(char *buffer, char *str)
{
	char	*temp;

	temp = ft_strjoin(buffer, str);
	free(buffer);
	return (temp);
}

static char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!line)
		return (0);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*read_file(int fd, char *buffer)
{
	char	*str;
	int		byte_read;

	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (0);
	byte_read = 1;
	while (byte_read > 0 && !(ft_strchr(str, '\n')))
	{
		byte_read = read(fd, str, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		str[byte_read] = 0;
		buffer = ft_alloc_free(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (0);
	}
	buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
