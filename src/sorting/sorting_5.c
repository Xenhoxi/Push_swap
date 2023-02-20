/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:46:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/20 14:04:32 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_5(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	while (stack_data_1->length > 3)
	{
		if (put_lower_in_first(stack_data_1) == 1)
			pb(stack_data_1, stack_data_2);
	}
	sorting_3(stack_data_1);
	if (is_sort(stack_data_2))
		swap(stack_data_2, 'b');
	while (stack_data_2->length > 0)
		pa(stack_data_1, stack_data_2);
}

int	find_lower(t_list_data *stack_data)
{
	t_list	*stack;
	int		pos;
	int		i;

	i = 0;
	pos = 1;
	stack = stack_data->first;
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			pos += i;
		else
			i++;
		stack = stack->next;
	}
	return (pos);
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

int	put_lower_in_first(t_list_data *stack_data)
{
	int	smallest_rank;

	smallest_rank = find_lower_rank(stack_data);
	while (stack_data->first->rank != smallest_rank)
		rotate(stack_data, 'a');
	return (1);
}
