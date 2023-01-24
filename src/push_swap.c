/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/24 02:29:49 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	push_back(t_stack *stack, int new_value)
{
	while (stack->next)
		stack = stack->next;
	stack->next = malloc(sizeof(t_stack));
	stack = stack->next;
	stack->value = new_value;
}

int	array_len(char **argv)
{	
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_first;
	int		i;

	i = 0;
	stack = malloc(sizeof(t_stack));
	stack->value = ft_atoi(argv[i]);
	stack_first = stack;
	while (++i < argc || i < array_len(argv))
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

int	main(int argc, char **argv)
{
	t_stack			*stack1;

	if (checking(argc, argv))
	{
		write(1, "le checking est carré !\n", 25);
		if (argc == 2)
			stack1 = fill_stack(argc - 1, ft_split(argv[1], ' '));
		if (argc > 2)
			stack1 = fill_stack(argc - 1, &argv[1]);
		print_stack(stack1);
	}
	return (0);
}
