/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:27:58 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/07 01:49:21 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	pa(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	t_list	*tmp;

	if (stack_data_2->length > 0 && stack_data_2->first)
	{
		tmp = stack_data_2->first;
		stack_data_2->first = stack_data_2->first->next;
		if (stack_data_2->first)
			stack_data_2->first->prev = 0;
		stack_data_2->length--;
		tmp->next = stack_data_1->first;
		tmp->prev = 0;
		if (tmp->next)
			tmp->next->prev = tmp;
		stack_data_1->first = tmp;
		stack_data_1->length++;
		write(1, "pa\n", 3);
	}
}

void	pb(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	t_list	*tmp;

	if (stack_data_1->length > 0 && stack_data_1->first)
	{
		tmp = stack_data_1->first;
		stack_data_1->first = stack_data_1->first->next;
		if (stack_data_1->first)
			stack_data_1->first->prev = 0;
		stack_data_1->length--;
		tmp->next = stack_data_2->first;
		tmp->prev = 0;
		if (tmp->next)
			tmp->next->prev = tmp;
		stack_data_2->first = tmp;
		stack_data_2->length++;
		write(1, "pb\n", 3);
	}
}
