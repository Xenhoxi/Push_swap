/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/21 01:02:36 by ljerinec         ###   ########.fr       */
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

/*
Ajoute au debut de la liste !
*/

// void	push_back(t_stack **stack, int new_value)
// {
// t_stack *new_node = malloc(sizeof(t_stack));
// new_node->value = new_value;
// new_node->next = *stack;
// *stack = new_node;
// }

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
	if (parsing(argc, argv))
		printf("Error\n");
	else
		printf("Parsing OK !\n");
	// t_stack_info	*stack_info;
	// t_stack			*stack1;

	// stack_info = malloc(sizeof(t_stack));
	// stack1 = malloc(sizeof(t_stack));
	// stack_info->s1_first = stack1;
	// push_back(stack1, 102);
	// push_back(stack1, 103);
	// push_back(stack1, 104);
	// print_stack(stack1);
	return (0);
}
