/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:55:06 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/04 19:17:04 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	**export_var(char *var, char *str, char **env)
{
	int		index;
	char	*tmp;

	index = find_env(var, env);
	tmp = xstrjoin("=", str);
	if (env[index])
	{
		xfree(env[index]);
		if (str)
			env[index] = xstrjoin(var, tmp);
		else
			env[index] = xstrjoin(var, "=");
	}
	else
	{
		env = realloc_env(index + 1, env);
		if (str)
			env[index] = xstrjoin(var, tmp);
		else
			env[index] = xstrjoin(var, "=");
	}
	xfree(tmp);
	return (env);
}

int	ft_bad_value(char *s1, char *s2)
{
	if (!s2)
		printf("minishell: export: `%s': not a valid identifier\n", s1);
	else
		printf("minishell: export: `%s=%s': not a valid identifier\n", \
		s1, s2);
	xfree(s1);
	if (s2)
		xfree(s2);
	return (1);
}

int	ft_isvalid(char *key)
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

int	extract_data(char *str, char **key, char **value)
{
	int		j;

	j = 0;
	while (str[j] && str[j] != '=')
		j++;
	*key = xsubstr(str, 0, j);
	if (!*key)
		return (ft_bad_value(xstrdup(str), NULL));
	if (str[j] == '=')
	{
		*value = xsubstr(str, j + 1, ft_strlen(str) - 1);
		if (!*value)
			*value = xstrdup("");
	}
	else
		*value = NULL;
	if (*value)
		*value = strip_quotes(*value);
	if (!ft_isvalid(*key))
		return (ft_bad_value(*key, *value));
	return (0);
}

int	ft_outputenv(char **env)
{
	int	i;
	int	j;
	
	i = 0;
	while (env[++i])
	{
		j = -1;
		ft_putstr("declare -x ");
		while (env[i][++j] != '=')
			write(1, &env[i][j], 1);
		if (j == (int)ft_strlen(env[i]) - 1)
		{
			write(1, "\n", 1);
			continue ;
		}
		write(1, &env[i][j], 1);
		write(1, "\"", 1);
		while(env[i][++j])
			write(1, &env[i][j], 1);
		write(1, "\"", 1);
		write(1, "\n", 1);
	}
	return (0);
}

int	ft_builtin_export(char **args, char ***env)
{
	int		i;
	char	*key;
	char	*value;
	int		ret;

	ret = 0;
	i = -1;
	if (!args[0])
		return (ft_outputenv(*env));
	while (args[++i])
	{
		if (extract_data(args[i], &key, &value))
		{
			ret++;
			continue ;
		}
		*env = export_var(key, value, *env);
		xfree(key);
		xfree(value);
	}
	if (ret)
		return (0);
	return (0);
}
