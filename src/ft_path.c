/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:08:34 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/02 15:45:37 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_stpt(t_rooms **crm, t_rooms **nrm)
{
	if (!((*nrm)->path = ft_strjoinfree((*nrm)->path, (*nrm)->name, ",")))
		return (0);
	if (!((*nrm)->path = ft_strjoinfree((*nrm)->path, (*nrm)->path,
		(*crm)->path)))
		return (0);
	return (1);
}

static int	ft_paths(t_list *arrlist)
{
	int		j;
	t_list	*tmp;
	t_list	*arr;
	t_rooms	*rm;

	tmp = NULL;
	arr = arrlist;
	while (arr)
	{
		j = -1;
		rm = ((t_rooms*)arr->content);
		while (rm->links && rm->links[++j])
		{
			if (rm->links[j]->check == 1)
				continue;
			if (!ft_stpt(&rm, &rm->links[j]) || !ft_addarr(&tmp, &rm->links[j]))
				return (ft_freearr(&arrlist, &tmp, 0));
			if (rm->links[j]->pos == 1)
				return (ft_freearr(&arrlist, &tmp, 1));
			rm->links[j]->check = 1;
		}
		arr = arr->next;
	}
	ft_freearr(&arrlist, NULL, 1);
	return ((!tmp) ? 0 : ft_paths(tmp));
}

int			ft_findpaths(t_rooms **rooms)
{
	t_rooms	*st;
	t_list	*arr;

	arr = NULL;
	ft_findends(&st, rooms, 0);
	free(st->path);
	if (!(st->path = ft_strdup(st->name)))
		return (0);
	st->check = 1;
	if (!ft_addarr(&arr, &st))
		return (0);
	if (!ft_paths(arr))
		return (0);
	return (1);
}
