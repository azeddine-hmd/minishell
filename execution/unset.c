/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:58:45 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/24 17:40:25 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	**delete_env(int	index, char **env)
{
	int		i;
	int		j;

	free(env[index]);
	env[index] = NULL;
	i = index;
	j = index + 1;
	while (env[i + 1])
	{
		env[i] = ft_strdup(env[i + 1]);
		free(env[i + 1]);
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
		return (error_msg("Error!\n too few arguments.\n", 2, 1));
	i = -1;
	while (args[++i])
	{
		index = find_env(args[i], *env);
		if (env[index])
			*env = delete_env(index, *env);
	}
	return (0);
}
