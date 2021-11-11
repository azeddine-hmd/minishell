/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:50:27 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/11 19:55:22 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ft_envcmp(char *s1, char *s2)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '=')
			break ;
		i++;
	}
	tmp = xsubstr(s1, 0, i);
	if (!ft_strcmp(tmp, s2))
	{
		xfree(tmp);
		return (0);
	}
	xfree(tmp);
	return (1);
}

int	find_env(char *value, char **env)
{
	int		i;
	char	*tmp;

	i = -1;
	while (env[++i])
	{
		tmp = ft_strjoinch(value, '=');
		if (ft_strstartw(env[i], tmp) || !(ft_envcmp(env[i], value)))
		{
			xfree(tmp);
			return (i);
		}
		xfree(tmp);
	}
	return (i);
}

int	ft_valid_env(char *s)
{
	int	i;
	int	check;

	check = 0;
	i = -1;
	while (s[++i])
		if (s[i] == '=')
			check = 1;
	if (!check)
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
