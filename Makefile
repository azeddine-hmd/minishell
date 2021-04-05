NAME = minishell

CFLAGS = -Wall -Wextra -Werror \
		 -ltermcap \
		 -g \
		 -fsanitize=address \

CC = gcc

LIBS = libft/libft.a \
	   linkedlist/liblinkedlist.a \
	   parser/libparser.a \
	   get_next_line/libget_next_line.a \

SRC = minishell.c \
	  errors.c \

OBJ = ${SRC:.c=.o}

MAKE = make --no-print-directory -C

all: $(NAME)

$(NAME):
	@$(MAKE) libft
	@$(MAKE) linkedlist
	@$(MAKE) parser
	@$(MAKE) get_next_line
	@$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(NAME)

clean:
	@$(MAKE) libft clean
	@$(MAKE) linkedlist clean
	@$(MAKE) parser clean
	@$(MAKE) get_next_line clean
	@rm -rf $(OBJ)

fclean:
	@$(MAKE) libft fclean
	@$(MAKE) linkedlist fclean
	@$(MAKE) parser fclean
	@$(MAKE) get_next_line fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean
