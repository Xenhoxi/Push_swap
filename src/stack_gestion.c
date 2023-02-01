/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/01 14:02:15 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	push_back(t_stack **stack, int new_value)
{
	t_stack	*tmp_prev;
	t_stack	*stackfirst;

	if (!(*stack))
	{
		(*stack) = malloc(sizeof(t_stack));
		(*stack)->value = new_value;
		(*stack)->next = 0;
		(*stack)->prev = 0;
		(*stack)->first = (*stack);
	}
	else
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = malloc(sizeof(t_stack));
		tmp_prev = (*stack);
		stackfirst = (*stack)->first;
		(*stack) = (*stack)->next;
		(*stack)->value = new_value;
		(*stack)->next = 0;
		(*stack)->prev = tmp_prev;
		(*stack)->first = stackfirst;
	}
}

void	fill_stack_split(int argc, char **argv, t_stack **stack)
{
	int		i;

	i = 0;
	while (i < argc)
		push_back(stack, ft_atoi(argv[i++]));
}

void	fill_stack_argv(int argc, char **argv, t_stack **stack)
{
	int		i;

	i = 1;
	while (i < argc)
		push_back(stack, ft_atoi(argv[i++]));
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

void	print_reverse_stack(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->prev;
	}
}
