/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:32:06 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/10 14:06:35 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_3(t_list_data *stack_data)
{
	int	position;

	position = 0;
	position = check_position(stack_data);
	if (position == 1)
		swap(stack_data, 'a');
	else if (position == 7)
	{
		swap(stack_data, 'a');
		rev_rotate(stack_data, 'a');
	}
	else if (position == 6)
		rev_rotate(stack_data, 'a');
	else if (position == 2)
	{
		swap(stack_data, 'a');
		rotate(stack_data, 'a');
	}
	else if (position == 5)
		rotate(stack_data, 'a');
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
		if (stack->rank > stack->next->rank)
			result += i;
		i *= 2;
		stack = stack->next;
	}
	if (stack_data->length == 3
		&& stack_data->first->rank > stack->rank)
		result += i;
	return (result);
}
