/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:00:43 by cormiere          #+#    #+#             */
/*   Updated: 2023/01/13 17:48:42 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_bufflen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_alloc(size_t size)
{
	char	*s;
	char	*ptr;

	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	size = size + 1;
	ptr = s;
	while (size-- > 0)
		*ptr++ = '\0';
	return (s);
}

static char	*ft_save(char *lines)
{
	if (ft_strchr(lines, '\n'))
	{
		ft_strcpy(lines, ft_strchr(lines, '\n') + 1);
		return (lines);
	}
	if (ft_bufflen(lines) > 0)
	{
		ft_strcpy(lines, ft_strchr(lines, '\0'));
		return (lines);
	}
	return (NULL);
}

int	ft_get_get_get(char **lines)
{
	if (*lines == NULL)
	{
		*lines = ft_alloc(0);
		if (*lines == NULL)
		{
			free (lines);
			return (-1);
		}
	}
	return (0);
}

int	get_next_line_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*lines = NULL;
	char		*newline_ptr;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	ft_get_get_get(&lines);
	while (1)
	{
		newline_ptr = ft_strchr(lines, '\n');
		if (newline_ptr != NULL)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		lines = ft_strjoin(lines, buffer);
	}
	*line = ft_substr(lines, 0, ft_bufflen(lines));
	if (ft_save(lines) != NULL)
		return (1);
	free(lines);
	return (0);
}
