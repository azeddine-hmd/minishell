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

# define MS_PROMPT_COLOR COLORS_BLUE
# define MS_PROMPT "minishell > "
# define MS_BUFFER_SIZE 2048


typedef struct	s_buf
{
	char	*buf;
	size_t	size;
	size_t	pos;
}				t_buf;

void		ms_enable_raw_mode(void);
void		ms_init_terminal_data(void);
void		ms_prompt(void);
void		ms_bufinit(t_buf **a_input);
int			ms_bufdel(t_buf *input);
void		ms_bufadd(t_buf *input, char c);
void		ms_curlef(void);
void		ms_curdel(void);
void		ms_scrclr(void);

#endif
