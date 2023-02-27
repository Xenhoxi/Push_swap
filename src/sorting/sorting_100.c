/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:29:59 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/27 15:59:57 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_100(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	if (stack_data_1->start_length <= 25)
		sorting_small(stack_data_1, stack_data_2);
	else if (stack_data_1->start_length > 25)
		sorting_big(stack_data_1, stack_data_2);
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
	else if (stack_data_1->start_length > 200)
		size = stack_data_1->start_length / 23;
	return (size);
}

void	sorting_big(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	int	i;
	int	chunk_size;

	chunk_size = define_chunk_size(stack_data_1);
	i = 0;
	while (stack_data_1->length > chunk_size)
		pb_chunk(stack_data_1, stack_data_2, ++i, chunk_size);
	while (stack_data_1->length > 1)
	{
		put_lower_in_first(stack_data_1, 'a');
		pb(stack_data_1, stack_data_2);
	}
	while (stack_data_2->length)
	{
		if (stack_data_1->first->rank == (stack_data_2->first->rank) + 1)
			pa(stack_data_1, stack_data_2);
		else
		{
			put_higher_in_first(stack_data_2, 'b');
			pa(stack_data_1, stack_data_2);
		}
	}
}

void	pb_chunk(t_list_data *stack_data_1, t_list_data *stack_data_2, int i, int size)
{
	t_list	*stack_1;
	int		rank_min;

	stack_1 = stack_data_1->first;
	rank_min = find_lower_rank(stack_data_1);
	while (stack_data_2->length < size * 2 * i && stack_data_1->length > 1)
	{
		stack_1 = stack_data_1->first;
		if (stack_1->rank == stack_data_1->start_length)
			rotate(stack_data_1, 'a');
		else if (stack_1->rank >= rank_min + size && stack_1->rank < rank_min + size * 2)
			pb(stack_data_1, stack_data_2);
		else if (stack_1->rank >= rank_min && stack_1->rank < rank_min + size)
		{
			pb(stack_data_1, stack_data_2);
			rotate(stack_data_2, 'b');
		}
		else if (stack_data_2->length == stack_data_1->start_length)
			break ;
		else
			rotate(stack_data_1, 'a');
	}
}

void	put_higher_in_first(t_list_data *stack_data, char chose_stack)
{
	int	rank_max;
	int	pos;

	rank_max = find_higher_rank(stack_data);
	pos = find_eazy_ways(stack_data, rank_max);
	while (stack_data->first->rank != rank_max && pos <= stack_data->length / 2)
		rotate(stack_data, chose_stack);
	while (stack_data->first->rank != rank_max && pos > stack_data->length / 2)
		rev_rotate(stack_data, chose_stack);
}
