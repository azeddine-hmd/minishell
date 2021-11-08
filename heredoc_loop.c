#include "minishell.h"

static void	heredoc_bloop(t_termarg *targ, t_hd *heredoc, const char *delimiter)
{
	heredoc->lines_lst = NULL;
	heredoc->saved_bufstr = xstrdup(targ->buf->str);
	ms_bufrst(targ->buf);
	hd_prompt();
	heredoc->stripped_delimiter = strip_quotes(delimiter);
	if (not_equal(delimiter, heredoc->stripped_delimiter))
		heredoc->expand_enabled = false;
	else
		heredoc->expand_enabled = true;
}

static void	heredoc_aloop(t_termarg *targ, t_hd *heredoc)
{
	ms_bufrpc(targ->buf, heredoc->saved_bufstr);
	xfree(heredoc->saved_bufstr);
	if (is_not_null(heredoc->lines_lst))
		heredoc->fcontent = join_string_list_with_nl(heredoc->lines_lst);
	else
		heredoc->fcontent = xstrdup("");
	lstclear(&(heredoc->lines_lst), str_del);
}

static t_bool	keys_cases_extanded(t_termarg *targ)
{
	if (targ->pos == 2)
		targ->pos = 0;
	else if (targ->input == K_CTRL_D)
	{
		if (hd_ctrl_d_triggered(targ))
			return (true);
	}
	else if (targ->input == K_CTRL_L)
		(void)NULL;
	else if (targ->input == K_CTRL_I || targ->input == K_CTRL_H
		|| targ->input == K_CTRL_K)
		(void)NULL;
	else
	{
		ms_bufadd(targ->buf, targ->input);
		ft_putc(targ->input);
		targ->pos = 0;
	}
	return (false);
}

static t_bool	keys_cases(t_termarg *targ, char **env, t_hd *heredoc)
{
	if (targ->input == K_BS)
		backspace_triggered(targ);
	else if (targ->input == K_ENTER)
	{
		if (hd_enter_triggered(targ, env, heredoc))
			return (true);
	}
	else if (targ->input == K_ESC)
		targ->pos++;
	else if (targ->pos == 1 && targ->input == K_OSB)
		targ->pos++;
	else if (targ->pos == 2 && targ->input == K_A)
		(void)NULL;
	else if (targ->pos == 2 && targ->input == K_B)
		(void)NULL;
	else if (targ->pos == 2 && targ->input == K_C)
		(void)NULL;
	else if (targ->pos == 2 && targ->input == K_D)
		(void)NULL;
	else
		if (keys_cases_extanded(targ))
			return (true);
	return (false);
}

char	*heredoc_loop(t_termarg *targ, const char *delimiter, char **env)
{
	t_hd	heredoc;

	heredoc_bloop(targ, &heredoc, delimiter);
	while (read(STDIN_FILENO, &(targ->input), 1) == 1)
	{
		if (g_sign.stop_heredoc)
			break ;
		if (keys_cases(targ, env, &heredoc))
			break ;
	}
	heredoc_aloop(targ, &heredoc);
	return (heredoc.fcontent);
}
