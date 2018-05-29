/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:39:57 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/29 17:14:32 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_joinstring(char *name, int ant, char **s)
{
	char *tmp;
	int i;

	i = ((int)ft_strlen(*s) - 1 == -1) ? 0 : (int)ft_strlen(*s) - 1;
	if (**s && s[0][i] != '\n')
	{
		if (!(*s = ft_strjoinfree(*s, *s, " ")))
			return (0);
	}
	if (!(*s = ft_strjoinfree(*s, *s, "L")))
		return (0);
	if (!(tmp = ft_itoa(ant)))
		return (0);
	if (!(*s = ft_strjoinfree(*s, *s, tmp)))
		return (0);
	if (!(*s = ft_strjoinfree(*s, *s, "-")))
		return (0);
	if (!(*s = ft_strjoinfree(*s, *s, name)))
		return (0);
	return (1);
}

int		ft_moveone(t_rooms **crm, t_rooms **nrm, char **s, int ants)
{
	int		ant;

	if (((*nrm)->full != 0 || (*crm)->full == 0) && ((*nrm)->pos != 1
		|| (*crm)->full == 0))
		return (1);
	if ((*crm)->pos == 0)
	{
		(*nrm)->full = ants - (*crm)->full + 1;
		(*crm)->full--;
		ant = (*nrm)->full;
	}
	else if ((*nrm)->pos == 1)
	{
		(*nrm)->full++;
		ant = (*crm)->full;
		(*crm)->full = 0;
	}
	else
	{
		(*nrm)->full = (*crm)->full;
		(*crm)->full = 0;
		ant = (*nrm)->full;
	}
	if (!(ft_joinstring((*nrm)->name, ant, s)))
		return (0);
	return (1);
}

int		ft_moveants(t_rooms **en, t_rooms **rooms, t_list *paths, char **s)
{
	int		ants;
	t_list	*tmp;
	t_rooms	*crm;
	t_rooms	*nrm;

	ft_findends(&crm, rooms, 0);
	ants = crm->full;
	while ((*en)->full != ants)
	{
		tmp = paths;
		while (tmp->next)
		{
			ft_findroom((char*)tmp->next->content, &crm, rooms);
			ft_findroom((char*)tmp->content, &nrm, rooms);
			if (!(ft_moveone(&crm, &nrm, s, ants)))
				return (0);
			tmp = tmp->next;
		}
		*s = ((*en)->full != ants) ? ft_strjoinfree(*s, *s, "\n") : *s;
	}
	return (1);
}

int		ft_move(t_rooms **rooms, t_list *paths)
{
	char	*str;
	t_rooms	*end;

	ft_findends(&end, rooms, 1);
	str = ft_strnew(0);
	if (!(ft_moveants(&end, rooms, paths, &str)))
		return (0);
	ft_printf("%s\n", str);
	return (1);
}
