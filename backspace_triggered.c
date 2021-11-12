/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backspace_triggered.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:24:19 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 19:24:19 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	backspace_triggered(t_termarg *targ)
{
	if (targ->buf->pos > 0)
		ms_chrdel(targ->cap);
	ms_bufdel(targ->buf);
	return (false);
}
