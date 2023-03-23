/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:14:04 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/22 11:28:34 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

int	stacklen(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_list	*stacklast(t_list *stack)
{
	if (stack)
		while (stack->next)
			stack = stack->next;
	return (stack);
}

t_list_data	*init_list(void)
{
	t_list_data	*stack;

	stack = malloc(sizeof(t_list_data));
	stack->first = NULL;
	stack->last = NULL;
	stack->start_length = -1;
	stack->length = 0;
	return (stack);
}
