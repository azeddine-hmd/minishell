/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:13:22 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/24 17:28:18 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_freestrarr(char **arr)
{
	int		i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
		free(arr);
	}
	arr = NULL;
}

char	*ft_strjoincl(char *s1, char *s2, int free_both)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (!new)
		return (NULL);
	free(s1);
	s1 = NULL;
	if (free_both)
	{
		free(s2);
		s2 = NULL;
	}
	return (new);
}

char	**realloc_env(int size, char **envv)
{
	char	**env;
	int		i;

	env = (char **)safe_malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (envv[++i] && i < size)
	{
		env[i] = ft_strdup(envv[i]);
		free(envv[i]);
	}
	free(envv);
	return (env);
}

char	*ft_pathjoin(char *s1, char *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	if (!ft_strendw(s1, "/"))
	{
		if (s2[0] == '/')
			return (ft_strjoin(s1, s2));
		else
		{
			tmp = ft_strjoincl(ft_strjoin(s1, "/"), s2, 0);
			return (tmp);
		}
	}
	else
	{
		if (s2[0] == '/')
			return (ft_strjoin(s1, s2 + 1));
		else
			return (ft_strjoin(s1, s2));
	}
}

char	*find_strenv(char *str, char **env)
{
	int		index;

	index = find_env(str, env);
	if (env[index])
		return (env[index]);
	return (NULL);
}
