/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:26:41 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 19:26:41 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_prompt(void)
{
	ft_putstr(MS_HEREDOC_COLOR);
	ft_putstr(MS_HEREDOC_PROMPT);
	ft_putstr(COLORS_DEFAULT);
}

char	*format_heredoc_err(const char *delimiter)
{
	char	*joined;
	char	*tmp;

	joined = xstrdup(HEREDOC_ERR);
	tmp = joined;
	joined = xstrjoin(joined, delimiter);
	xfree(tmp);
	tmp = joined;
	joined = xstrjoin(joined, "')");
	xfree(tmp);
	return (joined);
}

t_bool	hd_ctrl_d_triggered(t_termarg *targ, char **env, t_hd *heredoc)
{
	t_buf	*buf;

	buf = targ->buf;
	if (ft_strlen(targ->buf->str) == 0)
	{
		if (heredoc->expand_enabled)
			lstpush(&(heredoc->lines_lst), expand((buf->str), env, false));
		else
			lstpush(&(heredoc->lines_lst), xstrdup(buf->str));
		return (true);
	}
	return (false);
}
