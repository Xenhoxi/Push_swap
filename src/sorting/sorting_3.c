/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:32:06 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/11 17:04:34 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_3(t_list_data *stack_data)
{
	int	position;

	position = check_position(stack_data);
	if (position == 1)
		swap(stack_data, 'a');
	else if (position == 6)
	{
		swap(stack_data, 'a');
		rra(stack_data);
	}
	else if (position == 4)
		ra(stack_data);
	else if (position == 2)
	{
		swap(stack_data, 'a');
		ra(stack_data);
	}
	else if (position == 5)
		rra(stack_data);
}

int	check_position(t_list_data *stack_data)
{
	t_list	*stack;
	int		result;
	int		i;

	i = 1;
	result = 0;
	stack = stack_data->first;
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			result += i;
		i++;
		stack = stack->next;
	}
	if (stack_data->length == 3
		&& stack_data->first->value > stack_data->last->value)
		result += i;
	return (result);
}
