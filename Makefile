NAME = minishell

CFLAGS = -Wall -Wextra -Werror \
		 -g \
		 -fsanitize=address \

CC = gcc

LIBS = libft/libft.a \
	   linkedlist/liblinkedlist.a \
	   stack/libstack.a \
	   parser/libparser.a \

SRC = minishell.c \

OBJ = ${SRC:.c=.o}

MAKE = make --no-print-directory -C

all: $(NAME)

$(NAME):
	@$(MAKE) libft
	@$(MAKE) linkedlist
	@$(MAKE) parser
	@$(MAKE) stack
	@$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(NAME)

clean:
	@$(MAKE) libft clean
	@$(MAKE) linkedlist clean
	@$(MAKE) parser clean
	@$(MAKE) stack clean
	@rm -rf $(OBJ)

fclean:
	@$(MAKE) libft fclean
	@$(MAKE) linkedlist fclean
	@$(MAKE) parser fclean
	@$(MAKE) stack fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean
