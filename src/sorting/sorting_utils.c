/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:49:32 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 11:57:04 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	ranking(t_list *stack)
{
	t_list	*compared;
	t_list	*start;
	int		i;

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

int	is_sort(t_list *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
