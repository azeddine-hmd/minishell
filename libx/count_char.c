/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:27:40 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:27:40 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

int	count_char(const char *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = -1;
	while (s[++i])
		if (s[i] == c)
			counter++;
	return (counter);
}
