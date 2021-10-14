#include "minishell.h"

FILE *ms_log;
FILE *ms_buflog;
FILE *pa_log;

static void	minishell_loop(t_termarg *targ, t_list *env)
{
	ms_prompt(EXIT_SUCCESS);
	targ->cur = (t_cmdslst*)xmalloc(sizeof(t_cmdslst));
	add_cmdslst(&(targ->head), targ->cur);
	while (read(STDIN_FILENO, &(targ->input), 1) == 1)
	{
		if (targ->input == K_BS)
			backspace_triggered(targ);
		else if (targ->input == K_ENTER)
			enter_triggered(targ, &env);
		else if (targ->input == K_ESC)
			targ->pos++;
		else if (targ->pos == 1 && targ->input == K_OSB)
			targ->pos++;
		else if (targ->pos == 2 && targ->input == K_A)
			up_arrow_triggered(targ);
		else if (targ->pos == 2 && targ->input == K_B)
			down_arrow_triggered(targ);
		else if (targ->pos == 2 && targ->input == K_C)
			right_arrow_triggered(targ);
		else if (targ->pos == 2 && targ->input == K_D)
			left_arrow_triggered(targ);
		else if (targ->pos == 2)
			targ->pos = 0;
		else if (targ->input == K_CTRL_D)
		{
			if (ctrl_d_triggered(targ, false))
				break ;
		}
		else if (targ->input == K_CTRL_L)
			ctrl_l_triggered(targ);
		else if (
				targ->input == K_CTRL_I ||
				targ->input == K_CTRL_H ||
				targ->input == K_CTRL_K
				)
		{
			// ignore
		}
		else
		{
#ifdef DEBUG
			fprintf(ms_log, "key: %c\n", targ->input);
			fflush(ms_log);
#endif
			ms_bufadd(targ->buf, targ->input);
			ft_putc(targ->input);
			targ->pos = 0;
		}
	}
}

int		main(int argc, char **argv, char **env)
{
	t_termarg	targ;

	// debugging
	ms_log = fopen(DEBUG_LOG_PATH, "a");
	ms_buflog = fopen(DEBUG_BUFLOG_PATH, "a");
	pa_log = fopen(PARSE_DEBUG_LOG_PATH, "a");

	(void)argv;
	if (argc != 1)
	{
		usage();
		return (EXIT_FAILURE);
	}
	ft_bzero(&targ, sizeof(t_termarg));
	ms_setup(&(targ.cap), &(targ.buf));
	minishell_loop(&targ, string_array_to_string_list(env));
	deallocate();
	return (0);
}
