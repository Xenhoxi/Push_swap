/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:49:32 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/09 15:57:10 by ljerinec         ###   ########.fr       */
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

void	put_higher(t_list_data *s_d_1, t_list_data *s_d_2, char chose_stack)
{
	int		rank_max;
	int		pos;

	rank_max = find_higher_rank(s_d_2);
	pos = find_eazy_ways(s_d_2, rank_max);
	if (pos <= s_d_2->length / 2)
	{
		while (s_d_2->first->rank != rank_max)
		{
			if (s_d_2->first->rank == rank_max - 1)
				pa(s_d_1, s_d_2);
			else
				rotate(s_d_2, chose_stack);
		}
	}
	else
	{
		while (s_d_2->first->rank != rank_max)
		{
			if (s_d_2->first->rank == rank_max - 1)
				pa(s_d_1, s_d_2);
			else
				rev_rotate(s_d_2, chose_stack);
		}
	}
}
