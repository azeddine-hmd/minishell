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
	@$(MAKE) parser
	@$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(NAME)

clean:
	@$(MAKE) libft clean
	@$(MAKE) linkedlist clean
	@$(MAKE) parser clean
	@rm -rf $(OBJ)

fclean:
	@$(MAKE) libft fclean
	@$(MAKE) linkedlist fclean
	@$(MAKE) parser clean fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean
