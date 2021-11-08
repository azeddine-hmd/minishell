/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:58:45 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/08 20:45:37 by hboudhir         ###   ########.fr       */
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

int	is_valid(char *str)
{
	int	i;

	if (str[0] != '_' && !ft_isalpha(str[0]))
		return (1);
	i = 0;
	while (str[++i] && str[i] != '=')
	{
		if (str[i] != '_' && !ft_isalnum(str[i]))
			return (1);
	}
	return (0);
}

int	ft_builtin_unset(char **args, char ***env)
{
	int		i;
	int		index;
	int		ret;

	ret = 0;
	if (!args[0])
		return (error_msg("unset: not enough arguments\n", 2, 1));
	i = -1;
	while (args[++i])
	{
		index = find_env(args[i], *env);
		if (is_valid(args[i]))
		{
			ft_bad_value(args[i], NULL, "unset");
			ret = 1;
			continue ;
		}
		if (env[0][index])
			*env = delete_env(index, *env);
	}
	return (ret);
}
