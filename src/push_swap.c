/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 00:45:48 by ljerinec         ###   ########.fr       */
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
	system("leaks push_swap");
	return (0);
}

void	choose_sorting_algo(t_list *stack)
{
	int	stack_len;

	stack_len = stacklen(stack);
	if (stack_len == 2)
		sort("Le nombre de nombres dans la piles et la fonction choisie quelle algo")
}

/*
	Suite ...
	donne le nombres d'items de la pile et la fonction choisie quelle algo
	ou 
	la fonction choisie directement le bon algo avec des elseif
	Algo de tri pour 3 nombres
	Algo de tri pour 5 nombres
	Algo de tri pour 100 nombres
	Algo de tri pour 500 nombres
*/
