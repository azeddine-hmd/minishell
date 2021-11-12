/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:53:40 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:53:40 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;
	int		str_length;

	if (!s1 || !s2)
		return (NULL);
	str_length = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(str_length + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j] != '\0')
		str[i++] = s1[j];
	j = -1;
	while (s2[++j] != '\0')
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}
