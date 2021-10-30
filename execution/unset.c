/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boodeer <boodeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:58:45 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/30 21:58:35 by boodeer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	**delete_env(int index, char **env)
{
	int		i;
	int		j;

	xfree(env[index]);
	env[index] = NULL;
	i = index;
	j = index + 1;
	while (env[i + 1])
	{
		env[i] = xstrdup(env[i + 1]);
		xfree(env[i + 1]);
		i++;
		j++;
	}
	env = realloc_env(j - 1, env);
	return (env);
}

int	ft_builtin_unset(char **args, char ***env)
{
	int		i;
	int		index;

	if (!args[0])
		return (error_msg("unset: not enough arguments\n", 2, 1));
	i = -1;
	while (args[++i])
	{
		index = find_env(args[i], *env);
		if (env[0][index])
			*env = delete_env(index, *env);
	}
	return (0);
}
