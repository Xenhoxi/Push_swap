/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/06 14:04:30 by ljerinec         ###   ########.fr       */
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
	stackfirst(&stack_1);
	print_stack(stack_1);
	push_back(&stack_2, 12);
	print_stack(stack_2);
	return (0);
}

/*
	Essayer si un pointeur simple ne fait pas deja ce que je veux faire en dessous.
	utiliser un pointeur sur pointeur pour toujours partir du meme endroit
	Coder les fonctions de modifications des piles :
	pa : Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
	pb : Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
	ra : Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
	rb : Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
	rr : ra et rb en même temps.
	rra : Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
	rrb : Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier. 
	rrr : rra et rrb en même temps.
*/
