/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:49:09 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/01 14:00:38 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

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

int	identical_numbers(long long *int_array, int input_len)
{
	int	i;
	int	u;

	u = 1;
	i = 0;
	while (i < input_len)
	{
		while (u < input_len)
		{
			if (i != u)
			{
				if (int_array[i] == int_array[u])
				{
					free(int_array);
					return (1);
				}
			}
			u++;
		}
		u = i;
		i++;
	}
	// free(int_array);
	return (0);
}

int	check_argv(char	**input_list, int argc)
{
	if (only_digit(input_list, argc))
		if (only_int(input_list))
			return (1);
	return (0);
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
