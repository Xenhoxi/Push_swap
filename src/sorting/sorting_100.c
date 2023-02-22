/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:29:59 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/23 00:53:25 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_100(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	if (stack_data_1->start_length <= 25)
		sorting_small(stack_data_1, stack_data_2);
	else if (stack_data_1->start_length > 25)
		sorting_big(stack_data_1, stack_data_2);
}
 
void	sorting_small(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	while (stack_data_1->length)
	{
		put_lower_in_first(stack_data_1);
		pb(stack_data_1, stack_data_2);
	}
	while (stack_data_2->length)
		pa(stack_data_1, stack_data_2);
}

void	sorting_big(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	int	i;

	i = 0;
	while (stack_data_1->length > 25)
		pb_25_smallest(stack_data_1, stack_data_2, ++i);
}

void	pb_25_smallest(t_list_data *stack_data_1, t_list_data *stack_data_2, int i)
{
	t_list	*stack_1;
	int	rank_min;
	int	size;

	size = 25;
	stack_1 = stack_data_1->first;
	rank_min = find_lower_rank(stack_data_1);
	while (stack_data_2->length < size * i)
	{
		stack_1 = stack_data_1->first;
		if (stack_1->rank >= rank_min && stack_1->rank < rank_min + size)
			pb(stack_data_1, stack_data_2);
		else
			rotate(stack_data_1, 'a');
	}
}

/*
	tant que +25 dans A push les 25 plus petit dans b
	tri les nombres restants
	apres trie la pile b en recherchant les plus grand, les mettres en p1 et les push dans A (chunk de 25)
	bien joue t'es trop fort
*/

// int	size_of_chunk(t_list_data *stack)
// {
// 	int	size;

// 	size = stack->length / 4;
// 	return (size);
// }

// void	push_chunk(t_list_data *stack_data_1, t_list_data *stack_data_2, int size)
// {
// 	t_list	*stack_1;
// 	int		length_wanted;

// 	stack_1 = stack_data_1->first;
// 	length_wanted = stack_data_1->length - size;
// 	while (stack_data_1->length > length_wanted)
// 	{
// 		if (stack_1->rank < size)
// 			pb(stack_data_1, stack_data_2);
// 		else
// 			rotate(stack_data_1, 'a');
// 	}
// }
