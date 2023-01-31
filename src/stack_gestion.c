/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/31 16:18:20 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	push_back(t_stack **stac, int new_value)
{
	t_stack	*tmp_prev;
	// t_stack	*stack;

	if (!(*stac))
	{
		(*stac) = malloc(sizeof(t_stack));
		(*stac)->next = 0;
		(*stac)->value = new_value;
		(*stac)->prev = 0;
	}
	else
	{
		while ((*stac)->next)
			(*stac) = (*stac)->next;
		(*stac)->next = malloc(sizeof(t_stack));
		tmp_prev = (*stac);
		(*stac) = (*stac)->next;
		(*stac)->next = 0;
		(*stac)->value = new_value;
		(*stac)->prev = tmp_prev;
	}
}

void	fill_stack_split(int argc, char **argv, t_stack **stack)
{
	// t_stack	*stack;
	// t_stack	*stack_first;
	int		i;

	i = 0;
	// stack = malloc(sizeof(t_stack));
	// if (!stack)
	// 	return (NULL);
	// stack->value = ft_atoi(argv[i]);
	// stack_first = stack;
	// stack->next = 0;
	// stack->prev = 0;
	while (i < argc)
		push_back(stack, ft_atoi(argv[i++]));
	// return (stack_first);
}

void	fill_stack_argv(int argc, char **argv, t_stack **stack)
{
	// t_stack	*stack;
	// t_stack	*stack_first;
	int		i;

	i = 1;
	// stack = malloc(sizeof(t_stack));
	// if (!stack)
	// 	return (NULL);
	// stack->value = ft_atoi(argv[i]);
	// stack_first = stack;
	// stack->next = 0;
	// stack->prev = 0;
	while (i < argc - 1)
	{
		i++;
		push_back(stack, ft_atoi(argv[i]));
	}
	// return (stack_first);
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
