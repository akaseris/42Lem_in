/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:20:54 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/31 22:18:12 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_checkends(char *s, t_rooms **rooms, t_links **links)
{
	if (s[0] == '#' && s[1] == '#')
	{
		if (!*rooms || *links)
			return (-1);
		if (ft_strcmp(s, "##start") == 0)
			return (1);
		else if (ft_strcmp(s, "##end") == 0)
			return (2);
	}
	return (0);
}

static int	ft_checkant(char *s, t_rooms **rooms, t_links **links)
{
	int		i;

	if (*links || *rooms)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && !ft_strchr("+-", s[0]))
			return (0);
		i++;
	}
	if (!(*rooms = (t_rooms *)malloc(sizeof(**rooms))))
		return (0);
	(*rooms)->pos = -1;
	(*rooms)->full = ft_atoi(s);
	if (!((*rooms)->name = ft_strdup("antnum")))
		return (0);
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
	ft_putstr("\n");
	ft_strdel(&tmp);
	return (1);
}
