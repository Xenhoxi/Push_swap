/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/23 12:21:14 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	fill_stack_split(int argc, char **argv, t_list_data *stack)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		ft_lstadd_back(&stack->first, ft_lstnew(ft_atoi(argv[i++])));
		stack->length++;
	}
	stack->start_length = stack->length++;
	stack->last = stacklast(stack->first);
}

void	fill_stack_argv(int argc, char **argv, t_list_data *stack)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&stack->first, ft_lstnew(ft_atoi(argv[i++])));
		stack->start_length = stack->length;
		stack->length++;
	}
	stack->last = stacklast(stack->first);
}

void	print_list(t_list *stack_1, int nb_stack)
{
	if (nb_stack == 1)
		printf("Stacks 1\n");
	if (nb_stack == 2)
		printf("Stacks 2\n");
	while (stack_1)
	{
		printf("%d -> %d\n", stack_1->value, stack_1->rank);
		stack_1 = stack_1->next;
	}
}

void	print_rank(t_list *stack)
{
	printf("Rank\n---\n");
	while (stack)
	{
		printf("%d\n", stack->rank);
		stack = stack->next;
	}
	printf("---\n");
}

void	print_reverse_stack(t_list *stack)
{
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
		while (stack)
		{
			printf("%d\n", stack->value);
			stack = stack->prev;
		}
	}
}
