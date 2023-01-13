/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_into_strs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:29:19 by cormiere          #+#    #+#             */
/*   Updated: 2023/01/13 12:03:30 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_cnt_word(char const *duplicated_str, char delimiter)
{
	size_t	cnt_word;

	cnt_word = 0;
	while (*duplicated_str)
	{
		while (*duplicated_str == delimiter)
			++duplicated_str;
		if (*duplicated_str)
		{
			++cnt_word;
			while (*duplicated_str && *duplicated_str != delimiter)
				++duplicated_str;
		}
	}
	return (cnt_word);
}

static char	*get_word(char *word, char delimiter)
{
	char	*start;

	start = word;
	while (*word && *word != delimiter)
		++word;
	*word = '\0';
	return (ft_strdup(start));
}

static char	**get_strs(char delimiter, char *duplicated_str, size_t cnt_word)
{
	char	**strs;
	char	*word;
	size_t	i;

	strs = (char **)malloc(sizeof(char *) * (cnt_word + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (i < cnt_word)
	{
		while (*duplicated_str == delimiter)
			++duplicated_str;
		if (*duplicated_str)
		{
			word = get_word(duplicated_str, delimiter);
			if (word == NULL)
				free_word_fct(strs, i);
			strs[i++] = word;
			duplicated_str += (ft_strlen(word) + 1);
		}
	}
	strs[i] = NULL;
	return (strs);
}

char	**split_into_strs(char const *str, char delimiter)
{
	char	**strs;
	char	*duplicated_str;
	size_t	cnt_word;

	if (str == NULL)
		return (NULL);
	duplicated_str = ft_strdup((char *)str);
	if (duplicated_str == NULL)
		return (NULL);
	cnt_word = get_cnt_word(duplicated_str, delimiter);
	strs = get_strs(delimiter, duplicated_str, cnt_word);
	free(duplicated_str);
	duplicated_str = NULL;
	if (strs == NULL)
		return (NULL);
	return (strs);
}
