/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:08:34 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/29 21:44:32 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_paths(t_list *arrlist, t_list **prev)
{
	int j;
	char	*s;
	t_list *tmp;
	t_list *arr;

	tmp = NULL;
	arr = arrlist;
	while (arr)
	{
		j = -1;
		while (((t_rooms*)arr->content)->links[++j])
		{
			if (ft_inpath(*prev, ((t_rooms*)arr->content)->links[j]->name))
				continue ;
			s = ft_strnew(0);
			s = ft_strjoinfree(s, s, ((t_rooms*)arr->content)->path);
			s = ft_strjoinfree(s, s, ",");
			((t_rooms*)arr->content)->links[j]->path = ft_strjoinfree(s, s, ((t_rooms*)arr->content)->links[j]->name);
			if (((t_rooms*)arr->content)->links[j]->pos == 1)
				return (1);
			ft_addprev(prev, ((t_rooms*)arr->content)->links[j]->name);
			ft_addarr(&tmp, &((t_rooms*)arr->content)->links[j]);
		}
		arr = arr->next;
	}
	free(arr);
	ft_paths(tmp, prev);
	return (1);
}

int			ft_findpaths(t_rooms **rooms, t_list **prev)
{
	t_rooms *st;
	t_list *arr;

	arr = NULL;
	ft_findends(&st, rooms, 0);
	free(st->path);
	st->path = ft_strdup(st->name);
	ft_addprev(prev, st->name);
	ft_addarr(&arr, &st);
	ft_paths(arr, prev);
	ft_findends(&st, rooms, 1);
	ft_printf("%s\n", st->path);
	return (1);
}
