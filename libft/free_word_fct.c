/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_word_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:59:13 by cormiere          #+#    #+#             */
/*   Updated: 2023/01/13 12:03:32 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	double_free_strs(char **strs, size_t i)
{
	while (--i >= 0)
	{
		free(strs[i]);
		strs[i] = NULL;
	}
	free(strs);
	strs = NULL;
}

void	free_word_fct(char **strs, size_t i)
{
	double_free_strs(strs, i);
	return ;
}
