/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:31:07 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:31:07 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	free_str_array(char **str_arr)
{
	int	i;

	i = -1;
	while (str_arr[++i])
		free(str_arr[i]);
	free(str_arr);
}
