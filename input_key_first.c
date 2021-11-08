#include "minishell.h"

void	//TODO: add prepare history function static signature

t_bool	enter_triggered(t_termarg *targ, char ***env)
{
	char	*syntax_error;
	t_list	*heredoc_lst;
	t_list	*cmd_lst;
	t_bool	bre;

	bre = false
	syntax_error = NULL;
	ft_putc(targ->input);
	if (ft_strlen(targ->buf->str) == 0)
	{
		ms_prompt(getret(*env));
		return (bre);
	}
	targ->cur = get_last_history(targ->head);
	if (is_not_null(targ->cur->cmdln_str))
		xfree(targ->cur->cmdln_str);
	targ->cur->cmdln_str = xstrdup(targ->buf->str);
	// TODO: slice this shit

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
		targ->cur = (t_hist*)xmalloc(sizeof(t_hist));
		add_history(&(targ->head), targ->cur);
		ms_bufrst(targ->buf);
		bre = true
		return (bre);
	}
	strip_side_quotes(cmd_lst);
	if (syntax_error == NO_SYNTAX_ERROR)
		execute(cmd_lst, env);
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
	return (bre);
}
