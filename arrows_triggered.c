/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows_triggered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:23:24 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 19:23:24 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	up_arrow_triggered(t_termarg *targ)
{
	targ->pos = 0;
	if (!has_previous(targ->cur))
		return (false);
	if (is_null(targ->cur->cmdln_str))
		targ->cur->cmdln_str = xstrdup(targ->buf->str);
	targ->cur = targ->cur->previous;
	ms_lndel(targ->cap, targ->buf->last);
	ms_bufrpc(targ->buf, targ->cur->cmdln_str);
	ft_putstr(targ->cur->cmdln_str);
	return (false);
}

t_bool	down_arrow_triggered(t_termarg *targ)
{
	targ->pos = 0;
	if (targ->cur->next == NULL)
		return (false);
	targ->cur = targ->cur->next;
	ms_lndel(targ->cap, targ->buf->last);
	if (is_null(targ->cur->cmdln_str))
		ms_bufrst(targ->buf);
	else
		ms_bufrpc(targ->buf, targ->cur->cmdln_str);
	ft_putstr(targ->buf->str);
	return (false);
}

t_bool	right_arrow_triggered(t_termarg *targ)
{
	targ->pos = 0;
	return (false);
}

t_bool	left_arrow_triggered(t_termarg *targ)
{
	targ->pos = 0;
	return (false);
}
