/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:51:58 by ljerinec          #+#    #+#             */
/*   Updated: 2023/01/26 14:46:26 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	error(char **input_list)
{
	int	i;

	i = 0;
	// free(input_list);
	while (i < array_len(input_list))
		free(input_list[i++]);
	write(1, "Error\n", 6);
	exit(1);
}
