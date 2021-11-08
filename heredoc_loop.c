#include "minishell.h"

static void		hd_prompt(void)
{
	ft_putstr(MS_HEREDOC_COLOR);
	ft_putstr(MS_HEREDOC_PROMPT);
	ft_putstr(COLORS_DEFAULT);
}

char	*format_heredoc_err(const char *delimiter)
{
	char *joined;
	char *tmp;

	joined = xstrdup(HEREDOC_ERR);
	tmp = joined;
	joined = xstrjoin(joined, delimiter);
	xfree(tmp);
	tmp = joined;
	joined = xstrjoin(joined, "')");
	xfree(tmp);
	return (joined);
}

static t_bool	hd_ctrl_d_triggered(t_termarg *targ)
{
	if (ft_strlen(targ->buf->str) == 0)
	{
		ft_putc('\n');
		return (true);
	}
	return (false);
}

char			*heredoc_loop(t_termarg *targ, const char *delimiter, char **env)
{
	t_list	*lines_lst;
	char	*fcontent;
	char	*saved_bufstr;
	t_bool	expand_enabled;
	char	*stripped_delimiter;

	lines_lst = NULL;
	saved_bufstr = xstrdup(targ->buf->str);
	ms_bufrst(targ->buf);
	hd_prompt();
	stripped_delimiter = strip_quotes(delimiter);
	if (not_equal(delimiter, stripped_delimiter))
		expand_enabled = false;
	else
		expand_enabled = true;
	while (read(STDIN_FILENO, &(targ->input), 1) == 1)
	{
		if (g_sign.stop_heredoc)
			break ;
		if (targ->input == K_BS)
			backspace_triggered(targ);
		else if (targ->input == K_ENTER)
		{
			print_keys(targ->input);
			if (equal(targ->buf->str, stripped_delimiter))
			{
				lstpush(&lines_lst, "\n");
				ft_putc(targ->input);
				break ;
			}
			else
			{
				ft_putc(targ->input);
				if (expand_enabled)
					lstpush(&lines_lst, expand((targ->buf->str), env, false));
				else
					lstpush(&lines_lst, xstrdup(targ->buf->str));
				ms_bufrst(targ->buf);
				hd_prompt();
			}
		}
		else if (targ->input == K_ESC)
			targ->pos++;
		else if (targ->pos == 1 && targ->input == K_OSB)
			targ->pos++;
		else if (targ->pos == 2 && targ->input == K_A)
			// ignore
			;
		else if (targ->pos == 2 && targ->input == K_B)
			// ignore
			;
		else if (targ->pos == 2 && targ->input == K_C)
			// ignore
			;
		else if (targ->pos == 2 && targ->input == K_D)
			// ignore
			;
		else if (targ->pos == 2)
			targ->pos = 0;
		else if (targ->input == K_CTRL_D)
		{
			if (hd_ctrl_d_triggered(targ))
				break ;
		}
		else if (targ->input == K_CTRL_L)
			// ignore
			;
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
			print_keys(targ->input);
			ms_bufadd(targ->buf, targ->input);
			ft_putc(targ->input);
			targ->pos = 0;
		}
	}
	ms_bufrpc(targ->buf, saved_bufstr);
	xfree(saved_bufstr);
	if (is_not_null(lines_lst))
		fcontent = join_string_list_with_nl(lines_lst);
	else
		fcontent = xstrdup("");
	lstclear(&lines_lst, str_del);
	return (fcontent);
}
