/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:52 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 14:38:37 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	ra(t_list_data *stack)
{
	t_list	**stack_1;

	stack_1 = &stack->first;
	if (stack_1 && *stack_1)
	{
		ft_lstadd_back(stack_1, ft_lstnew((*stack_1)->value));
		ft_lstdelfirst(stack_1);
		write(1, "ra\n", 3);
	}
}

void	rb(t_list_data *stack)
{
	t_list	**stack_2;

	stack_2 = &stack->first;
	if (stack_2 && *stack_2)
	{
		ft_lstadd_back(stack_2, ft_lstnew((*stack_2)->value));
		ft_lstdelfirst(stack_2);
		write(1, "rb\n", 3);
	}
}

void	rr(t_list_data *stack__1, t_list_data *stack__2)
{
	t_list	**stack_1;
	t_list	**stack_2;

	stack_1 = &stack__1->first;
	stack_2 = &stack__2->first;
	if (stack_1 && stack_2 && *stack_1 && *stack_2)
	{
		ft_lstadd_back(stack_1, ft_lstnew((*stack_1)->value));
		ft_lstdelfirst(stack_1);
		ft_lstadd_back(stack_2, ft_lstnew((*stack_2)->value));
		ft_lstdelfirst(stack_2);
		write(1, "rr\n", 3);
	}
}
