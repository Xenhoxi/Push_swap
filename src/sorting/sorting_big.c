/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:04:50 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/03 00:18:00 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_big(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	int		size_chunk;
	int		i;

	i = 0;
	size_chunk = 50;
	printf("size_chunk = %d\n", size_chunk);
	while (stack_data_1->length > size_chunk)
		push_ck(stack_data_1, stack_data_2, size_chunk, ++i);
	print_list(stack_data_1->first, 1);
	print_list(stack_data_2->first, 2);
}


int	find_first_in_range(t_list_data *stack_data, int size, int min_r)
{
	t_list	*stack;
	int		i;

	stack = stack_data->first;
	i = 0;
	while (stack)
	{
		if (stack->rank >= min_r && stack->rank < min_r + size * 2)
			return (i);
		else
			i++;
		stack = stack->next;
	}
	return (-1);
}

int	find_last_in_range(t_list_data *stack_data, int size, int min_r)
{
	t_list	*stack;
	int		i;

	stack = stacklast(stack_data->first);
	i = 0;
	while (stack)
	{
		if (stack->rank >= min_r && stack->rank < min_r + size * 2)
			return (i++);
		else
			i++;
		stack = stack->prev;
	}
	return (1);
}

void	what_should_i_do(t_list_data *stack_data, int size, int min_r)
{
	int	first;
	int	last;

	first = find_first_in_range(stack_data, size, min_r);
	last = find_last_in_range(stack_data, size, min_r);
	if (first < last)
		rotate(stack_data, 'a');
	else
		rev_rotate(stack_data, 'a');
}

void	push_ck(t_list_data *s_data_1, t_list_data *s_data_2, int size, int i)
{
	int		range_top;
	int		range_low;
	t_list	*stack;

	stack = s_data_1->first;
	range_top = find_higher_rank(s_data_1);
	range_low = range_top - size * i;
	while (s_data_2->length <= size * i)
	{
		if (stack->rank > range_low && stack->rank <= range_top)
			pb(s_data_1, s_data_2);
		else if (s_data_2->length == s_data_1->start_length)
			break ;
		else
			what_should_i_do(s_data_1, size, range_low);
		stack = s_data_1->first;
	}
	printf("range_top = %d\n", range_top);
	printf("range_low = %d\n", range_low);
}

// || range_top - range_low < size * i)
