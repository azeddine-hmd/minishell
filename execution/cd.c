/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boodeer <boodeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:06:29 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/20 00:06:34 by boodeer          ###   ########.fr       */
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



int			home_run(char ***env) // changed the current work directory to $–HOME
{
	char	*path;
	char	*tmp;
	path = ft_substr(find_strenv("HOME", *env), 5, ft_strlen(find_strenv("HOME", *env)));
	if (!path)
		return (error_msg("cd: HOME not set\n", 2, 1));
	if (*path == '\0')
		path = getcwd(NULL, 1024);
	//else
		//path = ft_strdup(path);
	if (chdir(path) == -1)
		return (path_error(path));
	tmp = ft_substr(find_strenv("PWD", *env), 4, ft_strlen(find_strenv("PWD", *env)));
	printf("%s\n",tmp);
	*env = export_var("OLDPWD", tmp, *env);
	free(tmp);
	*env = export_var("PWD", path, *env);
	free(path);
	return (0);
}

char		*find_path(char *str, char **env)
{
	if (!ft_strcmp(str, "-"))
		return (ft_substr(find_strenv("OLDPWD", env), 7,
		ft_strlen(find_strenv("OLDPWD", env))));
		//return ( find_strenv("OLDPWD", env));
	else if (!ft_strcmp(str, "~"))
		return (ft_substr(find_strenv("HOME", env), 5, ft_strlen(find_strenv("HOME", env))));
		//return (find_strenv("HOME", env));
	//else if (*str == '~' && !ft_strcmp((str + 1), find_strenv("USER", env)))
		//return (find_strenv("HOME", env));
	return (ft_strdup(str));
}

int			ft_builtin_cd(char **args, char ***env)
{
	char	*path;
	char	*tmp;

	if (!args[0])
		return (home_run(env));
	path = find_path(args[0], *env);
	if (chdir(path) == -1)
		return (path_error(path));
	//if (path)
	free(path);
	path = getcwd(NULL, 0);
	tmp = ft_substr(find_strenv("PWD", *env), 4, ft_strlen(find_strenv("PWD", *env)));
	*env = export_var("OLDPWD", tmp, *env);
	*env = export_var("PWD", path, *env);
	free(path);
	free(tmp);
	return (0);
}