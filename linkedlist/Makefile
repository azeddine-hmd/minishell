NAME = liblinkedlist.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra \
		 -g \

SRC = linkedlist.c \
	  linkedlist_utils.c \
	  allocation.c \
	  error.c \
	  swap.c \
	  utils.c \
	  xsubstr.c \
	  xrealloc.c \

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
