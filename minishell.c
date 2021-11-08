#include "minishell.h"

static void	minishell_loop(t_termarg *targ, char **env)
{
	t_bool skip;

	g_sign.env = &env;
	ms_prompt(getret(env));
	targ->cur = (t_hist*)xmalloc(sizeof(t_hist));
	add_history(&(targ->head), targ->cur);
	skip = false;
	while (skip || read(STDIN_FILENO, &(targ->input), 1) == 1)
	{
		if (skip)
			skip = false;
		if (targ->input == K_BS)
			backspace_triggered(targ);
		else if (targ->input == K_ENTER)
			skip = enter_triggered(targ, &env);
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
			if (ctrl_d_triggered(targ))
				ft_builtin_exit(NULL, getret(env));
		}
		else if (targ->input == K_CTRL_L)
			ctrl_l_triggered(targ, env);
		else if (
				targ->input == K_CTRL_I ||
				targ->input == K_CTRL_H ||
				targ->input == K_CTRL_K
				)
		{
			;
		}
		else
		{
			print_keys(targ->input);
			ms_bufadd(targ->buf, targ->input);
			ft_putc(targ->input);
			targ->pos = 0;
		}
	}
}



int		main(int argc, char **argv, char **env)
{
	t_termarg	targ;
	char		**p_env;

	// debugging
	ms_log = fopen(DEBUG_LOG_PATH, "a");
	ms_buflog = fopen(DEBUG_BUFLOG_PATH, "a");
	pa_log = fopen(PARSE_DEBUG_LOG_PATH, "a");
	ms_signallog = fopen(DEBUG_SIGNAL_PATH, "a");

	(void)argv;
	if (argc != 1)
	{
		usage();
		return (EXIT_FAILURE);
	}
	signal(SIGINT, signal_interceptor);
	signal(SIGQUIT, signal_interceptor);
	p_env = init_env(env);
	ft_bzero(&targ, sizeof(t_termarg));
	g_sign.child_running = false;
	g_sign.targ = &targ;
	ms_setup(&(targ.cap), &(targ.buf));
	minishell_loop(&targ, p_env);
	shell_exit(getret(*(g_sign.env)));
	return (0);
}
