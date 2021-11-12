/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:48:26 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 21:48:26 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_content_lst(t_termarg *targ, t_hdentry *hdentry, char **env)
{
	hdentry->hd_iterator = hdentry->heredoc_lst;
	hdentry->fcontent_lst = EMPTY_LIST;
	hdentry->file_suffix = 0;
	while (hdentry->hd_iterator)
	{
		hdentry->hd_token = (t_token *)hdentry->hd_iterator->content;
		hdentry->fcontent = heredoc_loop(targ, hdentry->hd_token->value, env);
		lstpush(&(hdentry->fcontent_lst), hdentry->fcontent);
		if (g_sign.stop_heredoc)
		{
			if (not_null(hdentry->fcontent_lst))
				lstclear(&(hdentry->fcontent_lst), str_del);
			return ;
		}
		hdentry->hd_iterator = (hdentry->hd_iterator)->next;
	}
}

void	heredoc_entry(t_termarg *targ, t_list *heredoc_lst, char **env)
{
	t_hdentry	hdentry;
	char		*file_suffix_str;
	char		*pathname;
	int			fd;

	hdentry.heredoc_lst = heredoc_lst;
	set_content_lst(targ, &hdentry, env);
	hdentry.hd_iterator = hdentry.heredoc_lst;
	while (hdentry.hd_iterator && hdentry.fcontent_lst)
	{
		file_suffix_str = xitoa(hdentry.file_suffix);
		pathname = xstrjoin(FILE_PREFIX, file_suffix_str);
		xfree(file_suffix_str);
		hdentry.fcontent = hdentry.fcontent_lst->content;
		fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, FILE_PREMISSION);
		write(fd, hdentry.fcontent, ft_strlen(hdentry.fcontent));
		hdentry.hd_token = (t_token *)hdentry.hd_iterator->content;
		xfree(hdentry.hd_token->value);
		hdentry.hd_token->value = pathname;
		close(fd);
		hdentry.file_suffix++;
		hdentry.fcontent_lst = hdentry.fcontent_lst->next;
		hdentry.hd_iterator = hdentry.hd_iterator->next;
	}
	lstclear(&hdentry.fcontent_lst, str_del);
}
