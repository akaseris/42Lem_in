/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:39:57 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/31 23:33:58 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int ft_strprint(int ant, char *name, int *k)
{
	*k = *k + 1;
	if (*k == 1)
		return (ft_printf("\nL%d-%s", ant, name));
	else
		return (ft_printf(" L%d-%s", ant, name));
}

int		ft_moveone(t_rooms **crm, t_rooms **nrm, int ants, int *k)
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
	return (ft_strprint(ant, (*nrm)->name, k));
}

int		ft_moveants(t_rooms **en, t_rooms **rooms, char **split)
{
	int		ants;
	int		j;
	int		k;
	t_rooms	*crm;
	t_rooms	*nrm;

	ft_findends(&crm, rooms, 0);
	ants = crm->full;
	while ((*en)->full != ants)
	{
		j = 0;
		k = 0;
		while (split[j + 1])
		{
			ft_findroom(split[j + 1], &crm, rooms);
			ft_findroom(split[j], &nrm, rooms);
			if (!ft_moveone(&crm, &nrm, ants, &k))
				return (0);
			j++;
		}
	}
	ft_putstr("\n");
	return (1);
}

int		ft_move(t_rooms **rooms)
{
	t_rooms	*end;
	char	**split;

	ft_findends(&end, rooms, 1);
	if (!(split = ft_strsplit(end->path, ',')))
		return (0);
	if (!(ft_moveants(&end, rooms, split)))
		return (ft_freesplit(split, 0));
	return (ft_freesplit(split, 1));
}
