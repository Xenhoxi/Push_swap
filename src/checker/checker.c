/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:38:42 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/11 01:47:16 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	check_output(char *line, t_list_data *stack_1, t_list_data *stack_2)
{
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		swap(stack_1, ' ');
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		swap(stack_2, ' ');
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		ss(stack_1, stack_2);
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		pa(stack_1, stack_2, 0);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		pb(stack_1, stack_2, 0);
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		rotate(stack_1, ' ');
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		rotate(stack_2, ' ');
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		rr(stack_1, stack_2, 0);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		rev_rotate(stack_1, ' ');
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		rev_rotate(stack_2, ' ');
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		rrr(stack_1, stack_2, 0);
	else
		(write(2, "Error\n", 6), exit(1));
}

int	main(int argc, char **argv)
{
	t_list_data	stack_1;
	t_list_data	stack_2;
	char		*line;

	init_list(&stack_1);
	init_list(&stack_2);
	set_stack_1(argc, argv, &stack_1);
	ranking(&stack_1);
	line = get_next_line(0);
	while (line)
	{
		check_output(line, &stack_1, &stack_2);
		if (is_sort(&stack_1) && stack_2.length == 0)
			break ;
		line = get_next_line(0);
	}
	if (is_sort(&stack_1) && stack_2.length == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_linked_list(&stack_1, &stack_2);
	return (0);
}
