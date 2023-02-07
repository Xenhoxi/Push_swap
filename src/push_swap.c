/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 00:22:18 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_1;
	t_list	*stack_2;

	stack_1 = NULL;
	stack_2 = NULL;
	set_stack_1(argc, argv, &stack_1);
	ranking(stack_1);
	print_rank(stack_1);
	printf("Stack 1 :\n");
	print_list(stack_1);
	printf("\nStack 2 :\n");
	print_list(stack_2);
	// print_list(stack_1);
	// system("leaks push_swap");
	return (0);
}

/*
	Suite ...
	Algo de tri pour 3 nombres
	Algo de tri pour 5 nombres
	Algo de tri pour 100 nombres
	Algo de tri pour 500 nombres
*/
