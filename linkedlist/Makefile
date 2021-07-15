NAME = liblinkedlist.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra \
		 -g \

SRC = setters.c \
	  getters.c \
	  del.c \
	  iterator.c \
	  is_empty.c \
	  string_array_to_string_list.c \
	  string_list_to_string_array.c \
	  finish.c \
	  replace_node_intolist.c \

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):
	@ $(CC) $(CFLAGS) -c $(SRC)
	@ ar rc $(NAME) $(OBJ)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean re
