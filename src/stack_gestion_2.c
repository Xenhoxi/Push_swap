/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:14:04 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/07 14:27:33 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int	stacklen(t_list *stack)
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

void	stacklast(t_list **stack)
{
	if ((*stack))
		while ((*stack)->next)
			(*stack) = (*stack)->next;
}

void	stackfirst(t_list **stack)
{
	if (*stack)
		while ((*stack)->prev)
			(*stack) = (*stack)->prev;
}

// stack_last(t_list **stack)

// stack_new(int value)

// t_list	*stack_init(t_list *stack)
// {
// 	stack = malloc(sizeof(t_list));
// 	stack->next = 0;
// 	stack->prev = 0;
// 	stack->value = 0;
// 	stack->index = 0;
// 	stack->first = stack;
// 	stack->last = stack;
// 	return (stack);
// }
