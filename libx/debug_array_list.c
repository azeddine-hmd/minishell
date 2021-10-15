#include "libx.h"

void	print_list_str(t_list *str_lst)
{
	char	*str;
	int		i;
	char 	*i_str;

	i = 0;
	while (str_lst)
	{
		str = (char*)str_lst->content;
		ft_putstr("str_lst[");
		i_str = ft_itoa(i);
		ft_putstr(i_str);
		free(i_str);
		ft_putstr("] = ");
		ft_putstr(str);
		ft_putstr("\n");
		str_lst = str_lst->next;
		i++;
	}
}

void	print_array_str(char **str_arr)
{
	int		arr_len;
	int		i;
	char	*i_str;

	arr_len = length(str_arr);
	i = 0;
	while (i < arr_len)
	{
		ft_putstr("str_arr[");
		i_str = ft_itoa(i);
		ft_putstr(i_str);
		free(i_str);
		ft_putstr("] = ");
		ft_putstr(str_arr[i]);
		ft_putstr("\n");
		i++;
	}

}
