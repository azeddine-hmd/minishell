#ifndef LIBX_H
# define LIBX_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_data
{
	void			*data;
	struct s_data	*next;
}				t_data;

t_data			*lst_last(t_data *node);
void			lst_add_front(t_data **head, t_data *node);
void			lst_add_back(t_data **head, t_data *node);
void			free_node(t_data *node);
void			lst_clear(t_data *head);
t_data			*new_node(void *data);
void			add(t_data **head, void *data);
void			add_double_pointer(char **ptr);
void			xfree_double_pointer(char **ptr);
int				lst_size(t_data *head);
t_data			**get_head_node(void);
void			*xmalloc(size_t size);
void			xfree(void *data);
void			error(void);
void			error_message(const char *message);
void			error_line(int ln, const char *message);
void			error_file(const char *file_name, const char *message);
void			finish(void);
void			swap(t_data *this, t_data *other);
char			*xstrdup(const char *s);
char			*xstrjoin(const char *s1, const char *s2);
char			*xstrjoin_arr(const char **arglst, size_t n);
char			*xsubstr(char const *s, unsigned int start, size_t len);
void			*xrealloc(void *ptr, size_t old_size, size_t new_size);

#endif
