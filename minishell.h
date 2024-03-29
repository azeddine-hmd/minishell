/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:09:03 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 21:09:03 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <termcap.h>
# include <curses.h>
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
	struct s_hist	*next;
	struct s_hist	*previous;
}t_hist;

typedef struct s_termarg
{
	t_hist	*head;
	t_hist	*cur;
	t_buf	*buf;
	t_cap	*cap;
	char	input;
	int		pos;
}t_termarg;

typedef struct s_sign
{
	t_termarg	*targ;
	char		***env;
	t_bool		child_running;
	t_bool		stop_heredoc;
	t_bool		heredoc_running;
	t_bool		is_pipe;
}t_sign;

typedef struct s_hd
{
	t_list	*lines_lst;
	char	*fcontent;
	char	*saved_bufstr;
	t_bool	expand_enabled;
	char	*stripped_delimiter;
}t_hd;

typedef struct s_hdentry
{
	t_list	*fcontent_lst;
	t_list	*hd_iterator;
	t_list	*heredoc_lst;
	t_token	*hd_token;
	char	*fcontent;
	char	**env;
	int		file_suffix;
}t_hdentry;

typedef struct s_painfo
{
	t_list	*cmd_lst;
	char	*syntax_error;
	t_list	*heredoc_lst;
}t_painfo;

// types
typedef struct termios	t_termios;

// globals
t_sign					g_sign;

// utils
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
void		ms_prompt(int ret);
void		ms_chrdel(t_cap *cap);
void		ms_lndel(t_cap *cap, size_t n);

// history
t_bool		has_previous(t_hist *history);
t_hist		*get_last_history(t_hist *head);
void		add_history(t_hist **head, t_hist *history);

// keys events
t_bool		backspace_triggered(t_termarg *targ);
t_bool		enter_triggered(t_termarg *targ, char ***env);
t_bool		up_arrow_triggered(t_termarg *targ);
t_bool		down_arrow_triggered(t_termarg *targ);
t_bool		ctrl_d_triggered(t_termarg *targ);
t_bool		ctrl_l_triggered(t_termarg *targ, char **env);
t_bool		right_arrow_triggered(t_termarg *targ);
t_bool		left_arrow_triggered(t_termarg *targ);

// heredoc
t_list		*get_heredoc_lst(t_list	*cmds);
void		heredoc_entry(t_termarg *targ, t_list *heredoc_lst, char **env);
char		*heredoc_loop(t_termarg *targ, const char *delimiter, char **env);
t_bool		hd_ctrl_d_triggered(t_termarg *targ, char **env, t_hd *heredoc);
char		*format_heredoc_err(const char *delimiter);
void		hd_prompt(void);
t_bool		hd_enter_triggered(t_termarg *targ, char **env, t_hd *heredoc);

#endif
