/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsubstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:33:26 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/03/30 17:34:27 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

char	*xsubstr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	if (!(sub_str = (char*)xmalloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	while (i < (start + len))
	{
		sub_str[i - start] = s[i];
		i++;
	}
	sub_str[i - start] = '\0';
	return (sub_str);
}
