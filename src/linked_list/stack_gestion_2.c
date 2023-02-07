/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gestion_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:14:04 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 00:23:27 by ljerinec         ###   ########.fr       */
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

void	stacklast(t_list **stack)
{
	if ((*stack))
		while ((*stack)->next)
			(*stack) = (*stack)->next;
}

void	stackfirst(t_list **stack)
{
	if (*stack)
		while ((*stack)->prev)
			(*stack) = (*stack)->prev;
}
