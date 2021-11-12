/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:50:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 19:50:02 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*splitat(const char *s, int index)
{
	char	*splited;
	char	*left;
	char	*right;

	if (index == 0)
		return (xsubstr(s, 1, ft_strlen(s) - 1));
	if (index == (int)(ft_strlen(s) - 1))
		return (xsubstr(s, 0, ft_strlen(s) - 1));
	left = xsubstr(s, 0, index);
	right = xsubstr(s, index + 1, ft_strlen(s) - index + 1);
	splited = xstrjoin(left, right);
	xfree(left);
	xfree(right);
	return (splited);
}
