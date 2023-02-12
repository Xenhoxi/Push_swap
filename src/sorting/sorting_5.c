/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:46:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/11 21:03:54 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_5(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	while (stack_data_1->length > 3)
	{
		if (put_lower_in_first(stack_data_1, find_lower(stack_data_1)) == 1)
			pb(stack_data_1, stack_data_2);
	}
	// print_list(stack_data_1->first);
	// printf("---\n");
	// print_list(stack_data_2->first);
	sorting_3(stack_data_1);
	if (!is_sort(stack_data_2))
		swap(stack_data_2, 'b');
	while (stack_data_2->length > 0)
		pa(stack_data_1, stack_data_2);
}

int	find_lower(t_list_data *stack_data_1)
{
	t_list	*stack;
	int		pos;

	pos = 0;
	stack = stack_data_1->first;
	while (stack->next)
	{
		if (stack->rank == 1)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int	put_lower_in_first(t_list_data *stack_data, int lower_pos)
{
	if (lower_pos <= 3)
	{
		while (stack_data->first->rank != 1)
		{
			printf("lower pos : %d\n", stack_data->first->rank);
			ra(stack_data);
			ranking(stack_data);
			lower_pos--;
		}
		return (1);
	}
	else if (lower_pos > 3 && lower_pos <= 5)
	{
		while (stack_data->first->rank != 1)
		{
			ranking(stack_data);
			printf("lower pos : %d\n", stack_data->first->rank);
			rra(stack_data);
			ranking(stack_data);
			lower_pos--;
		}
		return (1);
	}
	return (0);
}
