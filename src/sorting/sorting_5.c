/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:46:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/20 11:28:56 by ljerinec         ###   ########.fr       */
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
	if (!is_sort(stack_data_1))
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

	i = 1;
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
	printf("position du lower %d\n", pos);
	return (pos);
}

int	put_lower_in_first(t_list_data *stack_data, int lower_pos)
{
	print_list(stack_data->first);
	if (lower_pos <= stack_data->length / 2)
	{
		while (stack_data->first->rank != 1)
		{
			ranking(stack_data);
			rotate(stack_data, 'a');
			lower_pos--;
		}
		return (1);
	}
	else if (lower_pos > stack_data->length / 2)
	{
		while (stack_data->first->rank != 1)
		{
			ranking(stack_data);
			rev_rotate(stack_data, 'a');
			lower_pos--;
		}
		return (1);
	}
	return (0);
}
