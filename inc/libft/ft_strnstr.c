/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:07:07 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/04 03:07:07 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	u;
	size_t	breakpoint;

	i = 0;
	u = 0;
	breakpoint = 0;
	if (!haystack && !len)
		return (0);
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i] == needle[u] && i < len)
		{
			if (needle[u + 1] == '\0')
				return ((char *)&haystack[breakpoint]);
			u++;
			i++;
		}
		breakpoint++;
		i = breakpoint;
		u = 0;
	}
	return (0);
}
