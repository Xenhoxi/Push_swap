/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:02 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/06 02:09:47 by ljerinec         ###   ########.fr       */
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

// Stuct pour mes 2 stacks claquer au sol ce code de merde
typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*first;
	struct s_stack	*last;
}					t_stack;

// push_swap.c
void	set_stack_1(int argc, char **argv, t_stack **stack);

// checking.c && checking_2.c
int		checking(int argc, char **argv);
int		check_argv(char	**input_list, int argc);
int		only_digit(char	**input_list, int argc);
int		only_int(char **input_list);
int		identical_numbers(long long *int_array, int input_len);
void	error(void);

// stack_gestion.c
void	fill_stack_split(int argc, char **argv, t_stack **stack);
void	fill_stack_argv(int argc, char **argv, t_stack **stack);
void	push_back(t_stack **stack_, int new_value);
void	print_stack(t_stack *stack);
void	print_reverse_stack(t_stack *stack);

// stack_gestion_2.c
int		stacklen(t_stack *stack);
t_stack	*stack_init(t_stack *stack);
void	stackfirst(t_stack **stack_);
void	stacklast(t_stack **stack_);
void	stacknew(t_stack **stack, int new_value);

// utils.c
int		array_len(char **argv);

// instructions
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_1, t_stack *stack_2);

#endif