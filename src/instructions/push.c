/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:27:58 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/13 13:40:47 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	push(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	t_list	*tmp;

	if (stack_data_1->length != 0 && stack_data_1->first)
	{
		tmp = stack_data_1->first;
		stack_data_1->first = stack_data_1->first->next;
		stack_data_1->length--;
		tmp->next = stack_data_2->first;
		tmp->prev = 0;
		stack_data_2->first = tmp;
		stack_data_2->length++;
		if (stack_data_1->name == 'b' && stack_data_2->name == 'a')
			write(1, "pa\n", 3);
		if (stack_data_1->name == 'a' && stack_data_2->name == 'b')
			write(1, "pb\n", 3);
	}
}
