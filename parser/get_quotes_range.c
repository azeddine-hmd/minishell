#include "parser.h"

static int	quote_address_to_index(const char *s, char *quote_address)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (&(s[i]) == quote_address)
			return (i);
		i++;
	}
	return (QUOTE_ADDRESS_NOT_FOUND);
}

static int	get_quote_pair_index(const char *s, char quote, int start_index)
{
	char	*quote_address;
	int		index;

	quote_address = ft_strchr(s + start_index, quote);
	if (is_null(quote_address))
		return (PAIR_NOT_FOUND);
	index = quote_address_to_index(s, quote_address);
	return (index);
}

static void	create_and_add_range(t_list **head, int from, int to, char type)
{
	t_list	*new;
	t_range	*range;

	range = get_range(from, to, type);
	if (is_null(range))
	{
		ft_lstclear(head, range_del);
		error();
	}
	new = ft_lstnew(range);
	if (is_null(new))
	{
		ft_lstclear(head, range_del);
		error();
	}
	ft_lstadd_back(head, new);
}

t_list	*get_quotes_range(const char *s)
{
	t_list	*head;
	int		pair_index;
	int		i;

	head = NULL;
	i = 0;
	while (s[i])
	{
		if (ft_strchr(QUOTES, s[i]))
		{
			pair_index = get_quote_pair_index(s, s[i], i + 1);
			if (pair_index == PAIR_NOT_FOUND)
				break ;
			create_and_add_range(&head, i, pair_index, s[i]);
			i = pair_index + 1;
		}
		else
			i++;
	}
	return (head);
}
