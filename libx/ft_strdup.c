/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:17:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:17:47 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_strdup(const char *s1)
{
	char	*memory;
	int		i;

	if (!s1)
		return (NULL);
	memory = (char *)ft_calloc(1, ft_strlen(s1) + 1);
	if (!memory)
		return (NULL);
	i = -1;
	while (s1[++i])
		memory[i] = s1[i];
	return (memory);
}
