/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:14:04 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/13 13:26:59 by ljerinec         ###   ########.fr       */
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

void	init_list(t_list_data *stack, char _name)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->name = _name;
	stack->length = 0;
}
