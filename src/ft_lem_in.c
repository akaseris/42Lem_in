/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:26:36 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/29 20:18:26 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_rooms *rooms;
	t_links *links;
	t_list	*prev;

	rooms = NULL;
	links = NULL;
	prev = NULL;
	if (!ft_getinp(&rooms, &links) || !ft_createmap(&rooms, &links)
		|| !ft_findpaths(&rooms, &prev))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	//ft_move(&rooms, paths);
	/*
	while (paths)
	{
		ft_printf("%s\n", paths->content);
		paths = paths->next;
	}
	while (rooms)
	{
		ft_printf("%s, %d, %d, %d\n", rooms->name, rooms->pos, rooms->x, rooms->y);
		rooms = rooms->next;
	}
	while (links)
	{
		ft_printf("%s, %s\n", links->r1, links->r2);
		links = links->next;
	}*/
	// while (rooms)
	// {
	// 	int i = 0;
	// 	//map = map->next[0]->next[0];
	// 	ft_printf("%s, %d, %d, %d, %d\n", rooms->name, rooms->full, rooms->pos, rooms->x, rooms->y);
	// 	while (rooms->links[i])
	// 	{
	// 		ft_printf("***%s, %d, %d, %d, %d\n", rooms->links[i]->name, rooms->links[i]->full, rooms->links[i]->pos, rooms->links[i]->x, rooms->links[i]->y);
	// 		i++;
	// 	}
	// 	rooms = rooms->next;
	// }
	return (0);
}
