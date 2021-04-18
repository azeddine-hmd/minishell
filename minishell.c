/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:03:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/18 17:32:37 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell(t_cmdslst **cmdslst, t_cap *cap, t_buf *buf)
{
	t_cmdslst	*current;
	char		input;
	char		*synerr;
	int			pos;

	// debugging
	fake_cmdslst(cmdslst);
	ms_prompt();
	pos = 0;
	while (read(STDIN_FILENO, &input, 1) == 1)
	{
		if (input == K_BS)
		{
			fprintf(ms_log, "key: BACKSPACE\n");
			fflush(ms_log);
			ms_bufdel(buf, cap);
		}
		else if (input == K_CR)
		{
			fprintf(ms_log, "key: ENTER\n");
			fflush(ms_log);
			ft_putc(input);
			if (ft_strlen(buf->buf) == 0)
			{
				ms_prompt();
				continue ;
			}
			current = (t_cmdslst*)xmalloc(sizeof(t_cmdslst));
			parse(buf->buf, &(current->cmds), &synerr);
			synerr++; // supress unused variable error
			print_all_cmds(current->cmds);
			current->cmds_str = xstrdup(buf->buf);
			add_cmdslst(cmdslst, current);
			ms_bufrst(buf);
			ms_prompt();
		}
		else if (input == 27)
		{
			pos++;
		}
		else if (pos == 1 && input == K_OSB)
		{
			pos++;
		}
		else if (pos == 2 && input == K_A)
		{
			fprintf(ms_log, "key: UP_ARROW\n");
			fflush(ms_log);
			pos = 0;
		}
		else if (pos == 2 && input == K_B)
		{
			fprintf(ms_log, "key: DOWN_ARROW\n");
			fflush(ms_log);
			pos = 0;
		}
		else if (input == K_CTRL_D)
		{
			if (ft_strlen(buf->buf) == 0)
				break ;
		}
		else
		{
			fprintf(ms_log, "key: %d\n", input);
			fflush(ms_log);
			ms_bufadd(buf, input);
			pos = 0;
		}
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

	setbuf(stdout, NULL);
	ms_setup(&cap, &buf);
	minishell(&cmdslst, cap, buf);
	lst_clear(*get_head_node());
	return (0);
}
