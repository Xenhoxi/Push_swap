/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:56 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/11 01:42:41 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	rev_rotate(t_list_data *stack_data, char stack_selected)
{
	t_list	*tmp;
	t_list	*stack;

	stack = stack_data->first;
	if (stack_data->first && stack_data->first->next)
	{
		while (stack->next)
			stack = stack->next;
		tmp = stack;
		stack = stack->prev;
		stack->next = 0;
		tmp->prev = 0;
		tmp->next = stack_data->first;
		stack_data->first->prev = tmp;
		stack_data->first = tmp;
		if (stack_selected == 'a')
			write(1, "rra\n", 4);
		if (stack_selected == 'b')
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_list_data *stack_data_1, t_list_data *stack_data_2, int true)
{
	rev_rotate(stack_data_1, ' ');
	rev_rotate(stack_data_2, ' ');
	if (true)
		write(1, "rrr\n", 4);
}
