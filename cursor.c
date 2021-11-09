/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:41:58 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 21:41:58 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** move cursor left and delete character inside cursor
*/

void	ms_chrdel(t_cap *cap)
{
	tputs(cap->le, 1, &ft_putc);
	tputs(cap->dc, 1, &ft_putc);
}

/*
** delete current line
*/

void	ms_lndel(t_cap *cap, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		ms_chrdel(cap);
	}
}
