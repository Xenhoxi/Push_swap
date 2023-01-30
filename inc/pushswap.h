/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:02 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/30 14:35:42 by ljerinec         ###   ########.fr       */
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
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*first;
	struct s_stack	*last;
}					t_stack;

// checking.c && checking_2.c
int		checking(int argc, char **argv);
int		check_argv(char	**input_list, int argc);
int		only_digit(char	**input_list, int argc);
int		only_int(char **input_list);
int		identical_numbers(long long *int_array, int input_len);
void	error(void);

// stack_gestion.c
t_stack	*fill_stack_split(int argc, char **argv);
t_stack	*fill_stack_argv(int argc, char **argv);
void	push_back(t_stack *stack, int new_value);
void	print_stack(t_stack *stack);
void	print_reverse_stack(t_stack *stack);

// stack_gestion_2.c
int		stacklen(t_stack *stack);
t_stack	*stack_init(t_stack *stack);

// utils.c
int		array_len(char **argv);

// instructions
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_1, t_stack *stack_2);

#endif