#ifndef LINKEDLIST_H
# define LINKEDLIST_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libx/libx.h"

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

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del) (void*));
void	ft_lstclear(t_list **lst, void (*del) (void*));
void	ft_lstiter(t_list *lst, void (*f) (void*));
t_list	*ft_lstmap(t_list *lst, void *(*f) (void*));
int		is_empty(t_list *lst);
t_list	*string_array_to_string_list(char **arr);
void	str_del(void *content);
char	**string_list_to_string_array(t_list *lst);
void	clean(void);
void	replace_node_intolist(t_replace *replace, void (*del) (void*));
int		is_not_empty(t_list *lst);

#endif
