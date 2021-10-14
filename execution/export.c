/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boodeer <boodeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:55:06 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/14 22:45:18 by boodeer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char		*find_strenv(char *str, char **env)
{
	int		index;

	index = find_env(str, env);
	if (env[index])
		return (env[index]);
	return (NULL);
}

void		export_var(char *var, char *str, char **env)
{
	int		index;
	char	*tmp;


	index = find_env(var, env);
	tmp   = ft_strjoin("=", str);
	if (env[index])
	{
		free(env[index]);
		if (str)
			env[index] = ft_strjoin(var, tmp);
		else
			env[index] = ft_strjoin(var, "=");
	}
	else
	{
		env = realloc_env(index + 1, env);
		if (str)
			env[index] = ft_strjoin(var, tmp);
		else
			env[index] = ft_strjoin(var, "=");
	}
	free(tmp);
}

int			ft_builtin_export(char **args, char **env)  // make sure to split w/ ("=") b4 passing the args
{
	args = ft_split(args[0], '=');
	//printf("%s\n%s\n", args[0], args[1]);
	if (!args[0])
	{
		ft_builtin_env(env);
		return (1);
	}
	if (args[1] && args[2])
		return(error_msg("export: Too many arguments.", 2, 1));
	export_var(args[0], args[1], env);
	ft_freestrarr(args);
	return (1);
}