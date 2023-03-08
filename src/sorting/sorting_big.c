/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:04:50 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/09 00:05:35 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_big(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	int		size_chunk;

	size_chunk = stack_data_1->length / 2;
	while (size_chunk < stack_data_1->start_length)
	{
		push_ck(stack_data_1, stack_data_2, size_chunk);
		size_chunk += stack_data_1->length / 2;
	}
	if (!is_sort(stack_data_1))
		swap(stack_data_1, 'a');
	while (stack_data_2->length)
	{
		if (stack_data_1->first->rank == (stack_data_2->first->rank) + 1)
			pa(stack_data_1, stack_data_2);
		else
			put_higher_in_first(stack_data_2, 'b');
	}
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
			break ;
		else
			i++;
		stack = stack->next;
	}
	// printf("rank a trouver dans first : %d\n", stack->rank);
	return (i);
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
			break ;
		else
			i++;
		stack = stack->prev;
	}
	// printf("rank a trouver dans last : %d\n", stack->rank);
	return (++i);
}

void	push_ck(t_list_data *s_data_1, t_list_data *s_data_2, int size)
{
	t_list	*stack;

	stack = s_data_1->first;
	while (s_data_2->length < size)
	{
		stack = s_data_1->first;
		if (stack->rank <= size)
			pb(s_data_1, s_data_2);
		else if (s_data_1->length == 0)
			break ;
		else
			rev_rotate(s_data_1, 'a');
		stack = s_data_1->first;
	}
}

void	pa_ck(t_list_data *s_data_1, t_list_data *s_data_2, int size)
{
	t_list	*stack;

	stack = s_data_2->first;
	while (s_data_1->length < size)
	{
		stack = s_data_2->first;
		if (stack->rank >= size)
			pb(s_data_1, s_data_2);
		else if (s_data_1->length == 0)
			break ;
		else
			rotate(s_data_1, 'b');
		stack = s_data_1->first;
	}
}
