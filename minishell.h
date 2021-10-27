#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <termcap.h>
# include <curses.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <signal.h>
# include "libx/libx.h"
# include "parser/parser.h"
# include "execution/execution.h"
# include "errors.h"

# define MS_PROMPT "minishell$ "
# define MS_PROMPT_COLOR COLORS_CYAN_BOLD
# define MS_PROMPT_ERROR_COLOR COLORS_RED_BOLD
# define MS_HEREDOC_PROMPT "> "
# define MS_HEREDOC_COLOR COLORS_CYAN
# define MS_BUFFER_SIZE 2048

/*
 ** keys
 */

# define K_A 65
# define K_B 66
# define K_C 67
# define K_D 68
# define K_BS 127
# define K_ENTER 10
# define K_ESC 27
# define K_OSB 91
# define K_CTRL_D 4
# define K_CTRL_L 12
# define K_CTRL_I 9
# define K_CTRL_H 8
# define K_CTRL_K 11
# define K_UP_ARROW K_ESC, K_OSB, K_A
# define K_DOWN_ARROW K_ESC, K_OSB, K_B
# define K_RIGHT_ARROW K_ESC, K_OSB, K_C
# define K_LEFT_ARROW K_ESC, K_OSB, K_D

// debugging
# define DEBUG_LOG_PATH "/tmp/log"
# define DEBUG_BUFLOG_PATH "/tmp/buflog"
# define DEBUG_SIGNAL_PATH "/tmp/signal_log"
FILE *ms_log;
FILE *ms_buflog;
FILE *ms_signallog;

typedef struct s_buf
{
	char	*str;
	size_t	size;
	size_t	pos;
	size_t	last;
}				t_buf;

// terminal capability
typedef struct s_cap
{
	char	*le;
	char	*dc;
	char	*nd;
	char	*ip;
}				t_cap;

typedef struct s_hist
{
	char			*cmdln_str;
	int				ret;
	struct s_hist	*next;
	struct s_hist	*previous;
}t_hist;

typedef struct s_termarg
{
	t_hist	*head;
	t_hist	*cur;
	t_buf		*buf;
	t_cap		*cap;
	char		input;
	int			pos;
}t_termarg;

typedef struct s_sign
{
	t_termarg	*targ;
	t_bool		child_running;
}t_sign;

// debugging
void		print_all_history(t_hist *history);
void		print_all_signal(void);

// general
t_sign		g_sign;
void		usage(void);
void		signal_interceptor(int sig);

// buffer
void		ms_bufinit(t_buf **a_buf);
void		ms_bufdel(t_buf *buf);
void		ms_bufadd(t_buf *buf, char out);
void		ms_bufrst(t_buf *buf);
void		ms_bufrpc(t_buf *buf, const char *s);

// termcap
void		ms_setup(t_cap **cap, t_buf **a_buf);
void		ms_prompt(t_hist *hist);
void		ms_chrdel(t_cap *cap);
void		ms_lndel(t_cap *cap, size_t n);

// history
t_bool		has_previous(t_hist *history);
t_hist		*get_last_history(t_hist *head);
void		add_history(t_hist **head, t_hist *history);
void		delete_history(t_hist **head, t_hist *history);

// keys events
t_bool		backspace_triggered(t_termarg *targ);
t_bool		enter_triggered(t_termarg *targ, char ***env);
t_bool		up_arrow_triggered(t_termarg *targ);
t_bool		down_arrow_triggered(t_termarg *targ);
t_bool		ctrl_d_triggered(t_termarg *targ);
t_bool		ctrl_l_triggered(t_termarg *targ);
t_bool		right_arrow_triggered(t_termarg *targ);
t_bool		left_arrow_triggered(t_termarg *targ);

// heredoc
t_list		*get_heredoc_lst(t_list	*cmds);
void		heredoc_entry(t_termarg *targ, t_list *heredoc_lst, char **env);
char		*heredoc_loop(t_termarg *targ, const char *delimiter, char **env);

#endif
