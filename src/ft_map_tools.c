/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:18:26 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/29 16:42:04 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_findroom(char *s, t_rooms **crm, t_rooms **rooms)
{
	t_rooms	*tmp;

	if (!*rooms)
		return ;
	tmp = *rooms;
	while (tmp)
	{
		if (ft_strcmp(s, tmp->name) == 0)
			break ;
		tmp = tmp->next;
	}
	*crm = tmp;
}

int		ft_strlnk(t_rooms *room, t_links *links, char **s)
{
	char	*rnm;

	while (links)
	{
		if (ft_strcmp(room->name, links->r1) == 0 ||
				ft_strcmp(room->name, links->r2) == 0)
		{
			rnm = (ft_strcmp(room->name, links->r1) == 0) ? links->r2
					: links->r1;
			if (!(rnm = ft_strjoin(rnm, ",")))
				return (0);
			if (!(*s = ft_strjoinfree(*s, *s, rnm)))
				return (0);
			ft_strdel(&rnm);
		}
		links = links->next;
	}
	return (1);
}
