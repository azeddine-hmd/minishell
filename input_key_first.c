#include "minishell.h"

void	backspace_triggered(t_termarg *targ)
{
#ifdef DEBUG
	fprintf(ms_log, "key: BACKSPACE\n");
	fflush(ms_log);
#endif
	ms_bufdel(targ->buf, targ->cap);
}

void	enter_triggered(t_termarg *targ)
{
#ifdef DEBUG
	fprintf(ms_log, "key: ENTER\n");
	fflush(ms_log);
#endif
	char *syntax_error;

	syntax_error = NULL;
	ft_putc(targ->input);
	if (ft_strlen(targ->buf->str) == 0)
	{
		ms_prompt();
		return ;
	}
	if (targ->cur->cmds_str == NULL || targ->cur->cmds_str[0] == '\0')
	{
		targ->cur->cmds_str = xstrdup(targ->buf->str);
#ifdef DEBUG
		fprintf(ms_log, "buf: %s", targ->buf->str);
		fflush(ms_log);
#endif
	}
	if (targ->cur->cmds != NULL && ft_strlen(targ->buf->str) != 0 && ft_strcmp(targ->buf->str, targ->cur->cmds_str) != 0)
	{
		if (targ->cur->original == NULL)
			targ->cur->original = targ->cur->cmds_str;
		targ->cur->cmds_str = xstrdup(targ->buf->str);
	}
	if (targ->cur->cmds == NULL && ft_strlen(targ->buf->str) != 0 && ft_strcmp(targ->buf->str, targ->cur->cmds_str) != 0)
	{
		targ->cur->cmds_str = xstrdup(targ->buf->str);
	}
	if (targ->cur->original)
	{
		t_cmdslst *tmp;

		tmp = get_last_cmdslst(targ->head);
		if (tmp->cmds == NULL)
		{
			if (tmp->cmds_str)
				xfree(tmp->cmds_str);
			tmp->cmds_str = targ->cur->cmds_str;
			targ->cur->cmds_str = targ->cur->original;
			targ->cur->original = NULL;
			targ->cur = tmp;
		}
	}
	if (has_previous(targ->cur))
	{
		syntax_error = parse(targ->buf->str, &(targ->cur->cmds), targ->cur->previous->ret);
	}
	else
	{
		syntax_error = parse(targ->buf->str, &(targ->cur->cmds), EXIT_SUCCESS);
	}
	if (syntax_error == NO_SYNTAX_ERROR)
	{
		targ->cur->ret = execute(targ->cur->cmds, targ->buf->str);
	}
	else
	{
		shell_err(syntax_error);
		xfree(syntax_error);
	}
	// leaks debugging
	/*printf("\n=======leaks=======\n");
	system("leaks minishell | grep 'leaked bytes'");
	printf("===================\n\n");*/
	targ->cur = (t_cmdslst*)xmalloc(sizeof(t_cmdslst));
	add_cmdslst(&(targ->head), targ->cur);
	ms_bufrst(targ->buf);
	ms_prompt();
}

void	up_arrow_triggered(t_termarg *targ)
{
#ifdef DEBUG
	fprintf(ms_log, "key: UP_ARROW\n");
	fflush(ms_log);
#endif

	targ->pos = 0;
	if (targ->head == NULL)
		return ;
	if (targ->cur->previous == NULL)
		return ;
	if (targ->cur->cmds_str == NULL)
	{
		targ->cur->cmds_str = xstrdup(targ->buf->str);
	}
	if (ft_strlen(targ->buf->str) != 0 && ft_strcmp(targ->buf->str, targ->cur->cmds_str))
	{
		if (targ->cur->original == NULL)
			targ->cur->original = targ->cur->cmds_str;
		targ->cur->cmds_str = xstrdup(targ->buf->str);
	}

	targ->cur = targ->cur->previous;
	ms_lndel(targ->cap, targ->buf);
	ms_bufrpc(targ->buf, targ->cur->cmds_str);
	printf("%s", targ->cur->cmds_str);
}

void		down_arrow_triggered(t_termarg *targ)
{
#ifdef DEBUG
	fprintf(ms_log, "key: DOWN_ARROW\n");
	fflush(ms_log);
#endif
	targ->pos = 0;
	if (targ->head == NULL)
		return ;
	if (targ->cur->next == NULL)
		return ;
	if (targ->cur->cmds_str == NULL)
		targ->cur->cmds_str = xstrdup(targ->buf->str);
	if (ft_strlen(targ->buf->str) != 0 && ft_strcmp(targ->buf->str, targ->cur->cmds_str))
	{
		if (targ->cur->original == NULL)
			targ->cur->original = targ->cur->cmds_str;
		targ->cur->cmds_str = xstrdup(targ->buf->str);
	}
	targ->cur = targ->cur->next;
	ms_lndel(targ->cap, targ->buf);
	ms_bufrpc(targ->buf, targ->cur->cmds_str);
	printf("%s", targ->cur->cmds_str);
}

t_bool	ctrl_d_triggered(t_termarg *targ)
{
	if (ft_strlen(targ->buf->str) == 0)
		return (true);
	return (false);
}
