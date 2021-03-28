# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 11:25:43 by ahamdaou          #+#    #+#              #
#    Updated: 2021/03/28 11:38:59 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libdlinkedlist.a

CFLAGS = -Wall -Wextra -Werror \
		 -g \
		 -fsanitize=address \

CC = gcc

LIBS = ../libft/libft.a

SRC = dlinkedlist.c \

OBJ = ${SRC:.c=.o}

MAKE = make -C

all: $(NAME)

$(NAME):
	@$(MAKE) ../libft
	@$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(NAME)

clean:
	@$(MAKE) ../libft clean
	@rm -rf $(OBJ)

fclean:
	@$(MAKE) ../libft fclean
	@rm -rf $(NAME) cub3D.dSYM #remove it later

.PHONY: clean fclean
