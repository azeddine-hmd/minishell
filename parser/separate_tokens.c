#include "parser.h"

/*char	*separate(t_list **new_lst, char *str, char *old_remaining, t_list *quotes_range)
{
	char		*remaining;
	char		*new_str;
	t_tkindx	*token_index;
	int			start;
	int			end;

	token_index = get_token_index(old_remaining, str, quotes_range);
	if (is_null(token_index))
	{
		return (NULL);
	}
	else if (token_index->index == INDEX_NOT_FOUND)
	{
		shell_err("seperate tokens: illegal state");
		tkindx_del(token_index);
		return (NULL);
	}
	// substracting string before token
	start = 0;
	end = token_index->index - 1;
	if (end > 0)
	{
		new_str = xsubstr(old_remaining, 0, end - start + 1);
		ft_lstadd_back(new_lst, ft_lstnew(new_str));
	}
	// substracting tokoen
	ft_lstadd_back(new_lst, ft_lstnew(xstrdup(token_index->token)));

	// substracting string after token
	start = token_index->index + ft_strlen(token_index->token);
	end = ft_strlen(old_remaining) - 1;
	if (start <= end)
		remaining = xsubstr(old_remaining, start, end - start + 1);
	else
		remaining = NULL;
	tkindx_del(token_index);
	return (remaining);
}*/

void	separate_tokens(t_list *cmdln_lst)
{
	(void)cmdln_lst;
	/*t_list	*iterator;
	t_list	*new_lst;
	t_list	*quotes_range;
	char	*str;
	char	*remaining;
	char	*befree;

	iterator = cmdln_lst;
	while (iterator)
	{
		new_lst = NULL;
		str = (char *)iterator->content;
		remaining = xstrdup(str);
		//quotes_range = get_quotes_range(str);
		while (have_token(remaining))
		{
			befree = remaining;
			remaining = separate(&new_lst, str, remaining, quotes_range);
			xfree(befree);
			print_str_lst(new_lst);
		}
		if (is_not_null(remaining))
			ft_lstadd_back(&new_lst, ft_lstnew(remaining));
		iterator = iterator->next;
	}*/
}
