#include "linkedlist.h"

static void	free_str_array_until_index_reached(char **str_arr, int last_index)
{
	int i;
	int	arr_len;

	i = 0;
	while (i < last_index)
		free(str_arr[i]);
	i = 0;
	arr_len = length(str_arr);
	while (i < arr_len)
		free(str_arr + i);
}

char	**string_list_to_string_array(t_list *lst)
{
	char	**str_arr;
	int		len;
	int		i;

	len = ft_lstsize(lst);
	str_arr = (char **)malloc(sizeof(char *) * (len + 1));
	str_arr[len] = NULL;
	i = 0;
	while (lst)
	{
		char *element = ft_strdup((char *)lst->content);
		if (is_null(element))
		{
			free_str_array_until_index_reached(str_arr, i);
			return (NULL);
		}
		str_arr[i] = element;
		lst = lst->next;
		i++;
	}
	return (str_arr);
}
