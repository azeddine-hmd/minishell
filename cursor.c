/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:33:25 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/07 10:53:12 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** move cursor left
*/

void	ms_curlef(void)
{
	char *value;

	value = tgetstr("le", NULL);
	tputs(value, 1, &ft_putc);
}

/*
** delete character inside cursor
*/

void	ms_curdel(void)
{
	char *value;

	value = tgetstr("dc", NULL);
	tputs(value, 1, &ft_putc);
}
