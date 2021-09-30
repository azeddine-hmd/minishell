#include "errors.h"

void	shell_err(const char *error)
{
	printf(COLORS_RED);
	printf(ERR_SHELL_NAME);
	printf("%s\n", error);
	printf(COLORS_DEFAULT);
}

void	err(const char *error)
{
	printf(COLORS_RED);
	printf("Error: ");
	printf("%s\n", error);
	printf(COLORS_DEFAULT);
	deallocate();
	exit(1);
}

void	ferr(const char *err_format, const char *arg)
{
	printf(COLORS_RED);
	printf("Error: ");
	printf(err_format, arg);
	printf(COLORS_DEFAULT);
	deallocate();
	exit(1);
}
