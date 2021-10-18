#ifndef LIBX_H
# define LIBX_H

# include <stdlib.h>
# include <unistd.h>

# define INDEX_NOT_FOUND -1
# define NO_RANGE_TYPE 0
# undef false
# undef true

typedef enum e_bool {
	false,
	true,
}t_bool;

typedef struct s_range
{
	int		from;
	int		to;
	char	type;
}t_range;

typedef struct	s_data
{
	void			*data;
	struct s_data	*next;
}				t_data;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

typedef struct s_replace
{
	t_list			**head;
	t_list			*target;
	t_list			*new_lst;
}t_replace;

// libft
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnstr(const char *h, const char *n, size_t len);
char			*ft_strstr(const char *h, const char *n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_atoi(const char *str);
char			*ft_itoa(long n);
void			ft_putchar_fd(const char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strdup(const char *s1);
char			*ft_dec2hex(size_t decimal);
char			*ft_strtoupper(char *s);
int				is_str_digit(const char *s);
void			ft_putstr(const char *s);
int				count_char(const char *s, char c);
int				length(char **array);
void			free_str_array(char **str_arr);
int				ft_putc(int c);
size_t			ft_max(size_t m1, size_t m2);
t_bool			is_null(void *ptr);
t_bool			is_not_null(void *ptr);
int				address_to_index(const char *s, char *address);

// libx
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
t_data			**xmalloc_head(void);
void			*xmalloc(size_t size);
void			xfree(void *data);
void			alloc_fail(void);
void			finish(void);
void			swap(t_data *this, t_data *other);
char			*xstrdup(const char *s);
char			*xstrjoin(const char *s1, const char *s2);
char			*xstrjoin_arr(const char **arglst, size_t n);
char			*xsubstr(char const *s, unsigned int start, size_t len);
void			*xrealloc(void *ptr, size_t old_size, size_t new_size);
char			**xsplit(char const *s, char c);
void			xfree_str_array(char **str_arr);
char			*splitat(const char *s, int index);

// linkedlist
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del) (void*));
void	ft_lstclear(t_list **lst, void (*del) (void*));
void	ft_lstiter(t_list *lst, void (*f) (void*));
t_list	*ft_lstmap(t_list *lst, void *(*f) (void*));
t_bool	is_empty(t_list *lst);
t_list	*string_array_to_string_list(char **arr);
void	str_del(void *content);
char	**string_list_to_string_array(t_list *lst);
void	deallocate(void);
void	replace_node_intolist(t_replace *replace, void (*del) (void*));
t_bool	is_not_empty(t_list *lst);
t_bool	ft_lsthas_next(t_list *lst);
void	ft_lstrem(t_list **head, t_list *target, void (*del) (void*));
char	*join_string_array_to_string(char **arr);
char	*join_string_list_to_string(t_list *lst);
char	*join_string_list_with_nl(t_list *lst);

// debugging
void	print_list_str(t_list *str_lst);
void	print_array_str(char **str_arr);

#endif
