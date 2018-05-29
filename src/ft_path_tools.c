/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:18:21 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/29 20:28:26 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_addprev(t_list **prev, char *rnm)
{
	t_list *nlst;

	if (!(nlst = ft_lstnew(rnm, ft_strlen(rnm))))
		return (0);
	ft_lstadd(prev, nlst);
	return (1);
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

int		ft_inpath(t_list *prev, char *rnm)
{
	while (prev)
	{
		if (ft_strcmp(prev->content, rnm) == 0)
			return (1);
		prev = prev->next;
	}
	return (0);
}

void	ft_lstfreeone(t_list **lst)
{
	t_list *nlst;

	nlst = (*lst)->next;
	ft_strdel((char**)&(*lst)->content);
	free(*lst);
	*lst = nlst;
}
