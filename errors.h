#ifndef ERRORS_H
# define ERRORS_H
# include <stdio.h>
# include <stdlib.h>

/*
** errors
*/

# define ERR_TERMTYPE "Specify a terminal type with `setenv TERM <yourtype>.`"
# define ERR_TERMACCESS "Could not access the termcap data base."
# define ERR_TERMNOTDEFINED "Terminal type `%s` is not defined."

/*
** colors
*/

# define COLOR_DEFAULT "\033[0;31m"
# define COLOR_BLACK "\033[0;30m"
# define COLOR_RED "\033[031m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_YELLOW "\033[0;33m"
# define COLOR_BLUE "\033[0;34m"
# define COLOR_PURPLE "\033[0;35m"
# define COLOR_CYAN "\033[0;36m"
# define COLOR_WHITE "\033[0;36m"

/*
** functions prototypes
*/

void	err(const char *error);
void	ferr(const char *err_format, const char *arg);

#endif
