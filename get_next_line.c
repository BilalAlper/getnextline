/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balper <balper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:18:35 by balper            #+#    #+#             */
/*   Updated: 2026/11/05 03:02:57 by balper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_null(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*free_and_null_both(char **str1, char **str2)
{
	free_and_null(str1);
	free_and_null(str2);
	return (NULL);
}

static char	*get_the_line(char **str)
{
	char	*line;
	char	*temp;
	int		i;
	int		j;

	i = ft_find_char(*str, '\n');
	if (i == -1)
	{
		line = *str;
		*str = NULL;
		return (line);
	}
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = -1;
	while (++j <= i)
		line[j] = (*str)[j];
	line[j] = '\0';
	temp = ft_strdup(&(*str)[i + 1]);
	if (!temp)
		return (free_and_null_both(&line, str));
	free(*str);
	*str = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_and_null(&remainder));
	while (ft_find_char(remainder, '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_and_null_both(&remainder, &buffer));
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
			return (free_and_null(&buffer));
	}
	free(buffer);
	if (!remainder || !remainder[0])
		return (free_and_null(&remainder));
	return (get_the_line(&remainder));
}
