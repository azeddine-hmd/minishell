#ifndef ERRORS_H
# define ERRORS_H
# include <stdlib.h>
# include "libx/libx.h"
# include <stdio.h>

/*
** terminal errors
*/

# define ERR_TERMTYPE "Specify a terminal type with `setenv TERM <yourtype>.`"
# define ERR_TERMACCESS "Could not access the termcap data base."
# define ERR_TERMNOTDEFINED "Terminal type `%s` is not defined."

/*
** colors
*/

# define COLORS_DEFAULT "\033[0;0m"
# define COLORS_BLACK "\033[0;30m"
# define COLORS_RED "\033[031m"
# define COLORS_GREEN "\033[0;32m"
# define COLORS_YELLOW "\033[0;33m"
# define COLORS_BLUE "\033[0;34m"
# define COLORS_PURPLE "\033[0;35m"
# define COLORS_CYAN "\033[0;36m"
# define COLORS_WHITE "\033[0;36m"

/*
** syntax errors
*/
# define ERR_PIPE "syntax error near unexpected token '|'"


void	err(const char *error);
void	ferr(const char *err_format, const char *arg);
void	print_syntax_error(const char *error);

#endif
