#include "minishell.h"

void	heredoc_entry(t_termarg *targ, t_list *heredoc_lst, char **env)
{
	t_list		*fcontent_lst;
	t_list		*hd_iterator;
	t_token		*hd_token;
	char		*fcontent;
	int			file_suffix;

	hd_iterator = heredoc_lst;
	fcontent_lst = NULL;
	file_suffix = 0;
	while (hd_iterator)
	{
		hd_token = (t_token*)hd_iterator->content;
		fcontent = heredoc_loop(targ, hd_token->value, env);
		ft_lstadd_back(&fcontent_lst, ft_lstnew(fcontent));
		hd_iterator = hd_iterator->next;
	}

	hd_iterator = heredoc_lst;
	while (hd_iterator || fcontent_lst)
	{
		char	*file_suffix_str;
		char	*pathname;
		int		fd;

		file_suffix_str = ft_itoa(file_suffix);
		pathname = xstrjoin(FILE_PREFIX, file_suffix_str);
		free(file_suffix_str);
		fcontent = fcontent_lst->content;
		fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, FILE_PREMISSION);
		write(fd, fcontent, ft_strlen(fcontent));
		hd_token = (t_token*)hd_iterator->content;
		xfree(hd_token->value);
		hd_token->value = pathname;
		close(fd);
		file_suffix++;
		fcontent_lst = fcontent_lst->next;
		hd_iterator = hd_iterator->next;
	}
	ft_lstclear(&fcontent_lst, str_del);
}
