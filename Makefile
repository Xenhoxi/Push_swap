# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 16:44:58 by ljerinec          #+#    #+#              #
#    Updated: 2023/03/11 02:03:26 by ljerinec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 	src/sorting/push_swap.c \
		src/parsing/parsing.c \
		src/parsing/parsing_2.c \
		src/linked_list/stack_gestion.c \
		src/linked_list/stack_gestion_2.c \
		src/instructions/swap.c \
		src/instructions/push.c \
		src/instructions/reverse_rotate.c \
		src/instructions/rotate.c \
		src/sorting/sorting_utils.c \
		src/sorting/sorting_3.c \
		src/sorting/sorting_5.c \
		src/sorting/sorting_big.c \

SRCSBONUS = src/checker/checker.c \
		inc/get_next_line/get_next_line.c \
		inc/get_next_line/get_next_line_utils.c \
		src/parsing/parsing.c \
		src/parsing/parsing_2.c \
		src/linked_list/stack_gestion.c \
		src/linked_list/stack_gestion_2.c \
		src/instructions/swap.c \
		src/instructions/push.c \
		src/instructions/reverse_rotate.c \
		src/instructions/rotate.c \
		src/sorting/sorting_utils.c \
		src/sorting/sorting_3.c \
		src/sorting/sorting_5.c \
		src/sorting/sorting_big.c \

PRINT_NAME		= push-swap
PRINT_PREFIX	= \033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

LIBFT_DIR = inc/libft/libft.a
OBJECTS = $(SRCS:%.c=%.o)
OBJECTSBONUS = $(SRCSBONUS:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

libft:
	@make -C inc/libft

$(NAME): libft $(OBJECTS) $(SRCS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Compiling \033[0m\n"
	@$(CC) -o $(NAME) $(OBJECTS) $(LIBFT_DIR)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Done \033[0m\n"

bonus: libft $(OBJECTSBONUS) $(SRCSBONUS)
	@$(CC) -o checker $(OBJECTSBONUS) $(LIBFT_DIR)

clean:
	@make -C inc/libft clean
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
	@rm -f $(OBJECTS) $(OBJECTSBONUS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Done \033[0m\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f checker
	@make -C inc/libft fclean

re: fclean all

.PHONY: all clean fclean re