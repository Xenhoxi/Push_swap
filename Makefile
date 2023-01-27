# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 16:44:58 by ljerinec          #+#    #+#              #
#    Updated: 2023/01/27 14:07:08 by ljerinec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/push_swap.c \
	src/checking.c \
	src/checking_2.c \
	src/stack_gestion.c \
	src/utils.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): $(OBJECTS)
	make -C inc/libft
	gcc -Wall -Wextra -Werror $(SRC) inc/libft/libft.a -g3

clean:
	rm -f $(OBJECTS) $(BONUS)

fclean: clean
	/bin/rm -f $(NAME)
	rm -f $(OBJECTS)

re: fclean all