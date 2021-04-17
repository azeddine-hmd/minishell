NAME = minishell

CFLAGS =  \
		 -ltermcap \
		 -g \
		 -fsanitize=address \

CC = gcc

LIBS = libft/libft.a \
	   linkedlist/liblinkedlist.a \
	   parser/libparser.a \

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
	@$(MAKE) parser fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean
