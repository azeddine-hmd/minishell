/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:38:12 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 19:38:12 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

int	length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
