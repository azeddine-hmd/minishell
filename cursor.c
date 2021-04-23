/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:33:25 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/22 17:36:53 by ahamdaou         ###   ########.fr       */
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

void	ms_lndel(t_cap *cap, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		ms_chrdel(cap);
	}
}
