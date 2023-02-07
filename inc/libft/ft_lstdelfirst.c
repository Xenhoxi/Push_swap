/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:45:19 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/07 13:19:56 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelfirst(t_list **lst)
{
	t_list	*temp;

	temp = (*lst)->next;
	if (*lst)
		free(*lst);
	temp->prev = 0;
	*lst = temp;
}
