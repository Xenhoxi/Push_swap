/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:06:35 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/01 17:23:47 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t	i;
	char	*buffer_pointeur;

	buffer_pointeur = (char *)b;
	i = 0;
	while (i < len)
	{
		buffer_pointeur[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
