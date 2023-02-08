/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 14:36:13 by ljerinec         ###   ########.fr       */
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
	ranking(stack_1.first);
	if (is_sort(stack_1.first))
	{
		printf("C'est deja Trié chien !\n");
		exit(1);
	}
	sorting(&stack_1.first, &stack_2.first); // changer pour le t_list_data
	printf("Stack 1 :\n");
	print_list(stack_1.first);
	printf("Stack 2 :\n");
	print_list(stack_2.first);
	pb(&stack_1, &stack_2);
	pb(&stack_1, &stack_2);
	rb(&stack_1);
	printf("Stack 1 :\n");
	print_list(stack_1.first);
	printf("Stack 2 :\n");
	print_list(stack_2.first);
	printf("Nombre d'element stack 1 : %d\n", stack_1.length);
	printf("Nombre d'element stack 2 : %d\n", stack_2.length);
	// system("leaks push_swap");
	return (0);
}

void	sorting(t_list **stack_1, t_list **stack_2)
{
	int	stack_len;

	stack_len = stacklen(*stack_1);
	(void) stack_2;
	printf("Nombres d'element dans la stack 1 : %d\n", stack_len);
	// if (stack_len <= 3)
		// sorting_3(stack_1);
	// else if (stack_len <= 5)
		// sorting_5(stack_1, stack_2);
	// else if (stack_len <= 100)
	// 	sorting_100(stack_1, stack_2);
	// else if (stack_len <= 500)
	// 	sorting_500(stack_1, stack_2);
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
