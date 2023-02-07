/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:49:32 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 00:13:07 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	ranking(t_list *stack)
{
	t_list	*compared;
	t_list	*start;
	int		i;

	start = stack;
	compared = stack;
	i = 0;
	while (compared)
	{
		while (stack)
		{
			if (stack->value < compared->value)
				i++;
			stack = stack->next;
		}
		stack = start;
		compared->rank = i + 1;
		i = 0;
		compared = compared->next;
	}
}
