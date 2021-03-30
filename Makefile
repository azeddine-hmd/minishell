NAME = minishell

CFLAGS = -Wall -Wextra -Werror \
		 -g \
		 -fsanitize=address \

CC = gcc

LIBS = libft/libft.a \
	   linkedlist/liblinkedlist.a \
	   parser/libparser.a \

SRC = main.c

OBJ = ${SRC:.c=.o}

MAKE = make -C

all: $(NAME)

$(NAME):
	@$(MAKE) libft
	@$(MAKE) linkedlist
	@$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(NAME)

clean:
	@$(MAKE) libft clean
	@$(MAKE) linkedlist clean
	@rm -rf $(OBJ)

fclean:
	@$(MAKE) libft fclean
	@$(MAKE) linkedlist fclean
	@rm -rf $(NAME) cub3D.dSYM #remove it later

re: fclean all

.PHONY: clean fclean
