/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:02 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/27 12:33:26 by ljerinec         ###   ########.fr       */
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
void	error(char **input_list);

// stack_gestion.c
t_stack	*fill_stack_split(int argc, char **argv);
t_stack	*fill_stack_argv(int argc, char **argv);
t_stack	*push_back(t_stack *stack, int new_value);
void	print_stack(t_stack *stack);
void	print_reverse_stack(t_stack *stack);

// utils.c
int		array_len(char **argv);

#endif