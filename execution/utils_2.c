/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:22:36 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/08 18:34:16 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	env_len(char **env)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (env[++i])
		j++;
	return (j);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = xmalloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size + 1);
	return (ptr);
}

int	error_msg(char *error_msg, int fd, int exit_code)
{
	write(fd, error_msg, ft_strlen(error_msg));
	return (exit_code);
}

char	**init_env(char **env)
{
	int		i;
	char	**p_env;

	p_env = (char **)safe_malloc(sizeof(char *) * (env_len(env) + 1));
	i = 0;
	p_env[i] = xstrdup("?=0");
	while (env[++i])
	{
		p_env[i] = xstrdup(env[i]);
		if (!p_env[i])
			error_msg("A memory allocation failed!\n", 2, 0);
	}
	return (p_env);
}
