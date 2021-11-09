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

void	heredoc_entry(t_termarg *targ, t_list *heredoc_lst, char **env)
{
	t_hdentry hdentry;

	//TODO: norm this shit
	hdentry.hd_iterator = heredoc_lst;
	fcontent_lst = EMPTY_LIST;
	file_suffix = 0;
	while (hd_iterator)
	{
		hd_token = (t_token *)hd_iterator->content;
		fcontent = heredoc_loop(targ, hd_token->value, env);
		lstpush(&fcontent_lst, fcontent);
		if (g_sign.stop_heredoc)
		{
			if (is_not_null(fcontent_lst))
				lstclear(&fcontent_lst, str_del);
			return ;
		}
		hd_iterator = hd_iterator->next;
	}

	hd_iterator = heredoc_lst;
	while (hd_iterator || fcontent_lst)
	{
		char	*file_suffix_str;
		char	*pathname;
		int		fd;

		file_suffix_str = xitoa(file_suffix);
		pathname = xstrjoin(FILE_PREFIX, file_suffix_str);
		xfree(file_suffix_str);
		fcontent = fcontent_lst->content;
		fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, FILE_PREMISSION);
		write(fd, fcontent, ft_strlen(fcontent));
		hd_token = (t_token *)hd_iterator->content;
		xfree(hd_token->value);
		hd_token->value = pathname;
		close(fd);
		file_suffix++;
		fcontent_lst = fcontent_lst->next;
		hd_iterator = hd_iterator->next;
	}
	lstclear(&fcontent_lst, str_del);
}
