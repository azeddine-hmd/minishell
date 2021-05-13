/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:03:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/05/13 17:59:29 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell(t_cmdslst **cmdslst, t_cap *cap, t_buf *buf)
{
	t_cmdslst	*current;
	char		input;
	char		*synerr;
	int			pos;

	// a fake list for debugging
	/*fake_cmdslst(cmdslst);*/

	ms_prompt();

	// point current to the last element in the list
	/*current = get_last_cmdslst(*cmdslst);*/

	// point current to the first element in the list
	/*current = *cmdslst;*/

	current = (t_cmdslst*)xmalloc(sizeof(t_cmdslst));
	add_cmdslst(cmdslst, current);
	pos = 0;

	// valid while loop
	while (read(STDIN_FILENO, &input, 1) == 1)

	// simulating input with sequence of characters
	/*char inputs[30000];
	ft_bzero(inputs, 30000);
	sprintf(inputs, "echo first\necho second\ntest%c%c%c%c%c%cddddddddddddd%c%c%c%c%c%c", 27, K_OSB, K_A, 27, K_OSB, K_A, 27, K_OSB, K_B, 27, K_OSB, K_A);
	int i = -1;
	while ((input = inputs[++i]))*/

	{
		if (input == K_BS)
		{

			fprintf(ms_log, "key: BACKSPACE\n");
			fflush(ms_log);

			ms_bufdel(buf, cap);

		}
		else if (input == K_ENTER)
		{

			fprintf(ms_log, "key: ENTER\n");
			fflush(ms_log);

			ft_putc(input);

			if (ft_strlen(buf->buf) == 0)
			{
				ms_prompt();
				continue ;
			}

			if (current->cmds_str == NULL)
			{
				current->cmds_str = xstrdup(buf->buf);
			}


			if (current->cmds == NULL)
			{
				parse(buf->buf, &(current->cmds), &synerr);
			}

			//print_all_cmds(current->cmds);
			print_all_cmdslst(*cmdslst);

			current = (t_cmdslst*)xmalloc(sizeof(t_cmdslst));
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

			if (current->cmds_str == NULL)
			{
				current->cmds_str = xstrdup(buf->buf);
			}
			else if (current->cmds_str != NULL)
			{
				if (ft_strlen(buf->buf) != 0)
				{
					char *tmp = current->cmds_str;
					current->cmds_str = xstrdup(buf->buf);
					xfree(tmp);
				}
			}

			if (*cmdslst == NULL)
			{
				continue ;
			}
			else if (current->previous == NULL)
			{
				continue ;
			}
			else
			{
				current = current->previous;
				ms_lndel(cap, buf->pos);
				ms_bufrpc(buf, current->cmds_str);
				printf("%s", current->cmds_str);
			}

		}
		else if (pos == 2 && input == K_B)
		{

			fprintf(ms_log, "key: DOWN_ARROW\n");
			fflush(ms_log);

			pos = 0;

			// have not been debugged
			if (strlen(cmds_str) > 0)
			{
				if (buf->buf != current->cmds_str)
				{
					current->original = xstrdup(buf->buf);
				}
			}

			if (current->cmds_str == NULL)
			{
				current->cmds_str = xstrdup(buf->buf);
			}
			else if (current->cmds_str != NULL)
			{
				if (ft_strlen(buf->buf) != 0)
				{
					char *tmp = current->cmds_str;
					current->cmds_str = xstrdup(buf->buf);
					xfree(tmp);
				}
			}

			if (*cmdslst == NULL)
			{
				continue ;
			}
			else if (current->next == NULL)
			{
				// ignore
				continue ;
			}
			else
			{
				current = current->next;


				ms_lndel(cap, buf->pos);
				ms_bufrpc(buf, current->cmds_str);
				printf("%s", current->cmds_str);
			}

		}
		else if (input == K_CTRL_D)
		{

			if (ft_strlen(buf->buf) == 0)
			{
				break ;
			}

		}
		else if (
				input == K_CTRL_L || input == K_CTRL_I || input == K_CTRL_H ||
				input == K_CTRL_K)
		{
			// ignore
			continue ;
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
