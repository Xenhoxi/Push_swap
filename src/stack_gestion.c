/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/27 12:35:13 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

t_stack	*push_back(t_stack *stack, int new_value)
{
	t_stack	*tmp_prev;
	t_stack	*stack_first;

	tmp_prev = stack;
	stack->next = malloc(sizeof(t_stack));
	stack = stack->next;
	stack_first = stack->first;
	stack->value = new_value;
	stack->prev = tmp_prev;
	stack->first = stack_first;
	return (stack);
}

t_stack	*find_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*fill_stack_split(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*last;
	int		i;

	i = 0;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = ft_atoi(argv[i]);
	stack->first = stack;
	while (++i < argc)
		stack = push_back(stack, ft_atoi(argv[i]));
	last = find_last(stack);
	return (stack->first);
}

t_stack	*fill_stack_argv(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = ft_atoi(argv[i]);
	stack->first = stack;
	while (i < argc)
		push_back(stack, ft_atoi(argv[++i]));
	return (stack->first);
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