/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_l_triggered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:23:14 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 19:23:14 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ctrl_l_triggered(t_termarg *targ, char **env)
{
	char	*saved_buf_str;

	ft_putstr(targ->cap->ip);
	saved_buf_str = xstrdup(targ->buf->str);
	ms_bufrst(targ->buf);
	ms_prompt(getret(env));
	ms_bufrpc(targ->buf, saved_buf_str);
	ft_putstr(targ->buf->str);
	xfree(saved_buf_str);
	return (false);
}
