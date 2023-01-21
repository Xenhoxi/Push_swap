/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/21 15:30:25 by ljerinec         ###   ########.fr       */
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

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_first;
	int		i;

	i = 1;
	stack = malloc(sizeof(t_stack));
	stack->value = ft_atoi(argv[i++]);
	stack_first = stack;
	while (i < argc)
	{
		while (stack->next)
			stack = stack->next;
		stack->next = malloc(sizeof(t_stack));
		stack = stack->next;
		stack->value = ft_atoi(argv[i]);
		i++;
	}
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
	int				i;

	i = 1;
	stack1 = fill_stack(argc, argv);
	push_back(stack1, 15);
	print_stack(stack1);
	return (0);
}

	// if (parsing(argc, argv))
	// 	printf("Error\n");
	// else
	// 	printf("Parsing OK !\n");