/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:51:58 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/08 00:19:50 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pushswap.h"

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
	free(int_array);
	return (0);
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	array_len(char **argv)
{	
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
