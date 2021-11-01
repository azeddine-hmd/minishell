/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boodeer <boodeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:50:27 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/01 08:03:02 by boodeer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	find_env(char *value, char **env)
{
	int		i;
	char	*tmp;

	i = -1;
	while (env[++i])
	{
		tmp = ft_strjoinch(value, '=');
		if (ft_strstartw(env[i], tmp))
		{
			xfree(tmp);
			return (i);
		}
		xfree(tmp);
	}
	return (i);
}

int ft_valid_env(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != '=')
		;
	if (i == (int)ft_strlen(s) - 1)
		return (0);
	else
		return (1);
}

int	ft_builtin_env(char **env)
{
	int			i;

	i = 0;
	while (++i < length(env))
	{
		if (ft_valid_env(env[i]))
		{
			write(1, env[i], ft_strlen(env[i]));
			write(1, "\n", 1);
		}
	}
	return (0);
}
