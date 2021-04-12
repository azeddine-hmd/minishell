/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:33:25 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/09 14:37:01 by ahamdaou         ###   ########.fr       */
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
