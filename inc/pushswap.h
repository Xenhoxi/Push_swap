/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:02 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 12:17:45 by ljerinec         ###   ########.fr       */
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

typedef struct s_list_data
{
	t_list	*first;
	int		length;
}			t_list_data;

// push_swap.c
void	sorting(t_list **stack_1, t_list **stack_2);

// parsing.c 
void	set_stack_1(int argc, char **argv, t_list **stack);
int		checking(int argc, char **argv);
int		check_argv(char	**input_list, int argc);
int		only_digit(char	**input_list, int argc);
int		identical_numbers(long long *int_array, int input_len);

// parsing_2.c
int		only_int(char **input_list);
int		array_len(char **argv);
void	error(void);

// stack_gestion.c
void	fill_stack_split(int argc, char **argv, t_list **stack);
void	fill_stack_argv(int argc, char **argv, t_list **stack);
void	print_list(t_list *stack);
void	print_rank(t_list *stack);
void	print_reverse_stack(t_list *stack);

// stack_gestion_2.c
int		stacklen(t_list *stack);
void	stackfirst(t_list **stack_);
void	stacklast(t_list **stack_);

// --- OPERATEURS ---
// swap.c
void	sa(t_list *stack);
void	sb(t_list *stack);
void	ss(t_list *stack_1, t_list *stack_2);
// push.c
void	pa(t_list **stack_1, t_list **stack_2);
void	pb(t_list **stack_1, t_list **stack_2);
// rotate.c
void	ra(t_list **stack_1);
void	rb(t_list **stack_2);
void	rr(t_list **stack_1, t_list **stack_2);
// reverse_rotate.c
void	rra(t_list **stack_1);
void	rrb(t_list **stack_2);
void	rrr(t_list **stack_1, t_list **stack_2);

// sorting_utils.c 
void	ranking(t_list *stack);
int		is_sort(t_list *stack);

#endif