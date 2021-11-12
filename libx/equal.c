/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:34:13 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 19:34:13 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

t_bool	equal(const char *s1, const char *s2)
{
	int	result;

	result = ft_strcmp(s1, s2);
	if (result == 0)
		return (true);
	else
		return (false);
}

t_bool	not_equal(const char *s1, const char *s2)
{
	int	result;

	result = ft_strcmp(s1, s2);
	if (result != 0)
		return (true);
	else
		return (false);
}
