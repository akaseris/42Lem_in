/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:23:43 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/29 18:07:48 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_addlinks(t_rooms **crm, t_rooms **rooms, char **s)
{
	t_rooms	*room;
	char	**rnms;
	int		i;

	room = *rooms;
	if (!(rnms = ft_strsplit(*s, ',')))
		return (0);
	i = 0;
	while (rnms[i])
		i++;
	if (!((*crm)->links = (t_rooms **)malloc(sizeof(*crm) * (i + 1))))
		return (0);
	i = 0;
	while (rnms[i])
	{
		ft_findroom(rnms[i], &room, rooms);
		(*crm)->links[i] = room;
		i++;
	}
	(*crm)->links[i] = NULL;
	return (1);
}

static int	ft_fillmap(t_rooms **rooms, t_links *links, int ants)
{
	t_rooms *tmp;
	char	*s;

	tmp = *rooms;
	while (tmp)
	{
		s = ft_strnew(0);
		if (!ft_strlnk(tmp, links, &s))
			return (0);
		if (!ft_addlinks(&tmp, rooms, &s))
			return (0);
		ft_strdel(&s);
		tmp->full = (tmp->pos == 0) ? ants : 0;
		tmp = tmp->next;
	}
	return (1);
}

int			ft_createmap(t_rooms **rooms, t_links **links)
{
	int		ants;
	t_rooms	*tmp;

	if (!*links || !*rooms || (*rooms)->pos != -1)
		return (0);
	ants = (*rooms)->full;
	tmp = *rooms;
	*rooms = (*rooms)->next;
	free(tmp->name);
	free(tmp);
	if (!ft_fillmap(rooms, *links, ants))
		return (0);
	return (1);
}
