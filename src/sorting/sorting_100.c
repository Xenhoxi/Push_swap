/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:29:59 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/09 11:54:59 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_100(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	if (stack_data_1->start_length <= 25)
		sorting_small(stack_data_1, stack_data_2);
	else if (stack_data_1->start_length > 25)
		sorting_bigg(stack_data_1, stack_data_2);
}

void	sorting_small(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	while (stack_data_1->length)
	{
		put_lower_in_first(stack_data_1, 'a');
		pb(stack_data_1, stack_data_2);
	}
	while (stack_data_2->length)
		pa(stack_data_1, stack_data_2);
}

int	define_chunk_size(t_list_data *stack_data_1)
{
	int	size;

	size = stack_data_1->start_length;
	if (stack_data_1->start_length <= 100)
		size = stack_data_1->start_length / 8;
	else if (stack_data_1->start_length <= 150)
		size = stack_data_1->start_length / 10;
	else if (stack_data_1->start_length <= 200)
		size = stack_data_1->start_length / 15;
	else if (stack_data_1->start_length > 400)
		size = stack_data_1->start_length / 18;
	return (size);
}

void	sorting_bigg(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	int	i;
	int	chunk_size;

	chunk_size = define_chunk_size(stack_data_1);
	i = 0;
	while (stack_data_1->length > chunk_size)
		pb_chunk(stack_data_1, stack_data_2, i++, chunk_size);
	while (stack_data_1->length > 0)
	{
		if (is_sort(stack_data_1))
			break ;
		put_lower_in_first(stack_data_1, 'a');
		pb(stack_data_1, stack_data_2);
	}
	while (stack_data_1->first->rank == (stack_data_2->first->rank) + 1)
		pa(stack_data_1, stack_data_2);
	while (stack_data_2->length)
	{
		put_higher_in_first(stack_data_2, 'b');
		pa(stack_data_1, stack_data_2);
	}
}

void	while_its_sort(t_list_data *s_data_1, t_list_data *s_data_2)
{
	t_list	*s_1;
	t_list	*s_2;

	s_1 = s_data_1->first;
	s_2 = s_data_2->first;
	while (s_data_2->length)
	{
		if (s_1->rank > s_2->next->rank)
			pa(s_data_1, s_data_2);
		else
		{
			put_higher_in_first(s_data_2, 'b');
			pa(s_data_1, s_data_2);
		}
	}
}

void	pb_chunk(t_list_data *s_data_1, t_list_data *s_data_2, int i, int size)
{
	t_list	*s_1;
	int		min_r;

	min_r = find_lower_rank(s_data_1);
	s_1 = s_data_1->first;
	while (s_data_2->length < size * 2 * i && s_data_1->length > 1)
	{
		s_1 = s_data_1->first;
		if (s_1->rank == s_data_1->start_length)
			rotate(s_data_1, 'a');
		else if (s_1->rank >= min_r + size && s_1->rank < min_r + size * 2)
			pb(s_data_1, s_data_2);
		else if (s_1->rank >= min_r && s_1->rank < min_r + size)
		{
			pb(s_data_1, s_data_2);
			rotate(s_data_2, 'b');
		}
		else if (s_data_2->length == s_data_1->start_length)
			break ;
		else
			rotate(s_data_1, 'a');
	}
}

void	what_should_i_do(t_list_data *stack_data, int size, int min_r)
{
	int	first;
	int	last;

	first = find_first_in_range(stack_data, size, min_r);
	last = find_last_in_range(stack_data, size, min_r);
	if (first < last)
		while (first > 0 && first--)
			rotate(stack_data, 'a');
	else
		while (last && last--)
			rev_rotate(stack_data, 'a');
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
	return (++i);
}
