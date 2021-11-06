#include "errors.h"

void	set_raw_mode(t_bool enable)
{
	struct termios tsettings;

	tcgetattr(STDIN_FILENO, &tsettings);
	if (enable)
	{
		tsettings.c_lflag &= ~(ECHO | ICANON);
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &tsettings);
	}
	else
	{
		tsettings.c_lflag |= ECHO;
		tsettings.c_lflag |= ICANON;
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &tsettings);
	}
}

void	shell_exit(int ret)
{
	set_raw_mode(false);
	deallocate();
	exit(ret);
}

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
	shell_exit(1);
}

void	ferr(const char *err_format, const char *arg)
{
	printf(COLORS_RED);
	printf("Error: ");
	printf(err_format, arg);
	printf(COLORS_DEFAULT);
	shell_exit(1);
}
