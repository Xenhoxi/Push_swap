/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:35:09 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/24 17:15:56 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	u;
	size_t	origindest;

	u = 0;
	if (!dstsize)
		return (ft_strlen(src));
	origindest = ft_strlen(dst);
	i = ft_strlen(dst);
	if (!dst)
		return (0);
	if (dstsize == 0 || dstsize <= origindest)
		return (dstsize + ft_strlen(src));
	while (src[u] && u < (dstsize - origindest - 1))
		dst[i++] = src[u++];
	dst[i] = '\0';
	return (origindest + ft_strlen(src));
}
