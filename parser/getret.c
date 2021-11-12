/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:16:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 10:16:16 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	getret(char **env)
{
	char	*ret_str;
	int		ret;

	ret_str = pa_getenv(env, "?");
	ret = ft_atoi(ret_str);
	xfree(ret_str);
	return (ret);
}
