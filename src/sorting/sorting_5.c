/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:46:53 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/09 16:01:34 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_5(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	t_list	*stack_1;
	t_list	*stack_2;

	stack_1 = stack_data_1->first;
	stack_2 = stack_data_2->first;
	while (stack_data_1->length > 3)
		pb(stack_data_1, stack_data_2);
	sorting_3(stack_data_1);
	sorting_3(stack_data_2);
	while (stack_data_2->length > 0)
		pa(stack_data_1, stack_data_2);
	ranking(stack_data_1);
	if (stack_1->rank == stack_data_1->length)
		ra(stack_data_1);
	ranking(stack_data_1);
	if (stack_1->rank > stack_1->next->rank)
		sa(stack_data_1);
}
