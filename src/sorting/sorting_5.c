/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:46:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/22 10:54:54 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_5(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	while (stack_data_1->length > 3)
	{
		put_lower_in_first(stack_data_1);
		pb(stack_data_1, stack_data_2);
	}
	sorting_3(stack_data_1);
	if (is_sort(stack_data_2))
		swap(stack_data_2, 'b');
	while (stack_data_2->length > 0)
		pa(stack_data_1, stack_data_2);
}

int	find_lower_rank(t_list_data *stack_data)
{
	int		rank;
	t_list	*stack;

	stack = stack_data->first;
	rank = stack->rank;
	while (stack)
	{
		if (stack->rank < rank)
			rank = stack->rank;
		stack = stack->next;
	}
	return (rank);
}

void	put_lower_in_first(t_list_data *stack_data)
{
	int	low_rank;
	int	pos;

	low_rank = find_lower_rank(stack_data);
	pos = find_eazy_ways(stack_data, low_rank);
	while (stack_data->first->rank != low_rank && pos <= stack_data->length / 2)
		rotate(stack_data, 'a');
	while (stack_data->first->rank != low_rank && pos > stack_data->length / 2)
		rev_rotate(stack_data, 'a');
}

int	find_eazy_ways(t_list_data *stack_data, int smallest_rank)
{
	t_list	*stack;
	int		i;

	stack = stack_data->first;
	i = 0;
	while (stack)
	{
		if (stack->rank == smallest_rank)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}
