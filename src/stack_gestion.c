/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/26 03:03:16 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	push_back(t_stack *stack, int new_value)
{
	t_stack	*tmp_prev;

	while (stack->next)
		stack = stack->next;
	stack->next = malloc(sizeof(t_stack));
	tmp_prev = stack;
	stack = stack->next;
	stack->value = new_value;
	stack->prev = tmp_prev;
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_first;
	int		len_args;
	int		i;

	i = 0;
	len_args = array_len(argv);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = ft_atoi(argv[i]);
	stack_first = stack;
	while (++i < argc || i < len_args)
		push_back(stack, ft_atoi(argv[i]));
	return (stack_first);
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