#include "libx.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Allocation failure\n", 2);
	lst_clear(*get_head_node());
	exit(1);
}

void	error_message(const char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	lst_clear(*get_head_node());
	exit(1);
}

void	error_line(int line, const char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("line[", 2);
	ft_putstr_fd(ft_itoa(line), 2);
	ft_putstr_fd("]: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	lst_clear(*get_head_node());
	exit(1);
}

void	error_file(const char *file_name, const char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	lst_clear(*get_head_node());
	exit(1);
}
