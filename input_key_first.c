#include "minishell.h"

t_bool	backspace_triggered(t_termarg *targ)
{
	if (targ->buf->pos > 0)
		ms_chrdel(targ->cap);
	ms_bufdel(targ->buf);
	return (false);
}

t_bool	enter_triggered(t_termarg *targ, char ***env)
{
	char	*syntax_error;
	t_list	*heredoc_lst;

	syntax_error = NULL;
	ft_putc(targ->input);
	if (ft_strlen(targ->buf->str) == 0)
	{
		ms_prompt(getret(*env));
		return (false);
	}
	targ->cur = get_last_history(targ->head);
	if (is_not_null(targ->cur->cmdln_str))
		xfree(targ->cur->cmdln_str);
	targ->cur->cmdln_str = xstrdup(targ->buf->str);
	t_list	*cmd_lst;
	cmd_lst = NULL;
	if (has_previous(targ->cur))
		syntax_error = parse(targ->buf->str, &cmd_lst, *env);
	else
		syntax_error = parse(targ->buf->str, &cmd_lst, *env);

	heredoc_lst = get_heredoc_lst(cmd_lst);
	if (is_not_null(heredoc_lst))
	{
		g_sign.heredoc_running = true;
		if (has_previous(targ->cur))
			heredoc_entry(targ, heredoc_lst, *env);
		else
			heredoc_entry(targ, heredoc_lst, *env);
		g_sign.heredoc_running = false;
	}
	if (g_sign.stop_heredoc)
	{
		g_sign.stop_heredoc = false;
		lstclear(&cmd_lst, cmd_del);
		targ->pos = 0;
		targ->cur->ret = 1;
		targ->cur = (t_hist*)xmalloc(sizeof(t_hist));
		add_history(&(targ->head), targ->cur);
		ms_bufrst(targ->buf);
		return (true);
	}
	strip_side_quotes(cmd_lst);
	if (syntax_error == NO_SYNTAX_ERROR)
	{
		set_raw_mode(false);
		execute(cmd_lst, env);
		set_raw_mode(true);
		targ->cur->ret = ft_atoi(pa_getenv(*env, "?"));
	}
	else
	{
		*env = export_var("?", "1", *env);
		shell_err(syntax_error);
		xfree(syntax_error);
	}
	lstclear(&cmd_lst, cmd_del);
	targ->cur = (t_hist*)xmalloc(sizeof(t_hist));
	add_history(&(targ->head), targ->cur);
	ms_bufrst(targ->buf);
	ms_prompt(getret(*env));
	return (false);
}

t_bool	up_arrow_triggered(t_termarg *targ)
{
	targ->pos = 0;
	if (!has_previous(targ->cur))
		return (false) ;
	if (is_null(targ->cur->cmdln_str))
		targ->cur->cmdln_str = xstrdup(targ->buf->str);
	targ->cur = targ->cur->previous;
	ms_lndel(targ->cap, targ->buf->last);
	ms_bufrpc(targ->buf, targ->cur->cmdln_str);
	ft_putstr(targ->cur->cmdln_str);
	return (false);
}

t_bool		down_arrow_triggered(t_termarg *targ)
{
	targ->pos = 0;
	if (targ->cur->next == NULL)
		return (false);
	targ->cur = targ->cur->next;
	ms_lndel(targ->cap, targ->buf->last);
	if (is_null(targ->cur->cmdln_str))
		ms_bufrst(targ->buf);
	else
		ms_bufrpc(targ->buf, targ->cur->cmdln_str);
	ft_putstr(targ->buf->str);
	return (false);
}

t_bool	ctrl_d_triggered(t_termarg *targ)
{
	if (ft_strlen(targ->buf->str) == 0)
		return (true);
	return (false);
}
