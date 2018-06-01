/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:20:54 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/01 19:21:00 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_checkends(char *s, t_rooms **rooms, t_links **links)
{
	t_rooms *tmp;

	tmp = NULL;
	if (s[0] == '#' && s[1] == '#')
	{
		if (ft_strcmp(s, "##start") == 0 || ft_strcmp(s, "##end") == 0)
		{
			if (!*rooms || *links)
				return (-1);
			ft_findends(&tmp, rooms, 0);
			if (s[2] == 's' && tmp == NULL)
				return (1);
			ft_findends(&tmp, rooms, 1);
			if (s[2] == 'e' && tmp == NULL)
				return (2);
			return (-1);
		}
	}
	return (0);
}

static int	ft_checkant(char *s, t_rooms **rooms, t_links **links)
{
	int		i;

	if (*links || *rooms)
		return (0);
	if ((i = ft_checknum(s)) == -1)
		return (0);
	if (!(*rooms = (t_rooms *)malloc(sizeof(**rooms))))
		return (0);
	(*rooms)->pos = -1;
	(*rooms)->full = ft_atoi(s);
	if (!((*rooms)->name = ft_strdup("antnum")))
		return (0);
	(*rooms)->path = NULL;
	(*rooms)->x = -1;
	(*rooms)->y = -1;
	return (((*rooms)->full < 1) ? 0 : 1);
}

static int	ft_validline(char *s, t_rooms **rooms, t_links **links)
{
	static int	sten;

	ft_putstr(s);
	ft_putstr("\n");
	if (s[0] == '#')
	{
		if (sten != 0)
			return (0);
		sten = ft_checkends(s, rooms, links);
		return ((sten == -1) ? 0 : 1);
	}
	else
	{
		if (ft_strchr(s, ' '))
			return (ft_checkroom(s, rooms, links, &sten));
		else if (ft_strchr(s, '-'))
			return (ft_checklink(s, rooms, links));
	}
	return (ft_checkant(s, rooms, links));
}

int			ft_getinp(t_rooms **rooms, t_links **links)
{
	int		r;
	char	*tmp;

	while ((r = get_next_line(0, &tmp)))
	{
		if (r == 2)
		{
			if (!(ft_validline(tmp, rooms, links)))
			{
				ft_strdel(&tmp);
				return (0);
			}
		}
		else if (r == 1 && tmp[0] != '\0')
		{
			ft_strdel(&tmp);
			return (0);
		}
		ft_strdel(&tmp);
	}
	ft_strdel(&tmp);
	return (1);
}
