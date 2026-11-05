/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balper <balper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:57:13 by balper            #+#    #+#             */
/*   Updated: 2026/11/03 02:34:36 by balper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_find_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	if (!str2)
		return (NULL);
	joined_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!joined_str)
	{
		free(str1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (str1 && str1[i])
	{
		joined_str[i] = str1[i];
		i++;
	}
	while (str2[j])
		joined_str[i++] = str2[j++];
	joined_str[i] = '\0';
	free(str1);
	return (joined_str);
}

char	*ft_strdup(char *str)
{
	char	*value;
	int		i;

	if (!str)
		return (NULL);
	value = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!value)
		return (NULL);
	i = 0;
	while (str[i])
	{
		value[i] = str[i];
		i++;
	}
	value[i] = '\0';
	return (value);
}
