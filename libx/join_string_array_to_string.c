/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_string_array_to_string.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:57:53 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:57:53 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*join_string_array_to_string(char **arr)
{
	char	*joined;
	char	*tmp;
	int		len;
	int		i;

	joined = xstrdup(arr[0]);
	len = length(arr);
	i = 1;
	while (i < len - 1)
	{
		tmp = joined;
		joined = xstrjoin(joined, arr[i + 1]);
		xfree(tmp);
		i++;
	}
	return (joined);
}
