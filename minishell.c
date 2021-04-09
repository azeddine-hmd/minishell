/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:03:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/09 13:28:02 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell(t_cmd **cmd_lst, t_cap cap, t_buf *buf, char out)
{
	char	*syntax_err;

	while (read(STDIN_FILENO, &out, 1) == 1)
	{
		if (out == K_BS)
		{
			fprintf(ms_log, "key: BACKSPACE\n");
			fflush(ms_log);
			ms_bufdel(buf, cap);
		}
		else if (out == K_CR)
		{
			fprintf(ms_log, "key: ENTER\n");
			fflush(ms_log);
			ft_putc(out);
			parse(buf->buf, cmd_lst, &syntax_err);
			ms_bufrst(buf);
			ms_prompt();
		}
		else
		{
			fprintf(ms_log, "key: %c\n", out);
			fflush(ms_log);
			ms_bufadd(buf, out);
		}
	}
}

int		main(void)
{
	t_cmd	**cmds_lst;
	t_buf	*buf;
	char	out;
	t_cap	cap;

	// debugging (initializing log files)
	ms_log = fopen("/Users/ahamdaou/development/42cursus/github/minishell/log", "a");
	ms_buflog = fopen("/Users/ahamdaou/development/42cursus/github/minishell/buflog", "a");

	setbuf(stdout, NULL);
	*cmds_lst = NULL;
	ms_setup(&cap, &buf);
	minishell(cmds_lst, cap, buf, out);
	lst_clear(*get_head_node());
	return (0);
}
