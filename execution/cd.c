/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boodeer <boodeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:06:29 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/15 23:23:04 by boodeer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int			path_error(char *path)
{
	error_msg("cd: ", 2, 1);
	error_msg(path, 2, 1);
	error_msg(": No such file or directory\n", 2, 1);
	free(path);
	return (1);
}



int			home_run(char **env) // changed the current work directory to $–HOME
{
	char	*path;

	path = ft_substr(find_strenv("HOME", env), 5, ft_strlen(find_strenv("HOME", env)));
	if (!path)
		return (error_msg("cd: HOME not set\n", 2, 1));
	if (*path == '\0')
		path = getcwd(NULL, 1024);
	else
		path = ft_strdup(path);
	if (chdir(path) == -1)
		return (path_error(path));
	export_var(ft_strdup("OLDPWD"), ft_strdup(find_strenv("PWD", env)), env);
	export_var(ft_strdup("PATH"), path, env);
	free(path);
	return (0);
}

char		*find_path(char *str, char **env)
{
	if (!ft_strcmp(str, "-"))
		return (find_strenv("OLDPWD", env));
	else if (!ft_strcmp(str, "~"))
		return (find_strenv("HOME", env));
	else if (*str == '~' && !ft_strcmp((str + 1), find_strenv("USER", env)))
		return (find_strenv("HOME", env));
	return (str);
}

int			ft_builtin_cd(char **args, char **env)
{
	char	*path;

	if (!args[0])
		return (home_run(env));
	path = find_path(args[0], env);
	if (chdir(path) == -1)
		return (path_error(ft_strdup(path)));
	path = getcwd(NULL, 1024);
	export_var(ft_strdup("OLDPWD"), ft_strdup(find_strenv("PWD", env)), env);
	export_var(ft_strdup("PWD"), path, env);
	return (0);
}