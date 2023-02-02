/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:14:04 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/02 16:31:12 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int	stacklen(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// stack_last(t_stack **stack)

// stack_new(int value)

// t_stack	*stack_init(t_stack *stack)
// {
// 	stack = malloc(sizeof(t_stack));
// 	stack->next = 0;
// 	stack->prev = 0;
// 	stack->value = 0;
// 	stack->index = 0;
// 	stack->first = stack;
// 	stack->last = stack;
// 	return (stack);
// }
