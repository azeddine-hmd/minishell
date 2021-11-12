/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:28:54 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/11 19:22:18 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	**export_var(char *var, char *str, char **env)
{
	int		index;
	char	*tmp;

	index = find_env(var, env);
	if (str != NULL)
		tmp = xstrjoin("=", str);
	else
		tmp = xstrdup("");
	if (env[index])
	{
		if (str)
		{
			xfree(env[index]);
			env[index] = xstrjoin(var, tmp);
		}
	}
	else
	{
		env = realloc_env(index + 1, env);
		env[index] = xstrjoin(var, tmp);
	}
	xfree(tmp);
	return (env);
}
