# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 15:13:20 by ahamdaou          #+#    #+#              #
#    Updated: 2021/04/14 15:39:03 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libparser.a

CFLAGS = -Wall -Wextra -Werror \
		 -g \

CC = gcc

SRC = parse.c \
	  cmds.c \
	  cmdslst.c \
	  parse_debugger.c \

OBJ = ${SRC:.c=.o}

MAKE = make -C

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
