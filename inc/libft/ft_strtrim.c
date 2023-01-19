/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:39:09 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/19 19:50:19 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr((char *)set, s1[0]))
		s1++;
	end = ft_strlen(s1) - 1;
	while (end > 0 && ft_strrchr((char *)set, s1[end]))
		end--;
	return (ft_substr(s1, 0, (end + 1)));
}
