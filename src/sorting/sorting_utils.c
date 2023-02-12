/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:49:32 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/09 15:56:57 by ljerinec         ###   ########.fr       */
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