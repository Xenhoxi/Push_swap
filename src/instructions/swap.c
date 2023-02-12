/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:08:58 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/11 17:01:49 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	swap(t_list_data *stack_data, char stack_selected)
{
	t_list	*stack;
	t_list	*swap;

	stack = stack_data->first;
	swap = NULL;
	if (stack && stack->next)
	{
		swap = stack->next;
		stack->next = swap->next;
		if (stack->next)
			stack->next->prev = stack;
		swap->prev = 0;
		swap->next = stack;
		stack_data->first = swap;
		if (stack_selected == 'a')
			write(1, "sa\n", 3);
		if (stack_selected == 'b')
			write(1, "sb\n", 3);
	}
}

void	ss(t_list_data *stack__1, t_list_data *stack__2)
{
	t_list	*stack_1;
	t_list	*stack_2;
	int		swap;

	stack_1 = stack__1->first;
	stack_2 = stack__2->first;
	swap = 0;
	if (stack_1 && stack_1->next)
	{
		swap = stack_1->value;
		stack_1->value = stack_1->next->value;
		stack_1->next->value = swap;
	}
	swap = 0;
	if (stack_2 && stack_2->next)
	{
		swap = stack_2->value;
		stack_2->value = stack_2->next->value;
		stack_2->next->value = swap;
	}
	write(1, "ss\n", 3);
}
