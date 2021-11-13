/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_interceptor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:24:11 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 21:24:11 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_heredoc_notrunning(void)
{
	t_termarg	*targ;

	(void)targ;
	targ = g_sign.targ;
	ft_putc('\n');
	ms_bufrst(targ->buf);
	*g_sign.env = export_var("?", "1", *g_sign.env);
	targ->cur = get_last_history(targ->head);
	ms_prompt(getret(*g_sign.env));
}

static void	while_child_running(void)
{
	ft_putc('\n');
}

static void	while_heredoc_running(void)
{
	t_termarg	*targ;

	(void)targ;
	targ = g_sign.targ;
	g_sign.stop_heredoc = true;
	ft_putc('\n');
	*g_sign.env = export_var("?", "1", *g_sign.env);
	ms_prompt(getret(*g_sign.env));
}

void	signal_interceptor(int sig)
{
	t_termarg	*targ;

	targ = g_sign.targ;
	if (sig == SIGINT)
	{
		if (g_sign.child_running)
			while_child_running();
		else if (g_sign.heredoc_running)
			while_heredoc_running();
		else
			child_heredoc_notrunning();
	}
	else if (sig == SIGQUIT && g_sign.child_running)
	{
		write(1, "Quit: 3\n", 8);
		return ;
	}
}
