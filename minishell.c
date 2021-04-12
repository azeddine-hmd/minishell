/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:03:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/10 19:00:00 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell(t_cmdslst *cmdslst, t_cap *cap, t_buf *buf)
{
	char	out;
	char	*synerr;

	ms_prompt();
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
			parse(buf->buf, &(cmdslst->cmds), &synerr);
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

void	ms_cmdsadd(t_cmdslst *cmdslst, t_cmd * cmd)
{
	if (cmdslst == NULL)
	{
		//TODO
	}
}

void	ms_cmdsget(void)
{
	t_cmdslst *cmdslst;

	cmdslst = (t_cmdslst*)xmalloc(sizeof(t_cmdslst));
	cmdslst->cmds =
}

void	fake_cmdslst(t_cmdslst **cmdslst)
{
	t_cmd *cmd;

	for (int i = 0; i < 10; i++) {
		cmd = ms_cmdsget();
		ms_cmdsadd(cmd);
	}
}

int		main(void)
{
	t_cmdslst	*cmdslst;
	t_buf		*buf;
	t_cap		*cap;

	cmdslst = NULL;
	cap = NULL;
	buf = NULL;

	// debugging (initializing log files)
	ms_log = fopen("/Users/ahamdaou/development/42cursus/github/minishell/log", "a");
	ms_buflog = fopen("/Users/ahamdaou/development/42cursus/github/minishell/buflog", "a");
	cmdslst = (t_cmdslst*)xmalloc(sizeof(t_cmdslst));
	fake_cmdslst(&cmdslst);

	setbuf(stdout, NULL);
	ms_setup(&cap, &buf);
	minishell(cmdslst, cap, buf);
	lst_clear(*get_head_node());
	return (0);
}
