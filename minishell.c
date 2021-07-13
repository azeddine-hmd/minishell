#include "minishell.h"

static void	minishell(t_cmdslst **cmdslst, t_cap *cap, t_buf *buf)
{
	t_cmdslst	*current;
	char		input;
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

	// primary while loop
	while (read(STDIN_FILENO, &input, 1) == 1)

	// simulating input with sequence of characters
	/*char inputs[30000];
	ft_bzero(inputs, 30000);
	sprintf(inputs, "echo 1\nholder%c%c%c%c%c%c<appended>\n", K_UP_ARROW, K_DOWN_ARROW);
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
			char *syntax_error;

			syntax_error = NULL;
			fprintf(ms_log, "key: ENTER\n");
			fflush(ms_log);

			ft_putc(input);

			// pre-conditions
			if (ft_strlen(buf->buf) == 0)
			{
				ms_prompt();
				continue ;
			}
			if (current->cmds_str == NULL || current->cmds_str[0] == '\0')
			{
				current->cmds_str = xstrdup(buf->buf);
				fprintf(ms_log, "buf: %s", buf->buf);
				fflush(ms_log);
			}
			// override cmds_str and assign original
			// ignore tmp cmdslst
			if (current->cmds != NULL && ft_strlen(buf->buf) != 0 && ft_strcmp(buf->buf, current->cmds_str) != 0)
			{
				if (current->original == NULL)
					current->original = current->cmds_str;
				current->cmds_str = xstrdup(buf->buf);
			}
			if (current->cmds == NULL && ft_strlen(buf->buf) != 0 && ft_strcmp(buf->buf, current->cmds_str) != 0)
			{
				//TODO: please insert sommething here
				current->cmds_str = xstrdup(buf->buf);
			}

			// have not been debugged yet
			if (current->original)
			{
				t_cmdslst *tmp;

				tmp = get_last_cmdslst(*cmdslst);
				if (tmp->cmds == NULL)
				{
					if (tmp->cmds_str)
						xfree(tmp->cmds_str);
					tmp->cmds_str = current->cmds_str;
					current->cmds_str = current->original;
					current->original = NULL;
					current = tmp;
				}
				else
				{
					fprintf(ms_log, "Note: there is no temporary node");
					fflush(ms_log);
				}

			}

			// parsing
			if (has_previous(current))
				syntax_error = parse(buf->buf, &(current->cmds), current->previous->ret);
			else
				syntax_error = parse(buf->buf, &(current->cmds), EXIT_SUCCESS);

			// execution
			if (is_null(syntax_error))
			{
				current->ret = execute(current->cmds);
			}
			else
			{
				print_syntax_error(syntax_error);
			}

			// leaks debugging
			printf("\n=======leaks=======\n");
			system("leaks minishell | grep 'leaked bytes'");
			printf("===================\n\n");

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

			// pre-conditions
			if (*cmdslst == NULL)
			{
				continue ;
			}
			if (current->previous == NULL)
			{
				continue ;
			}
			if (current->cmds_str == NULL)
			{
				current->cmds_str = xstrdup(buf->buf);
			}

			// override cmds_str and assign original
			if (ft_strlen(buf->buf) != 0 && ft_strcmp(buf->buf, current->cmds_str))
			{
				if (current->original == NULL)
					current->original = current->cmds_str;
				current->cmds_str = xstrdup(buf->buf);
			}

			current = current->previous;
			ms_lndel(cap, buf->pos);
			ms_bufrpc(buf, current->cmds_str);
			printf("%s", current->cmds_str);
		}
		else if (pos == 2 && input == K_B)
		{

			fprintf(ms_log, "key: DOWN_ARROW\n");
			fflush(ms_log);

			pos = 0;


			// pre-conditions
			if (*cmdslst == NULL)
			{
				continue ;
			}
			if (current->next == NULL)
			{
				// ignore
				continue ;
			}
			if (current->cmds_str == NULL)
			{
				current->cmds_str = xstrdup(buf->buf);
			}

			// override cmds_str and assign original
			if (ft_strlen(buf->buf) != 0 && ft_strcmp(buf->buf, current->cmds_str))
			{
				if (current->original == NULL)
					current->original = current->cmds_str;
				current->cmds_str = xstrdup(buf->buf);
			}

			current = current->next;
			ms_lndel(cap, buf->pos);
			ms_bufrpc(buf, current->cmds_str);
			printf("%s", current->cmds_str);
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

	// debugging
	ms_log = fopen(DEBUG_LOG_PATH, "a");
	ms_buflog = fopen(DEBUG_BUFLOG_PATH, "a");

	setbuf(stdout, NULL);
	ms_setup(&cap, &buf);
	minishell(&cmdslst, cap, buf);
	lst_clear(*get_head_node());
	return (0);
}
