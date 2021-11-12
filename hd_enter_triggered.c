/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_enter_triggered.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:24:07 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 19:24:07 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	hd_enter_triggered(t_termarg *targ, char **env, t_hd *heredoc)
{
	t_buf	*buf;

	buf = targ->buf;
	if (equal(buf->str, heredoc->stripped_delimiter))
	{
		lstpush(&(heredoc->lines_lst), "\n");
		ft_putc(targ->input);
		return (true);
	}
	else
	{
		ft_putc(targ->input);
		if (heredoc->expand_enabled)
			lstpush(&(heredoc->lines_lst), expand((buf->str), env, false));
		else
			lstpush(&(heredoc->lines_lst), xstrdup(buf->str));
		ms_bufrst(buf);
		hd_prompt();
	}
	return (false);
}
