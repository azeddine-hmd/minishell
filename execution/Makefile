NAME = libexecution.a

CFLAGS = -Wall -Wextra -Werror \
		 -g \

CC = gcc

SRC = execute.c \

OBJ = ${SRC:.c=.o}

MAKE = make -C

all: options $(NAME)

options:
	@echo ${NAME} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(NAME).dSY

re: fclean all

.PHONY: clean fclean re

#CC 		= gcc
#FLAGS	= -fsanitize=address
#AR		= ar -rc
#SRC		= main.c utils_0.c utils_1.c env.c pwd.c export.c unset.c cd.c redirections.c echo.c pipes.c
#PROGRAM = minishell
#NAME	= minishell.a
#MAKE 	= make -C
#all:	$(NAME)

#%.o:	%.c
#	@$(CC) -c $(FLAGS) $<

#$(NAME): $(SRC:.c=.o)
#	@echo "Creating the program."
#	@make -C libft
#	@$(AR) $(NAME) $(SRC:.c=.o)
#	@ranlib $(NAME)
#	@$(CC) $(FLAGS) -o $(PROGRAM) $(NAME) libft.a

#clean:
#	@make clean -C  libft
#	@rm -rf $(SRC:.c=.o) $(NAME)
#fclean: clean
#	@make fclean -C  libft
#	@rm -rf $(PROGRAM)

re:	fclean all
