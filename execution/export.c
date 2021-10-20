/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boodeer <boodeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:55:06 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/20 23:10:33 by boodeer          ###   ########.fr       */
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

char		**export_var(char *var, char *str, char **env)
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
	return (env);
}

/******************************
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * *******/
int			ft_bad_value(char *s1, char *s2)
{
	if (!s2)
		printf("minishell: export: `%s': not a valid identifier\n", s1);
	else
		printf("minishell: export: `%s=%s': not a valid identifier\n", \
		s1, s2);
	free(s1);
	if (s2)
		free(s2);
	return (1);
}

int			ft_isvalid(char *key)
{
	int		i;
	
	i = 0;
	if (*key == '\0' || (!ft_isalpha(*key) && *key != '_'))
		return (0);
	while (key[++i])
		if (!ft_isalpha(key[i]) && !ft_isdigit(key[i]) && key[i] == '_')
			return (0);
	return (1);
}

int			extract_data(char *str, char **key, char **value)
{
	int		j;
	
	j = 0;
	while (str[j] && str[j] != '=')
		j++;
	*key = ft_substr(str, 0, j);
	if (!*key)
		return (ft_bad_value(ft_strdup(str), NULL));
	if (str[j] == '=')
	{
		*value = ft_substr(str, j + 1, ft_strlen(str) - 1);
		if (!*value)
			*value = ft_strdup("");
	}
	else
		*value = NULL;
	if (!ft_isvalid(*key))
		return (ft_bad_value(*key, *value));
	return (0);
}
int			ft_builtin_export(char **args, char ***env)  // make sure to split w/ ("=") b4 passing the args
{
	//args = ft_split(args[0], '=');
	//printf("%s\n%s\n", args[0], args[1]);
	int		i;
	char	*key;
	char	*value;
	int		ret;

	ret = 0;
	i = -1;
	if (!args[0])
		return (ft_builtin_env(*env));
	while (args[++i])
	{
		if (extract_data(args[i], &key, &value))	
		{
			ret++;
			continue;
		}
		*env = export_var(key, value, *env);
		free(key);
		free(value);
	}
	if (ret)
		return (1);
	//if (args[1] && args[2])
	//	return(error_msg("export: Too many arguments.", 2, 1));
	//export_var(args[0], args[1], env);
	//ft_freestrarr(args);
	return (0);
}