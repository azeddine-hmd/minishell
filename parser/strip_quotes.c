/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:53:42 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 10:53:42 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*strip_quotes(const char *s)
{
	t_list	*quotes_lst;
	t_range	*quotes_range;
	char	*stripped;
	char	*tmp;
	int		removed;

	if (!s)
		return (NULL);
	quotes_lst = get_quotes_range(s);
	stripped = xstrdup(s);
	removed = 0;
	while (quotes_lst)
	{
		quotes_range = (t_range *)quotes_lst->content;
		tmp = stripped;
		stripped = splitat(stripped, quotes_range->from - removed);
		xfree(tmp);
		removed++;
		tmp = stripped;
		stripped = splitat(stripped, quotes_range->to - removed);
		xfree(tmp);
		removed++;
		quotes_lst = quotes_lst->next;
	}
	return (stripped);
}
