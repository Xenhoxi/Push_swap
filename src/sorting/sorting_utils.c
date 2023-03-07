/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:49:32 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/07 17:11:57 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	ranking(t_list_data *stack_data)
{
	t_list	*stack;
	t_list	*compared;
	t_list	*start;
	int		i;

	stack = stack_data->first;
	start = stack;
	compared = stack;
	i = 0;
	while (compared)
	{
		while (stack)
		{
			if (stack->value < compared->value)
				i++;
			stack = stack->next;
		}
		stack = start;
		compared->rank = i + 1;
		i = 0;
		compared = compared->next;
	}
}

int	is_sort(t_list_data *stack_data)
{
	t_list	*stack;

	stack = stack_data->first;
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_higher_rank(t_list_data *stack_data)
{
	int		rank;
	t_list	*stack;

	stack = stack_data->first;
	rank = stack->rank;
	while (stack)
	{
		if (stack->rank > rank)
			rank = stack->rank;
		stack = stack->next;
	}
	return (rank);
}

void	put_higher_in_first(t_list_data *stack_data, char chose_stack)
{
	int		rank_max;
	int		pos;
	t_list	*stack;

	stack = stack_data->first;
	rank_max = find_higher_rank(stack_data);
	pos = find_eazy_ways(stack_data, rank_max);
	while (stack_data->first->rank != rank_max && pos <= stack_data->length / 2)
	{
		rotate(stack_data, chose_stack);
	}
	while (stack_data->first->rank != rank_max && pos > stack_data->length / 2)
	{
		rev_rotate(stack_data, chose_stack);
	}
}
