#include "minishell.h"

static void	minishell_loop(t_termarg *targ, char **env)
{
	t_bool newline_after_heredoc;

	ms_prompt(getret(env));
	targ->cur = (t_hist*)xmalloc(sizeof(t_hist));
	add_history(&(targ->head), targ->cur);
	while (read(STDIN_FILENO, &(targ->input), 1) == 1)
	{
		if (targ->input == K_BS)
			backspace_triggered(targ);
		else if (targ->input == K_ENTER)
		{
			newline_after_heredoc = enter_triggered(targ, &env);
			while (newline_after_heredoc)
				newline_after_heredoc = enter_triggered(targ, &env);
		}
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

int			env_len(char **env) // to modify later. (No need for J)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while(env[++i])
		j++;
	return  (j);
}

void		*safe_malloc(size_t size)  // equal to ft_memalloc() | To modify later
{
	void	*ptr;

	if (!(ptr = xmalloc(size + 1)))
		return (NULL);
	ft_bzero(ptr, size + 1);
	return (ptr);
}

int		error_msg(char *error_msg, int fd, int exit_code)
{
	write(fd, error_msg, ft_strlen(error_msg));
	return (exit_code);
}

char	**init_env(char **env)
{
	int		i;
	char	**p_env;

	p_env = (char**)safe_malloc(sizeof(char *) * (env_len(env) + 1));
	i = 0;
	p_env[i] = xstrdup("?=0");
	while (env[++i])
	{
		if (!(p_env[i] = xstrdup(env[i])))
			error_msg("A memory allocation failed!\n", 2, 0);
	}
	return (p_env);
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
	g_sign.env = p_env;
	ms_setup(&(targ.cap), &(targ.buf));
	minishell_loop(&targ, p_env);
	shell_exit(getret(p_env));
	return (0);
}
