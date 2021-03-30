NAME = libparser.a

CFLAGS = -Wall -Wextra -Werror \
		 -g \
		 -fsanitize=address \

CC = gcc

LIBS = ../libft/libft.a \
	   ../linkedlist/liblinkedlist.a \

SRC = parse.c \
	  parse_debugger.c \

OBJ = ${SRC:.c=.o}

MAKE = make -C

all: $(NAME)

$(NAME):
	@ $(CC) $(CFLAGS) $(LIBS) -c $(SRC)
	@ ar rc $(NAME) $(OBJ)

clean:
	@$(MAKE) ../libft clean
	@$(MAKE) ../linkedlist clean
	@rm -rf $(OBJ)

fclean:
	@$(MAKE) ../libft fclean
	@$(MAKE) ../linkedlist fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean
