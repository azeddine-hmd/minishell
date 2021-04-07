/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:56:36 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/07 10:58:23 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_scrclr(void)
{
	char	*value;

	value = tgetstr("cl", NULL);
	tputs(value, 1, &ft_putc);
	//TODO: reset buffer
}
