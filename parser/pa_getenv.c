/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:22:03 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 10:22:03 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*pa_getenv(char **env, const char *name)
{
	char	*key;
	char	*equal_sign;
	int		i;

	i = -1;
	while (env[++i])
	{
		equal_sign = ft_strchr(env[i], '=');
		if (not_null(equal_sign))
		{
			key = xsubstr(env[i], 0, address_to_index(env[i], equal_sign));
			if (equal(key, name))
			{
				xfree(key);
				return (xstrdup(equal_sign + 1));
			}
			xfree(key);
		}
	}
	return (NULL);
}
