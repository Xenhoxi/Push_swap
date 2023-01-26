/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:23 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/26 02:30:36 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	push_back(t_stack *stack, int new_value)
{
	while (stack->next)
		stack = stack->next;
	stack->next = malloc(sizeof(t_stack));
	stack = stack->next;
	stack->value = new_value;
}

int	array_len(char **argv)
{	
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_first;
	int		len_args;
	int		i;

	i = 0;
	len_args = array_len(argv);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = ft_atoi(argv[i]);
	stack_first = stack;
	while (++i < argc || i < len_args - 1)
		push_back(stack, ft_atoi(argv[i]));
	return (stack_first);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack			*stack1;

	if (checking(argc, argv))
	{
		write(1, "Ok !\n", 5);
		if (argc <= 1)
			error();
		if (argc == 2)
			stack1 = fill_stack(argc - 1, ft_split(argv[1], ' '));
		if (argc > 2)
			stack1 = fill_stack(argc - 1, &argv[1]);
		print_stack(stack1);
	}
	// system("leaks a.out");
	return (0);
}

// Faire en sorte que mes piles soit circulaire et reversible
// Trop de fonctinos dans le checking.c
// Coder les fonctions de modifications des piles :
// sa : Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
// sb : Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
// ss : sa et sb en même temps.
// pa : Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
// pb : Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
// ra : Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
// rb : Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
// rr : ra et rb en même temps.
// rra : Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
// rrb : Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier. 
// rrr : rra et rrb en même temps.
