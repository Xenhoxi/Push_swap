/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:29:59 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/08 13:51:21 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	sorting_100(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	if (stack_data_1->start_length <= 25)
		sorting_small(stack_data_1, stack_data_2);
	else if (stack_data_1->start_length > 25)
		sorting_bigg(stack_data_1, stack_data_2);
}

void	sorting_small(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	while (stack_data_1->length)
	{
		put_lower_in_first(stack_data_1, 'a');
		pb(stack_data_1, stack_data_2);
	}
	while (stack_data_2->length)
		pa(stack_data_1, stack_data_2);
}

int	define_chunk_size(t_list_data *stack_data_1)
{
	int	size;

	size = stack_data_1->start_length;
	if (stack_data_1->start_length <= 100)
		size = stack_data_1->start_length / 8;
	else if (stack_data_1->start_length <= 150)
		size = stack_data_1->start_length / 10;
	else if (stack_data_1->start_length <= 200)
		size = stack_data_1->start_length / 15;
	else if (stack_data_1->start_length > 400)
		size = stack_data_1->start_length / 20;
	return (size);
}

void	sorting_bigg(t_list_data *stack_data_1, t_list_data *stack_data_2)
{
	int	i;
	int	chunk_size;

	chunk_size = define_chunk_size(stack_data_1);
	i = 0;
	while (stack_data_1->length > chunk_size)
		pb_chunk(stack_data_1, stack_data_2, i++, chunk_size);
	while (stack_data_1->length > 0)
	{
		if (is_sort(stack_data_1))
			break ;
		put_lower_in_first(stack_data_1, 'a');
		pb(stack_data_1, stack_data_2);
	}
	while (stack_data_1->first->rank == (stack_data_2->first->rank) + 1)
		pa(stack_data_1, stack_data_2);
	while (stack_data_2->length)
	{
		rotate_a_or_put_higher(stack_data_1, stack_data_2);
		// put_higher_in_first(stack_data_2, 'b');
		// pa(stack_data_1, stack_data_2);
		print_list(stack_data_1, 1);
		print_list(stack_data_2, 2);
	}
}
// fonctions qui va trouver la position ou mettre la premiere valeur de la pile 2 pour que la pile 1 soit triee
void	find_good_place(t_list_data *s_data_1, t_list_data *s_data_2)
{
	// t_list	*s_1;
	t_list	*s_2;
	int		pos;

	// s_1 = s_data_1->first;
	s_2 = s_data_2->first;
	pos = count_find_place(s_data_1, s_data_2);
	printf("pos = %d\n", pos);
	if (find_lower_rank(s_data_1) < s_2->rank)
	{
		while (pos-- > 0)
			rev_rotate(s_data_1, 'a');
		pa(s_data_1, s_data_2);
	}
	else if (find_lower_rank(s_data_1) > s_2->rank)
	{
		put_lower_in_first(s_data_1, 'a');
		pa(s_data_1, s_data_2);
	}
	else
	{
		pa(s_data_1, s_data_2);
	}
	// if (!is_sort(s_data_1))
	// 	swap(s_data_1, 'a');
	// while (s_1->rank < s_2->rank && stacklast(s_data_1->first)->rank < s_2->rank)
	// {
	// 	if (count_find_place(s_data_1, s_data_2) >= s_data_1->length / 2)
	// 		rev_rotate(s_data_1, 'a');
	// 	else
	// 		rotate(s_data_1, 'a');
	// }
}
// fonctions qui va compter le nombre de rotation pour trouver la bonne place
int	count_find_place(t_list_data *s_data_1, t_list_data *s_data_2)
{
	int		i;
	t_list	*s_1;
	t_list	*s_2;

	i = 0;
	s_1 = s_data_1->first;
	s_2 = s_data_2->first;
	while (s_1 && s_1->next)
	{
		if (s_1->rank > s_2->rank && find_lower_rank(s_data_1) == s_1->rank)
			break ;
		else
			i++;
		s_1 = s_1->next;
	}
	return (i);
}

int	count_put_higher(t_list_data *stack_data)
{
	int	rank_max;
	int	pos;

	rank_max = find_higher_rank(stack_data);
	pos = find_eazy_ways(stack_data, rank_max);
	return (pos);
}
// code a function to count the number of rotations tu put the higher rank in first position
void	rotate_a_or_put_higher(t_list_data *s_data_1, t_list_data *s_data_2)
{
	// if (s_data_1->length < s_data_1->start_length / 2)
		find_good_place(s_data_1, s_data_2);
	// else
	// {
	// 	printf("--------------------------------------------------------------------------------------------------------\n");
	// 	if (!is_sort(s_data_1))
	// 		put_lower_in_first(s_data_1, 'a');
	// 	put_higher_in_first(s_data_2, 'b');
	// 	pa(s_data_1, s_data_2);
	// }
}

void	pb_chunk(t_list_data *s_data_1, t_list_data *s_data_2, int i, int size)
{
	t_list	*s_1;
	int		min_r;

	min_r = find_lower_rank(s_data_1);
	s_1 = s_data_1->first;
	while (s_data_2->length < size * 2 * i && s_data_1->length > 1)
	{
		s_1 = s_data_1->first;
		if (s_1->rank == s_data_1->start_length)
			rotate(s_data_1, 'a');
		else if (s_1->rank >= min_r + size && s_1->rank < min_r + size * 2)
			pb(s_data_1, s_data_2);
		else if (s_1->rank >= min_r && s_1->rank < min_r + size)
		{
			pb(s_data_1, s_data_2);
			rotate(s_data_2, 'b');
		}
		else if (s_data_2->length == s_data_1->start_length)
			break ;
		else
			rotate(s_data_1, 'a');
	}
}
