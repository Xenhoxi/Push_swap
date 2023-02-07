/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:08:58 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/06 20:38:59 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sa(t_list *stack)
{
	int	swap;

	swap = 0;
	if (stack && stack->next)
	{
		swap = stack->value;
		stack->value = stack->next->value;
		stack->next->value = swap;
	}
	write(1, "sa\n", 3);
}

void	sb(t_list *stack)
{
	int	swap;

	swap = 0;
	if (stack && stack->next)
	{
		swap = stack->value;
		stack->value = stack->next->value;
		stack->next->value = swap;
	}
	write(1, "sb\n", 3);
}

void	ss(t_list *stack_1, t_list *stack_2)
{
	int	swap;

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
