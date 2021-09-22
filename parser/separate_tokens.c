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

/*void	separate_tokens(t_list *cmdln_lst)
{
	t_list	*iterator;
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
	}
}*/


void	end(t_list **new_lst, const char *str, t_list *tokens_range)
{
	t_range	*content;
	char	*new_str;
	int		last_index;
	int		after_last_quote;
	int		len;

	content = (t_range *)ft_lstlast(tokens_range)->content;
	new_str = xsubstr(str, content->from, get_range_len(content));
	ft_lstadd_back(new_lst, ft_lstnew(new_str));
	last_index = ft_strlen(str) - 1;
	if (content->to < last_index)
	{
		after_last_quote = content->to + 1;
		len = last_index - after_last_quote + 1;
		new_str = xsubstr(str, after_last_quote, len);
		ft_lstadd_back(new_lst, ft_lstnew(new_str));
	}
}

void	middle(t_list **new_lst, const char *str, t_list *tokens_range)
{
	t_range	*content;
	t_range	*next_content;
	char	*new_str;
	int		start;
	int		end;

	while (tokens_range->next)
	{
		content = (t_range *)tokens_range->content;
		new_str = xsubstr(str, content->from, get_range_len(content));
		ft_lstadd_back(new_lst, ft_lstnew(new_str));
		next_content = (t_range *)tokens_range->next->content;
		start = content->to + 1;
		end = next_content->from - 1;
		if (end >= start)
		{
			new_str = xsubstr(str, start, end - start + 1);
			ft_lstadd_back(new_lst, ft_lstnew(new_str));
		}
		tokens_range = tokens_range->next;
	}
}

void	begin(t_list **new_lst, const char *str, t_list *tokens_range)
{
	t_range	*content;
	char	*new_str;
	int		start;
	int		end;
	int		len;

	content = (t_range *)tokens_range->content;
	start = 0;
	end = content->from - 1;
	len = end - start + 1;
	if (end > 0)
	{
		new_str = xsubstr(str, start, len);
		ft_lstadd_back(new_lst, ft_lstnew(new_str));
	}
}

static void	separate(t_list **new_lst, const char *str, t_list *tokens_range)
{
	*new_lst = NULL;
	begin(new_lst, str, tokens_range);
	middle(new_lst, str, tokens_range);
	end(new_lst, str, tokens_range);
}

void	separate_tokens(t_list **cmdln_lst)
{
	t_list		*iterator;
	t_list		*new_lst;
	t_list		*tokens_range;
	t_replace	replace;
	char		*str;

	iterator = *cmdln_lst;
	while (iterator)
	{
		str = (char *)iterator->content;
		if (is_not_empty(tokens_range) && have_token(str))
		{
			tokens_range = get_tokens_range(str);
			separate(&new_lst, str, tokens_range);
			ft_lstclear(&tokens_range, range_del);
			replace.head = cmdln_lst;
			replace.target = iterator;
			replace.new_lst = new_lst;
			replace_node_intolist(&replace, str_del);
		}
		iterator = iterator->next;
	}
}
