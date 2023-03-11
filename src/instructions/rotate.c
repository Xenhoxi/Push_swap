/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:52 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/11 01:43:05 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	rotate(t_list_data *stack_data, char stack_selected)
{
	t_list	*tmp;

	if (stack_data->first && stack_data->length >= 2)
	{
		tmp = stack_data->first;
		stack_data->first = stack_data->first->next;
		tmp->next = 0;
		tmp->prev = stacklast(stack_data->first);
		stacklast(stack_data->first)->next = tmp;
		if (stack_selected == 'a')
			write(1, "ra\n", 3);
		if (stack_selected == 'b')
			write(1, "rb\n", 3);
	}
}

void	rr(t_list_data *stack_data_1, t_list_data *stack_data_2, int true)
{
	if (stack_data_1->first && stack_data_1->first->next)
		rotate(stack_data_1, ' ');
	if (stack_data_2->first && stack_data_2->first->next)
		rotate(stack_data_2, ' ');
	if (true)
		write(1, "rr\n", 3);
}
