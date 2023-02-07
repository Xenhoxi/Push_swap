/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:48:47 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/07 18:07:24 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdellast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	lst->prev->next = 0;
	lst->prev = 0;
	if (lst->next)
	{
		free(lst->next);
		lst->next = 0;
	}
}
