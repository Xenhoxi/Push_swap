/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 12:38:02 by ljerinec         ###   ########.fr       */
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
	if (is_sort(stack_1))
	{
		printf("C'est deja Trié chien !\n");
		exit(1);
	}
	sorting(&stack_1, &stack_2);
	printf("Stack 1 :\n");
	print_list(stack_1);
	printf("\nStack 2 :\n");
	print_list(stack_2);
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
	// 	sorting_5(stack_1, stack_2);
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
