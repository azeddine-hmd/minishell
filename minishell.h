#ifndef MINISHELL_H
# define MINISHELL_H

# include <termcap.h>
# include <curses.h>
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include "libft/libft.h"
# include "linkedlist/linkedlist.h"
# include "parser/parser.h"
# include "errors.h"

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
 ** keys
 */

# define K_BS 127
# define K_CR 10

/*
 ** others
 */

# define DEBUG TRUE
# define MS_PROMPT_COLOR COLORS_BLUE
# define MS_PROMPT "minishell > "
# define MS_BUFFER_SIZE 2048


typedef struct	s_buf
{
	char	*buf;
	size_t	size;
	size_t	pos;
}				t_buf;

/*
 ** terminal capability
 */

typedef struct	s_cap
{
	char	*le;
	char	*dc;
}				t_cap;

// debugging
FILE *ms_log;
FILE *ms_buflog;


void		ms_bufinit(t_buf **a_buf);
void		ms_bufdel(t_buf *buf, t_cap *cap);
void		ms_bufadd(t_buf *buf, char out);
void		ms_bufrst(t_buf *buf);

/*
 ** termcap functions
 */

void		ms_prompt(void);
void		ms_scrclr(void);
void		ms_chrdel(t_cap *cap);
void		ms_setup(t_cap **cap, t_buf **a_buf);


#endif
