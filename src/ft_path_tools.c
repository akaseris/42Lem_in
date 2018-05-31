/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:18:21 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/31 23:44:48 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_freearr(t_list **lst, int ret)
{
	t_list *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		//free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	return (ret);
}

int		ft_addarr(t_list **arr, t_rooms **rm)
{
	t_list *nlst;

	if (!(nlst = (t_list*)malloc(sizeof(*nlst))))
		return (0);
	nlst->content = *rm;
	nlst->content_size = 1;
	ft_lstadd(arr, nlst);
	return (1);
}

void	ft_findends(t_rooms **start, t_rooms **rooms, int ind)
{
	t_rooms *tmp;

	tmp = *rooms;
	while (tmp)
	{
		if (tmp->pos == ind)
		{
			*start = tmp;
			break ;
		}
		tmp = tmp->next;
	}
}

void	ft_lstfreeone(t_list **lst)
{
	t_list *nlst;

	nlst = (*lst)->next;
	ft_strdel((char**)&(*lst)->content);
	free(*lst);
	*lst = nlst;
}
