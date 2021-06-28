#include "errors.h"

void	print_syntax_error(const char *error)
{
	printf(COLORS_RED);
	printf("minishell: ");
	printf("%s\n", error);
	printf(COLORS_DEFAULT);
}

void	err(const char *error)
{
	printf(COLORS_RED);
	printf("Error: ");
	printf("%s\n", error);
	printf(COLORS_DEFAULT);
	lst_clear(*get_head_node());
	exit(1);
}

void	ferr(const char *err_format, const char *arg)
{
	printf(COLORS_RED);
	printf("Error: ");
	printf(err_format, arg);
	printf(COLORS_DEFAULT);
	lst_clear(*get_head_node());
	exit(1);
}
