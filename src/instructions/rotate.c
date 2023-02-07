/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:52 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/07 16:41:38 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	ra(t_list **stack_1)
{
	if (stack_1)
	{
		ft_lstadd_back(stack_1, ft_lstnew((*stack_1)->value));
		ft_lstdelfirst(stack_1);
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack_2)
{
	if (stack_2)
	{
		ft_lstadd_back(stack_2, ft_lstnew((*stack_2)->value));
		ft_lstdelfirst(stack_2);
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **stack_1, t_list **stack_2)
{
	if (stack_1 && stack_2)
	{
		ft_lstadd_back(stack_1, ft_lstnew((*stack_1)->value));
		ft_lstdelfirst(stack_1);
		ft_lstadd_back(stack_2, ft_lstnew((*stack_2)->value));
		ft_lstdelfirst(stack_2);
		write(1, "rr\n", 3);
	}
}
