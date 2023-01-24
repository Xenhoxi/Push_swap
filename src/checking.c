/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:49:09 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/24 02:43:45 by ljerinec         ###   ########.fr       */
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

	i = 0;
	u = 0;
	while (i < argc)
	{
		while (input_list[i][u])
		{
			if ((input_list[i][u] >= '0' && input_list[i][u] <= '9')
				|| input_list[i][u] == '-')
				u++;
			else
				return (0);
		}
		u = 0;
		i++;
	}
	return (1);
}

int	only_int(char **input_list)
{
	int			i;
	long long	number;

	i = 0;
	while (input_list[i])
	{
		number = ft_atoi_2(input_list[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

// int	no_identical_numbers(char **input_list)
// {
	//cree un tableau d'int
	//verifier si deux nombres sont identique a l'interieur du tableau d'int
	//free le tableau d'int
// }

int	check_argv(char	**input_list, int argc)
{
	if (only_digit(input_list, argc))
		if (only_int(input_list))
			// if (no_identical_numbers())
				return (1);
	return (0);
}

int	checking(int argc, char **argv)
{
	char	**input_list;

	if (argc <= 1)
		error();
	if (argc == 2)
	{
		input_list = ft_split(argv[1], ' ');
		if (check_argv(input_list, array_len(input_list)))
			return (1);
		else
			error();
	}
	if (argc > 2)
	{
		input_list = &argv[1];
		if (check_argv(input_list, argc - 1))
			return (1);
		else
			return (0);
	}
	return (0);
}
