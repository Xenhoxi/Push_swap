/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:38:42 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/09 23:49:58 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

int	main(int argc, char **argv)
{
	t_list_data	stack_1;
	t_list_data	stack_2;

	init_list(&stack_1);
	init_list(&stack_2);
	// system("leaks push_swap");
	set_stack_1(argc, argv, &stack_1);
	printf("%s gnl\n", get_next_line(STDOUT_FILENO));
	free_linked_list(&stack_1, &stack_2);
	return (0);
}
