/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:47:28 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/25 23:12:58 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*contenu;
	t_list	*list;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	contenu = 0;
	while (lst)
	{
		tmp = f(lst->content);
		list = ft_lstnew(tmp);
		if (!list)
		{
			free(tmp);
			ft_lstclear(&contenu, del);
			return (0);
		}
		ft_lstadd_back(&contenu, list);
		lst = lst->next;
	}
	return (contenu);
}
