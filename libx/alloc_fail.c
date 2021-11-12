/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_fail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:26:55 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:26:55 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	alloc_fail(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Allocation failure\n", 2);
	lst_clear(*xmalloc_head());
	exit(1);
}
