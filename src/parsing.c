/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:49:09 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/23 04:47:54 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	only_digit(char	**input_list, int argc)
{
	int	i;
	int	u;

	i = 1;
	u = 0;
	while (i <= argc)
	{
		while (input_list[i])
		{
			if ((input_list[i][u] >= '0' && input_list[i][u] <= '9')
				|| input_list[i][u] == '-' || input_list[i][u] == ' ')
				u++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_argv(char	**input_list, int argc)
{
	int	checker;

	checker = 0;
	if (only_digit(input_list, argc))
		checker = 1;
	// atoi
	// Is_int()
	// No_multiple_same_numbers()
	return (checker);
}

int	parsing(int argc, char **argv)
{
	char	**input_list;

	if (argc <= 1)
		error();
	if (argc == 2)
	{
		input_list = ft_split(argv[1], ' ');
		if (check_argv(input_list, argc))
			return (1);
		else
			error();
	}
	if (argc > 2)
	{
		
	}
	return (0);
}
