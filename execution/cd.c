/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:06:29 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/02 18:01:11 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	path_error(char *path)
{
	error_msg("cd: ", 2, 1);
	error_msg(path, 2, 1);
	error_msg(": No such file or directory\n", 2, 1);
	free(path);
	return (1);
}

int	home_run(char ***env)
{
	char	*path;
	char	*tmp;

	path = ft_substr(find_strenv("HOME", *env), 5,
			ft_strlen(find_strenv("HOME", *env)));
	if (!path)
		return (error_msg("cd: HOME not set\n", 2, 1));
	if (*path == '\0')
		path = getcwd(NULL, 1024);
	tmp = getcwd(NULL, 0);
	if (chdir(path) == -1)
		return (path_error(path));
	*env = export_var("OLDPWD", tmp, *env);
	xfree(tmp);
	*env = export_var("PWD", path, *env);
	free(path);
	return (0);
}

char	*find_path(char *str, char **env)
{
	if (!ft_strcmp(str, "-"))
		return (ft_substr(find_strenv("OLDPWD", env), 7,
				ft_strlen(find_strenv("OLDPWD", env))));
	else if (!ft_strcmp(str, "~"))
		return (ft_substr(find_strenv("HOME", env), 5,
				ft_strlen(find_strenv("HOME", env))));
	return (ft_strdup(str));
}

int	ft_builtin_cd(char **args, char ***env)
{
	char	*path;
	char	*tmp;

	if (!args[0])
		return (home_run(env));
	path = find_path(args[0], *env);
	if (chdir(path) == -1)
		return (path_error(path));
	free(path);
	path = getcwd(NULL, 0);
	tmp = xsubstr(find_strenv("PWD", *env), 4,
			ft_strlen(find_strenv("PWD", *env)));
	*env = export_var("OLDPWD", tmp, *env);
	*env = export_var("PWD", path, *env);
	free(path);
	xfree(tmp);
	return (0);
}
