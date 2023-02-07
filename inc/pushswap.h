/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:02 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/07 16:43:55 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

// push_swap.c
void	set_stack_1(int argc, char **argv, t_list **stack);

// checking.c 
int		checking(int argc, char **argv);
int		check_argv(char	**input_list, int argc);
int		only_digit(char	**input_list, int argc);
int		only_int(char **input_list);
int		identical_numbers(long long *int_array, int input_len);

//checking_2.c
void	error(void);

// stack_gestion.c
void	fill_stack_split(int argc, char **argv, t_list **stack);
void	fill_stack_argv(int argc, char **argv, t_list **stack);
void	push_back(t_list **stack_, int new_value);
void	print_list(t_list *stack);
void	print_reverse_stack(t_list *stack);

// stack_gestion_2.c
int		stacklen(t_list *stack);
t_list	*stack_init(t_list *stack);
void	stackfirst(t_list **stack_);
void	stacklast(t_list **stack_);
void	stacknew(t_list **stack, int new_value);


// utils.c
int		array_len(char **argv);

// instructions
void	sa(t_list *stack);
void	sb(t_list *stack);
void	ss(t_list *stack_1, t_list *stack_2);
void	pa(t_list **stack_1, t_list **stack_2);
void	pb(t_list **stack_1, t_list **stack_2);
void	ra(t_list **stack_1);
void	rb(t_list **stack_2);
void	rr(t_list **stack_1, t_list **stack_2);
void	rra(t_list **stack_1);
void	rrb(t_list **stack_2);
void	rrr(t_list **stack_1, t_list **stack_2);

#endif