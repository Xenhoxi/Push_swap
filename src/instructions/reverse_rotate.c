/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:56 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 14:51:15 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	rra(t_list_data *stack)
{
	t_list	**stack_1;

	stack_1 = &stack->first;
	if (stack_1 && *stack_1)
	{
		ft_lstadd_front(stack_1, ft_lstnew(ft_lstlast((*stack_1))->value));
		ft_lstdellast(*stack_1);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list_data *stack)
{
	t_list	**stack_2;

	stack_2 = &stack->first;
	if (stack_2 && *stack_2)
	{
		ft_lstadd_front(stack_2, ft_lstnew(ft_lstlast((*stack_2))->value));
		ft_lstdellast(*stack_2);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list_data *stack__1, t_list_data *stack__2)
{
	t_list	**stack_1;
	t_list	**stack_2;

	stack_1 = &stack__1->first;
	stack_2 = &stack__2->first;
	if (stack_1 && stack_2 && *stack_1 && *stack_2)
	{
		ft_lstadd_front(stack_1, ft_lstnew(ft_lstlast((*stack_1))->value));
		ft_lstdellast(*stack_1);
		ft_lstadd_front(stack_2, ft_lstnew(ft_lstlast((*stack_2))->value));
		ft_lstdellast(*stack_2);
		write(1, "rrr\n", 4);
	}
}
