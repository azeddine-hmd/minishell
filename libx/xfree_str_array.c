/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xfree_str_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:50:14 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 19:50:14 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	xfree_str_array(char **str_arr)
{
	int	i;

	if (!str_arr)
		return ;
	i = -1;
	while (str_arr[++i])
		xfree(str_arr[i]);
	xfree(str_arr);
}
