/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/26 18:00:30 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int	main(int argc, char **argv)
{
	t_list_data	stack_1;
	t_list_data	stack_2;

	init_list(&stack_1);
	init_list(&stack_2);
	set_stack_1(argc, argv, &stack_1);
	ranking(&stack_1);
	if (is_sort(&stack_1))
		exit(1);
	else
		sorting(&stack_1, &stack_2);
	// print_list(stack_1.first, 1);
	// print_list(stack_1.first, 1);
	return (0);
}

void	sorting(t_list_data *stack_1, t_list_data *stack_2)
{
	if (stack_1->length <= 3)
		sorting_3(stack_1);
	else if (stack_1->length <= 5)
		sorting_5(stack_1, stack_2);
	else if (stack_1->length <= 500)
		sorting_100(stack_1, stack_2);
}
