/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:02 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/21 10:19:39 by ljerinec         ###   ########.fr       */
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
	t_list	*last;
	int		length;
	int		start_length;
}			t_list_data;

// push_swap.c
void	sorting(t_list_data *stack_1, t_list_data *stack_2);

// parsing.c 
void	set_stack_1(int argc, char **argv, t_list_data *stack_1);
int		checking(int argc, char **argv);
int		check_argv(char	**input_list, int argc);
int		only_digit(char	**input_list, int argc);
int		identical_numbers(long long *int_array, int input_len);

// parsing_2.c
int		only_int(char **input_list);
int		array_len(char **argv);
void	error(void);

// stack_gestion.c
void	fill_stack_split(int argc, char **argv, t_list_data *stack);
void	fill_stack_argv(int argc, char **argv, t_list_data *stack);
void	print_list(t_list *stack);
void	print_rank(t_list *stack);
void	print_reverse_stack(t_list *stack);

// stack_gestion_2.c
int		stacklen(t_list *stack);
t_list	*stacklast(t_list *stack);
void	init_list(t_list_data *stack);

// --- OPERATEURS ---

// swap.c
void	swap(t_list_data *stack_data, char stack_selected);
void	ss(t_list_data *stack__1, t_list_data *stack__2);
// push.c
void	pa(t_list_data *stack_data_1, t_list_data *stack_data_2);
void	pb(t_list_data *stack_data_1, t_list_data *stack_data_2);
// rotate.c
void	rotate(t_list_data *stack_data, char stack_selected);
void	rr(t_list_data *stack_data_1, t_list_data *stack_data_2);
// reverse_rotate.c
void	rev_rotate(t_list_data *stack_data, char stack_selected);
void	rrr(t_list_data *stack_data_1, t_list_data *stack_data_2);

// sorting_utils.c 
void	ranking(t_list_data *stack_data);
int		is_sort(t_list_data *stack_data);

// sorting_3.c
void	sorting_3(t_list_data *stack_data);
int		check_position(t_list_data *stack_data);

// sorting_5.c
void	sorting_5(t_list_data *stack_1, t_list_data *stack_2);
int		put_lower_in_first(t_list_data *stack_data);

// sorting_100.c
void	sorting_100(t_list_data *stack_1, t_list_data *stack_2);

#endif