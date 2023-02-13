/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/13 13:33:03 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int	main(int argc, char **argv)
{
	t_list_data	stack_1;
	t_list_data	stack_2;

	init_list(&stack_1, 'a');
	init_list(&stack_2, 'b');
	set_stack_1(argc, argv, &stack_1);
	ranking(&stack_1);
	// if (is_sort(&stack_1))
	// 	exit(1);
	// else
	// 	sorting(&stack_1, &stack_2);
	push(&stack_2, &stack_1);
	push(&stack_1, &stack_2);
	push(&stack_2, &stack_1);
	push(&stack_1, &stack_2);
	push(&stack_1, &stack_2);
	printf("---\n");
	print_list(stack_2.first);
	return (0);
}

void	sorting(t_list_data *stack_1, t_list_data *stack_2)
{
	(void) stack_2;
	if (stack_1->length <= 3)
		sorting_3(stack_1);
	else if (stack_1->length <= 5)
		sorting_5(stack_1, stack_2);
	// else if (stack_len <= 100)
	// 	sorting_100(stack_1, stack_2);
	// else if (stack_len <= 500)
	// 	sorting_500(stack_1, stack_2);
}

/*
	Suite ...
	Algo de tri pour 100 nombres
	Algo de tri pour 500 nombres
*/
