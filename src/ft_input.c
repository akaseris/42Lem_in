/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:20:54 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/23 17:34:25 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_checkends(char *s)
{
	if (s[0] == '#' && s[1] == '#')
	{
		if (ft_strcmp(s, "##start") == 0)	
			return (1);
		else if (ft_strcmp(s, "##end") == 0)
			return (2);
	}
	return (0);
}

int		ft_checkant(char *s, t_rooms **rooms, t_links **links)
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
	(*rooms)->x = ft_atoi(s);
	return (1);
}

int		ft_validline(char *s, t_rooms **rooms, t_links **links)
{
	char		**split;
	int			i;
	static int	sten;

	if (s[0] == '#')
	{
		sten = ft_checkends(s);
		return (1);
	}
	else
	{
		if (ft_strchr(s, ' '))
			return (ft_checkroom(s, rooms, links, sten));
		else if (ft_strchr(s, '-'))
			return (ft_checklink(s, links));
	}
	return (ft_checkant(s, rooms, links));
}

int		ft_getinp(t_rooms **rooms, t_links **links)
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