NAME = minishell

CFLAGS = -Wall -Werror -Wextra \
		 -ltermcap \
		 -g \
		 -fsanitize=address \

CC = gcc

LIBS = libft/libft.a \
	   libx/libx.a \
	   linkedlist/liblinkedlist.a \
	   parser/libparser.a \
	   execution/libexecution.a \

SRC = minishell.c \
	  errors.c \
	  terminal.c \
	  cursor.c \
	  buffer.c \

OBJ = ${SRC:.c=.o}

MAKE = make --no-print-directory -C

all: $(NAME)

$(NAME):
	@$(MAKE) libft
	@$(MAKE) libx
	@$(MAKE) linkedlist
	@$(MAKE) parser
	@$(MAKE) execution
	@$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(NAME)

clean:
	@$(MAKE) libft clean
	@$(MAKE) libx clean
	@$(MAKE) linkedlist clean
	@$(MAKE) parser clean
	@$(MAKE) execution clean
	@rm -rf $(OBJ)

fclean:
	@$(MAKE) libft fclean
	@$(MAKE) libx fclean
	@$(MAKE) linkedlist fclean
	@$(MAKE) parser fclean
	@$(MAKE) execution fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re clean # delete fclean at the end
