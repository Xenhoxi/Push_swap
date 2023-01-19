/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/19 18:26:28 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	push_back(t_stack *stack, int new_value)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	stack->next = malloc(sizeof(t_stack));
	stack = stack->next;
	stack->value = new_value;
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_info	*stack1_info;
	t_stack			*stack1;

	stack1 = malloc(sizeof(t_stack));
	stack1_info = malloc(sizeof(t_stack));
	stack1_info->first = stack1;
	return (0);
}
