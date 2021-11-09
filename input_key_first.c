#include "minishell.h"

static t_bool	prepare_history(t_termarg *targ, char **env)
{
	ft_putc(targ->input);
	if (ft_strlen(targ->buf->str) == 0)
	{
		ms_prompt(getret(env));
		return (true);
	}
	targ->cur = get_last_history(targ->head);
	if (is_not_null(targ->cur->cmdln_str))
		xfree(targ->cur->cmdln_str);
	targ->cur->cmdln_str = xstrdup(targ->buf->str);
	return (false);
}

static void	prepare_parsing(t_termarg *targ, t_painfo *painfo, char ***env)
{
	if (has_previous(targ->cur))
		painfo->syntax_error = parse(targ->buf->str, &(painfo->cmd_lst), *env);
	else
		painfo->syntax_error = parse(targ->buf->str, &(painfo->cmd_lst), *env);
}

static t_bool	prepare_heredoc(t_termarg *targ, t_painfo *painfo, char ***env)
{
	painfo->heredoc_lst = get_heredoc_lst(painfo->cmd_lst);
	if (is_not_null(painfo->heredoc_lst))
	{
		g_sign.heredoc_running = true;
		if (has_previous(targ->cur))
			heredoc_entry(targ, painfo->heredoc_lst, *env);
		else
			heredoc_entry(targ, painfo->heredoc_lst, *env);
		g_sign.heredoc_running = false;
	}
	if (g_sign.stop_heredoc)
	{
		g_sign.stop_heredoc = false;
		lstclear(&(painfo->cmd_lst), cmd_del);
		targ->pos = 0;
		targ->cur = (t_hist*)xmalloc(sizeof(t_hist));
		add_history(&(targ->head), targ->cur);
		ms_bufrst(targ->buf);
		return (true);
	}
	return (false);
}

static void	prepare_execution(t_painfo *painfo, char ***env)
{
	strip_side_quotes(painfo->cmd_lst);
	if (painfo->syntax_error == NO_SYNTAX_ERROR)
		execute(painfo->cmd_lst, env);
	else
	{
		*env = export_var("?", "1", *env);
		shell_err(painfo->syntax_error);
		xfree(painfo->syntax_error);
	}
	lstclear(&(painfo->cmd_lst), cmd_del);
}

t_bool	enter_triggered(t_termarg *targ, char ***env)
{
	t_painfo painfo;

	painfo.cmd_lst = EMPTY_LIST;
	painfo.syntax_error = NO_SYNTAX_ERROR;
	painfo.heredoc_lst = EMPTY_LIST;
	if (prepare_history(targ, *env))
		return (false);
	prepare_parsing(targ, &painfo, env);
	if (prepare_heredoc(targ, &painfo, env))
		return (true);
	prepare_execution(&painfo, env);
	targ->cur = (t_hist*)xmalloc(sizeof(t_hist));
	add_history(&(targ->head), targ->cur);
	ms_bufrst(targ->buf);
	ms_prompt(getret(*env));
	return (false);
}
