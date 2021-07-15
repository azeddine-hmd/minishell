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

t_list	*get_quotes_range(const char *s)
{
	t_list	*head;
	t_range	*range;
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
			range = get_range(i, pair_index, s[i]);
			ft_lstadd_back(&head, ft_lstnew(range));
			i = pair_index + 1;
		}
		else
			i++;
	}
	return (head);
}
