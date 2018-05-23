/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:40:44 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/23 16:21:50 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlist;
	t_list *tmp;

	nlist = NULL;
	tmp = NULL;
	while (lst)
	{
		if (nlist == NULL)
		{
			nlist = f(lst);
			tmp = nlist;
		}
		else
		{
			nlist->next = f(lst);
			nlist = nlist->next;
		}
		lst = lst->next;
	}
	nlist = tmp;
	return (nlist);
}
