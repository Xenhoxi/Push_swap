/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/30 00:28:23 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

t_stack	*set_stack_1(int argc, char **argv)
{
	char			**input_list;

	if (checking(argc, argv))
	{
		write(1, "Ok !\n", 5);
		if (argc == 2)
		{
			input_list = ft_split(argv[1], ' ');
			return (fill_stack_split(array_len(input_list), input_list));
		}
		if (argc > 2)
			return (fill_stack_argv(argc, argv));
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_1;

	stack_1 = set_stack_1(argc, argv);
	print_stack(stack_1);
	write(1, "\n", 1);
	print_reverse_stack(stack_1);
	printf("Taille stack : %d\n ", stacklen(stack_1));
	return (0);
}

/*
	Essayer si un pointeur simple ne fait pas deja ce que je veux faire en dessous.
	utiliser un pointeur sur pointeur pour toujours partir de meme endroit
	Coder les fonctions de modifications des piles :
	sa : Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
	sb : Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
	ss : sa et sb en même temps.
	pa : Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
	pb : Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
	ra : Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
	rb : Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
	rr : ra et rb en même temps.
	rra : Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
	rrb : Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier. 
	rrr : rra et rrb en même temps.
*/
