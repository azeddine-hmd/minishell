#include "minishell.h"
#include "libx/libx.h"

FILE *ms_log;
FILE *ms_buflog;

static void	minishell_loop(t_termarg *targ)
{
	ms_prompt();
	targ->cur = (t_cmdslst*)xmalloc(sizeof(t_cmdslst));
	add_cmdslst(&(targ->head), targ->cur);
	while (read(STDIN_FILENO, &(targ->input), 1) == 1)
	// simulating input with sequence of characters
	/*char inputs[30000];
	ft_bzero(inputs, 30000);
	sprintf(inputs, "echo 1\nholder%c%c%c%c%c%c<appended>\n", K_UP_ARROW, K_DOWN_ARROW);
	int i = -1;
	while ((input = inputs[++i]))*/
	{
		if (targ->input == K_BS)
			backspace_triggered(targ);
		else if (targ->input == K_ENTER)
			enter_triggered(targ);
		else if (targ->input == K_ESC)
			targ->pos++;
		else if (targ->pos == 1 && targ->input == K_OSB)
			targ->pos++;
		else if (targ->pos == 2 && targ->input == K_A)
			up_arrow_triggered(targ);
		else if (targ->pos == 2 && targ->input == K_B)
			down_arrow_triggered(targ);
		else if (targ->input == K_CTRL_D)
		{
			if (ctrl_d_triggered(targ))
				break ;
		}
		else if (
				targ->input == K_CTRL_L || targ->input == K_CTRL_I ||
				targ->input == K_CTRL_H || targ->input == K_CTRL_K)
		{
			continue ;
		}
		else
		{
#ifdef DEBUG
			fprintf(ms_log, "key: %d\n", targ->input);
			fflush(ms_log);
#endif
			ms_bufadd(targ->buf, targ->input);
			targ->pos = 0;
		}
	}
}

int		main(void)
{
#ifdef DEBUG
	ms_log = fopen(DEBUG_LOG_PATH, "a");
	ms_buflog = fopen(DEBUG_BUFLOG_PATH, "a");
#endif
	t_termarg	targ;

	//TODO: is setbuf() stdlib function allowed in this project?
	setbuf(stdout, NULL);
	ft_bzero(&targ, sizeof(t_termarg));
	ms_setup(&(targ.cap), &(targ.buf));
	minishell_loop(&targ);
	deallocate();
	return (0);
}
