/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:19:10 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/21 19:13:20 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*memalloc;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (0);
	memalloc = malloc(ft_strlen(s) + 1);
	if (!memalloc)
		return (NULL);
	while (s[i])
	{
		memalloc[i] = (int)(*f)(i, s[i]);
		i++;
	}
	memalloc[i] = '\0';
	return (memalloc);
}
