/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_to_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:24:51 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:24:51 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

int	address_to_index(const char *s, char *address)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (&(s[i]) == address)
			return (i);
		i++;
	}
	return (INDEX_NOT_FOUND);
}
