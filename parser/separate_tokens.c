/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:24:26 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 10:24:26 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	end(t_list **new_lst, const char *str, t_list *tokens_range)
{
	t_range	*content;
	char	*new_str;
	int		last_index;
	int		after_last_quote;
	int		len;

	content = (t_range *)ft_lstlast(tokens_range)->content;
	new_str = xsubstr(str, content->from, get_range_len(content));
	lstpush(new_lst, new_str);
	last_index = ft_strlen(str) - 1;
	if (content->to < last_index)
	{
		after_last_quote = content->to + 1;
		len = last_index - after_last_quote + 1;
		new_str = xsubstr(str, after_last_quote, len);
		lstpush(new_lst, new_str);
	}
}

static void	middle(t_list **new_lst, const char *str, t_list *tokens_range)
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
		lstpush(new_lst, new_str);
		next_content = (t_range *)tokens_range->next->content;
		start = content->to + 1;
		end = next_content->from - 1;
		if (end >= start)
		{
			new_str = xsubstr(str, start, end - start + 1);
			lstpush(new_lst, new_str);
		}
		tokens_range = tokens_range->next;
	}
}

static void	begin(t_list **new_lst, const char *str, t_list *tokens_range)
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
	if (end >= start && len >= 1)
	{
		new_str = xsubstr(str, start, len);
		lstpush(new_lst, new_str);
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
	t_tkinfo	tkinfo;
	t_replace	replace;
	char		*str;

	tkinfo.iterator = *cmdln_lst;
	while (tkinfo.iterator)
	{
		str = (char *)tkinfo.iterator->content;
		if (have_token(str))
		{
			tkinfo.tokens_range = get_tokens_range(str);
			if (not_null(tkinfo.tokens_range))
			{
				separate(&(tkinfo.new_lst), str, tkinfo.tokens_range);
				lstclear(&(tkinfo.tokens_range), range_del);
				replace.head = cmdln_lst;
				replace.target = tkinfo.iterator;
				replace.new_lst = tkinfo.new_lst;
				tkinfo.iterator = tkinfo.iterator->next;
				replace_node_intolist(&replace, str_del);
				continue ;
			}
		}
		tkinfo.iterator = tkinfo.iterator->next;
	}
}
