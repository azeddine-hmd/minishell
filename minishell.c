#include "minishell.h"

FILE *ms_log;
FILE *ms_buflog;
FILE *pa_log;

static void	minishell_loop(t_termarg *targ, char **env)
{
	ms_prompt(EXIT_SUCCESS);
	targ->cur = (t_cmdslst*)xmalloc(sizeof(t_cmdslst));
	add_cmdslst(&(targ->head), targ->cur);
	while (read(STDIN_FILENO, &(targ->input), 1) == 1)
	{
		if (targ->input == K_BS)
			backspace_triggered(targ);
		else if (targ->input == K_ENTER)
			enter_triggered(targ, env);
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
/*




*/

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

	if (!(ptr = malloc(size + 1)))
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
	i = -1;
	while (env[++i])
	{
		if (!(p_env[i] = ft_strdup(env[i])))
			error_msg("A memory allocation failed!\n", 2, 0);
	}
	return (p_env);
}

/*

*/
int		main(int argc, char **argv, char **env)
{
	t_termarg	targ;
	char		**p_env;

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
	p_env = init_env(env);
	minishell_loop(&targ, p_env);
	deallocate();
	return (0);
}
