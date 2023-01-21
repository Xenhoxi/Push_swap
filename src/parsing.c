/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:49:09 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/21 01:10:37 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

// bool	check_argv()
// {
// 	//Is_digit()
//	//atoi
// 	//Is_int()
// 	//No_multiple_same_numbers()
// }

int	parsing(int argc, char **argv)
{
	char	**numbers_list;
	int		i;

	i = 0;
	if (argc == 2)
	{
		numbers_list = ft_split(argv[1], ' ');
		while (numbers_list[i])
			printf("%s\n", numbers_list[i++]);
		//Check_argv()
		return (0);
	}
	return (1);
}
