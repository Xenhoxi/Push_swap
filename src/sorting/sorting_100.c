/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:29:59 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/22 12:49:44 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_100(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	int 	chunk_size;

	// chunk_size = size_of_chunk(stack_data_1);
	chunk_size = 10;
	push_chunk(stack_data_1, stack_data_2, chunk_size);
}
 
int	size_of_chunk(t_list_data *stack)
{
	int	size;

	size = stack->length / 4;
	return (size);
}

void	push_chunk(t_list_data *stack_data_1, t_list_data *stack_data_2, int size)
{
	t_list	*stack_1;
	int		length_wanted;

	stack_1 = stack_data_1->first;
	length_wanted = stack_data_1->length - size;
	while (stack_data_1->length > length_wanted)
	{
		if (stack_1->rank < size)
			pb(stack_data_1, stack_data_2);
		else
			rotate(stack_data_1, 'a');
	}
}
