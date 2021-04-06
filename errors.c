#include "errors.h"

void	err(const char *error)
{
	printf(COLORS_RED);
	printf("Error: ");
	printf("%s\n", error);
	printf(COLORS_DEFAULT);
	exit(1);
}

void	ferr(const char *err_format, const char *arg)
{
	printf(COLORS_RED);
	printf("Error: ");
	printf(err_format, arg);
	printf(COLORS_DEFAULT);
	exit(1);
}
