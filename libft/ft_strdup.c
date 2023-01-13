/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:33:58 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 18:11:22 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*ch;
	unsigned int	i;

	ch = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ch == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ch[i] = s1[i];
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
