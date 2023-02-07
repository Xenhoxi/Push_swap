/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:49:09 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 00:21:12 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

void	set_stack_1(int argc, char **argv, t_list **stack)
{
	char	**input_list;
	int		i;	

	i = 0;
	if (checking(argc, argv))
	{
		write(1, "Inputs Ok !\n\n", 14);
		if (argc == 2)
		{
			input_list = ft_split(argv[1], ' ');
			fill_stack_split(array_len(input_list), input_list, stack);
			while (input_list[i])
				free(input_list[i++]);
			free(input_list);
		}
		if (argc > 2)
			fill_stack_argv(argc, argv, stack);
	}
}

int	checking(int argc, char **argv)
{
	char	**input_list;

	if (argc <= 1)
		write(1, "Error\n", 6);
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
			error();
	}
	return (0);
}

int	check_argv(char	**input_list, int argc)
{
	if (only_digit(input_list, argc))
		if (only_int(input_list))
			return (1);
	return (0);
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
				|| (input_list[i][u] == '-' && u == 0))
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
	long long	*numbers;
	int			input_list_len;	

	i = 0;
	input_list_len = array_len(input_list);
	numbers = malloc(sizeof(int) * input_list_len);
	while (input_list[i])
	{
		numbers[i] = ft_atoi_2(input_list[i]);
		if (numbers[i] < INT_MIN || numbers[i] > INT_MAX)
		{
			free(input_list);
			return (0);
		}
		i++;
	}
	if (identical_numbers(numbers, input_list_len))
		return (0);
	return (1);
}
