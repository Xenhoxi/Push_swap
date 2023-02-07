/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:49:55 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/06 23:16:19 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdellast(t_list **lst)
{
	while ((*lst)->next->next)
		(*lst) = (*lst)->next;
	if ((*lst)->next)
		free((*lst)->next);
	(*lst)->next = 0;
}