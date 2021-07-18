#include "parser.h"

void	end(t_list **new_lst, const char *str, t_list *quotes_range)
{
	t_range	*content;
	char	*new_str;
	int		last_index;
	int		after_last_quote;
	int		len;

	content = (t_range *)ft_lstlast(quotes_range)->content;
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

void	middle(t_list **new_lst, const char *str, t_list *quotes_range)
{
	t_range	*content;
	t_range	*next_content;
	char	*new_str;
	int		start;
	int		end;

	while (quotes_range->next)
	{
		content = (t_range *)quotes_range->content;
		new_str = xsubstr(str, content->from, get_range_len(content));
		ft_lstadd_back(new_lst, ft_lstnew(new_str));
		next_content = (t_range *)quotes_range->next->content;
		start = content->to + 1;
		end = next_content->from - 1;
		if (end >= start)
		{
			new_str = xsubstr(str, start, end - start + 1);
			ft_lstadd_back(new_lst, ft_lstnew(new_str));
		}
		quotes_range = quotes_range->next;
	}
}

void	begin(t_list **new_lst, const char *str, t_list *quotes_range)
{
	t_range	*content;
	char	*new_str;
	int		start;
	int		end;
	int		len;

	content = (t_range *)quotes_range->content;
	start = 0;
	end = content->from - 1;
	len = end - start + 1;
	if (end > 0)
	{
		new_str = xsubstr(str, start, len);
		ft_lstadd_back(new_lst, ft_lstnew(new_str));
	}
}

static void	separate(t_list **new_lst, const char *str, t_list *quotes_range)
{
	*new_lst = NULL;
	begin(new_lst, str, quotes_range);
	middle(new_lst, str, quotes_range);
	end(new_lst, str, quotes_range);
}

void	separate_quotes(t_list *cmdln_lst)
{
	t_list		*iterator;
	t_list		*new_lst;
	t_list		*quotes_range;
	t_replace	replace;
	char		*str;

	iterator = cmdln_lst;
	while (iterator)
	{
		str = (char *)iterator->content;
		quotes_range = get_quotes_range(str);
		if (is_not_empty(quotes_range))
		{
			separate(&new_lst, str, quotes_range);
			replace.head = &cmdln_lst;
			replace.target = iterator;
			replace.new_lst = new_lst;
			replace_node_intolist(&replace, str_del);
		}
		iterator = iterator->next;
	}
}
