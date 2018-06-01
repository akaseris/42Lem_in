/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:26:36 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/01 22:06:47 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_freeall(t_rooms **rms, t_links **lnk)
{
	if (*rms)
		ft_freerooms(rms);
	if (*lnk)
		ft_freelinks(lnk);
}

int			main(void)
{
	t_rooms *rooms;
	t_links *links;

	rooms = NULL;
	links = NULL;
	if (!ft_getinp(&rooms, &links) || !ft_createmap(&rooms, &links)
		|| !ft_findpaths(&rooms) || !ft_move(&rooms))
	{
		ft_freeall(&rooms, &links);
		ft_printf("ERROR\n");
		return (0);
	}
	ft_freeall(&rooms, &links);
	return (0);
}
