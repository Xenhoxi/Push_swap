/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:27:58 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/07 18:14:30 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	pa(t_list **stack_1, t_list **stack_2)
{
	if (*stack_2 && stack_2)
	{
		ft_lstadd_front(stack_1, ft_lstnew((*stack_2)->value));
		ft_lstdelfirst(stack_2);
		write(1, "pa\n", 3);
	}
}

void	pb(t_list **stack_1, t_list **stack_2)
{
	if (*stack_1 && stack_1)
	{
		ft_lstadd_front(stack_2, ft_lstnew((*stack_1)->value));
		ft_lstdelfirst(stack_1);
		write(1, "pb\n", 3);
	}
}
