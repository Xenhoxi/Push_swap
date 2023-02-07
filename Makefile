# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 16:44:58 by ljerinec          #+#    #+#              #
#    Updated: 2023/02/07 13:27:59 by ljerinec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/push_swap.c \
	src/checking.c \
	src/checking_2.c \
	src/stack_gestion.c \
	src/utils.c \
	src/stack_gestion_2.c \
	src/instructions/swap.c \
	src/instructions/push.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): $(OBJECTS)
	make -C inc/libft
	gcc -Wall -Wextra -Werror $(SRC) inc/libft/libft.a -g3

clean:
	rm -f $(OBJECTS) $(BONUS)
	make -C inc/libft clean

fclean: clean
	/bin/rm -f $(NAME)
	rm -f $(OBJECTS)
	make -C inc/libft fclean

re: fclean all