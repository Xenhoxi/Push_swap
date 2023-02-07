/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/07 18:15:40 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	set_stack_1(int argc, char **argv, t_list **stack)
{
	char			**input_list;

	if (checking(argc, argv))
	{
		write(1, "Ok !\n", 5);
		if (argc == 2)
		{
			input_list = ft_split(argv[1], ' ');
			fill_stack_split(array_len(input_list), input_list, stack);
		}
		if (argc > 2)
			fill_stack_argv(argc, argv, stack);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_1;
	t_list	*stack_2;

	stack_1 = NULL;
	stack_2 = NULL;
	set_stack_1(argc, argv, &stack_1);
	printf("Operations :\n");
	pb(&stack_1, &stack_2);
	pb(&stack_1, &stack_2);
	pb(&stack_1, &stack_2);
	printf("\n");
	printf("Stack 1 :\n");
	print_list(stack_1);
	printf("Stack 2 :\n");
	print_list(stack_2);
	rra(&stack_1);
	rrb(&stack_2);
	printf("\n");
	printf("Stack 1 :\n");
	print_list(stack_1);
	printf("Stack 2 :\n");
	print_list(stack_2);
	return (0);
}

/*
	Coder les fonctions de modifications des piles :
	ra : Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
	rb : Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
	rr : ra et rb en même temps.
	rra : Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
	rrb : Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier. 
	rrr : rra et rrb en même temps.
*/
