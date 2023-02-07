/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:56 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/07 16:46:58 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	rra(t_list **stack_1)
{
	if (stack_1)
	{
		ft_lstadd_front(stack_1, ft_lstnew((*stack_1)->value));
		ft_lstdellast(stack_1);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_2)
{
	if (stack_2)
	{
		ft_lstadd_front(stack_2, ft_lstnew((*stack_2)->value));
		ft_lstdellast(stack_2);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_1, t_list **stack_2)
{
	if (stack_1 && stack_2)
	{
		ft_lstadd_front(stack_1, ft_lstnew((*stack_1)->value));
		ft_lstdellast(stack_1);
		ft_lstadd_front(stack_2, ft_lstnew((*stack_2)->value));
		ft_lstdellast(stack_2);
		write(1, "rrr\n", 4);
	}
}
