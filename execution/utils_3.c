/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:28:54 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/08 18:34:27 by hboudhir         ###   ########.fr       */
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
