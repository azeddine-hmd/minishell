/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsubstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:38:38 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 19:38:38 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*xsubstr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	sub_str = (char *)xmalloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	sub_str = (char *)xmalloc(sizeof(char) * (len + 1));
	if (!sub_str)
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

char	*xstrsub(const char *s, unsigned int start, unsigned int end)
{
	if (end >= start)
		return (xsubstr(s, start, end - start + 1));
	else
		return (NULL);
}

char	*xsubrange(const char *s, t_range *range)
{
	return (xstrsub(s, range->from, range->to));
}
