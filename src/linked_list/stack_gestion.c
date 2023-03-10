/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/09 21:23:52 by ljerinec         ###   ########.fr       */
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

void	print_list(t_list_data *stack_data, int nb_stack)
{
	t_list	*stack_1;

	stack_1 = stack_data->first;
	if (nb_stack == 1)
		printf("Stacks 1 | length %d\n", stack_data->length);
	if (nb_stack == 2)
		printf("Stacks 2 | length %d\n", stack_data->length);
	while (stack_1)
	{
		printf("Value %d | rank %d | prev %p | current %p | next %p\n",
			stack_1->value, stack_1->rank, stack_1->prev, stack_1,
			stack_1->next);
		stack_1 = stack_1->next;
	}
}

void	free_linked_list(t_list_data *stack_1, t_list_data *stack_2)
{
	(void) stack_2;

	while (stack_1->first->next)
		ft_lstdellast(stack_1->first);
	free(stack_1->first);
	stack_1->first = NULL;
}
