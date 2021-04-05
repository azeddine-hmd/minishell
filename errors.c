#include "errors.h"

void	err(const char *error)
{
	printf(COLOR_RED);
	printf("Error: ");
	printf("%s\n", error);
	printf(COLOR_DEFAULT);
	exit(1);
}

void	ferr(const char *err_format, const char *arg)
{
	printf(COLOR_RED);
	printf("Error: ");
	printf(err_format, arg);
	printf(COLOR_DEFAULT);
	exit(1);
}
