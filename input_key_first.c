#include "minishell.h"

t_bool	backspace_triggered(t_termarg *targ)
{
#ifdef DEBUG
	fprintf(ms_log, "key: BACKSPACE\n");
	fflush(ms_log);
#endif
	if (targ->buf->pos > 0)
		ms_chrdel(targ->cap);
	ms_bufdel(targ->buf);
	return (false);
}

t_bool	enter_triggered(t_termarg *targ, char **env)
{
#ifdef DEBUG
	fprintf(ms_log, "key: ENTER\n");
	fflush(ms_log);
#endif
	char	*syntax_error;
	t_list	*heredoc_lst;

	syntax_error = NULL;
	ft_putc(targ->input);
	if (ft_strlen(targ->buf->str) == 0)
	{
		ms_prompt(targ->cur->ret);
		return (false);
	}
	targ->cur = get_last_history(targ->head);
	if (is_not_null(targ->cur->cmdln_str))
		xfree(targ->cur->cmdln_str);
	targ->cur->cmdln_str = xstrdup(targ->buf->str);
#ifdef DEBUG
	fprintf(ms_buflog, "cmdln: %s\n\n", targ->buf->str);
	fflush(ms_log);
#endif
	t_list	*cmd_lst;

	cmd_lst = NULL;
	if (has_previous(targ->cur))
		syntax_error = parse(targ->buf->str, &cmd_lst, env, targ->cur->previous->ret);
	else
		syntax_error = parse(targ->buf->str, &cmd_lst, env, EXIT_SUCCESS);
	heredoc_lst = get_heredoc_lst(cmd_lst);
	if (is_not_null(heredoc_lst))
		heredoc_entry(targ, heredoc_lst);
	if (syntax_error == NO_SYNTAX_ERROR)
	{
		targ->cur->ret = execute(cmd_lst, env);
	}
	else
	{
		shell_err(syntax_error);
		xfree(syntax_error);
	}
	ft_lstclear(&cmd_lst, cmd_del);
	targ->cur = (t_hist*)xmalloc(sizeof(t_hist));
	add_history(&(targ->head), targ->cur);
	ms_bufrst(targ->buf);
	ms_prompt(targ->cur->ret);
	return (false);
}

t_bool	up_arrow_triggered(t_termarg *targ)
{
#ifdef DEBUG
	fprintf(ms_log, "key: UP_ARROW\n");
	fflush(ms_log);
#endif
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
#ifdef DEBUG
	fprintf(ms_log, "key: DOWN_ARROW\n");
	fflush(ms_log);
#endif
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

t_bool	ctrl_d_triggered(t_termarg *targ, t_bool on_heredoc)
{
	if (on_heredoc)
	{
		if (ft_strlen(targ->buf->str) == 0)
		{
			ft_putc('\n');
			shell_err(HEREDOC_ERR);
			return (true);
		}
	}
	else
	{
		if (ft_strlen(targ->buf->str) == 0)
			return (true);
	}
	return (false);
}
