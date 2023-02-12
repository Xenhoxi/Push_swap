/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/11 20:07:50 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	init_list(t_list_data *stack)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->length = 0;
}

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
	print_list(stack_1.first);
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
	Changer sa et sb pour qu'il intervertisse tout le maillon et non juste la valeur
	Algo de tri pour 5 nombres
	Algo de tri pour 100 nombres
	Algo de tri pour 500 nombres
*/
