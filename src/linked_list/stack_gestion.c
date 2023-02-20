/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/20 10:38:18 by ljerinec         ###   ########.fr       */
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
	stack->start_length = stack->length;
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

void	print_list(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
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
