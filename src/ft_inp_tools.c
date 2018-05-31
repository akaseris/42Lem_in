/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inp_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:26:37 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/31 22:12:21 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_addroom(t_rooms **rooms, char **name, int *coord, int *sten)
{
	t_rooms *nrm;
	t_rooms *tmp;

	if (!*rooms || **name == 'L' || **name == '#')
		return (0);
	if (!(nrm = (t_rooms *)malloc(sizeof(*nrm))))
		return (0);
	nrm->name = *name;
	nrm->path = ft_strnew(0);
	if (!nrm->path)
		return (0);
	nrm->x = coord[0];
	nrm->y = coord[1];
	free(coord);
	nrm->full = 0;
	nrm->check = 0;
	nrm->pos = (*sten == 1 || *sten == 2) ? *sten - 1 : 2;
	nrm->next = NULL;
	*sten = (*sten == 1 || *sten == 2) ? 0 : *sten;
	tmp = *rooms;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nrm;
	return (1);
}

static int	ft_addlink(char **s, t_links **links)
{
	t_links *nlnk;
	t_links *tmp;

	if (!(nlnk = (t_links *)malloc(sizeof(*nlnk))))
		return (0);
	nlnk->r1 = ft_strdup(s[0]);
	nlnk->r2 = ft_strdup(s[1]);
	ft_freesplit(s, 1);
	if (!nlnk->r1 || !nlnk->r2)
		return (0);
	nlnk->next = NULL;
	tmp = *links;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!*links)
		*links = nlnk;
	else
		tmp->next = nlnk;
	return (1);
}

int			ft_checkroom(char *s, t_rooms **rooms, t_links **links, int *sten)
{
	int		i;
	int		*coord;
	char	*name;
	char	**split;

	if (*links)
		return (0);
	i = 0;
	if (!(coord = (int *)malloc(sizeof(*coord) * 2)))
		return (0);
	if (!(split = ft_strsplit(s, ' ')))
		return (0);
	while (split[i])
	{
		if (i == 0)
			name = (ft_countrooms(split[i], *rooms) == 0) ? ft_strdup(split[i])
					: NULL;
		if (i == 1)
			coord[0] = ft_checknum(split[i]);
		if (i == 2)
			coord[1] = ft_checknum(split[i]);
		i++;
	}
	ft_freesplit(split, 1);
	if (i != 3 || coord[0] == -1 || coord[1] == -1 || !name)
		return (0);
	return (ft_addroom(rooms, &name, coord, sten));
}

int			ft_checklink(char *s, t_rooms **rooms, t_links **links)
{
	char	**split;
	int		i;

	if (!*links)
	{
		if (!ft_valrooms(*rooms))
			return (0);
	}
	i = 0;
	split = ft_strsplit(s, '-');
	while (split[i])
	{
		if (ft_countrooms(split[i], *rooms) != 1)
			return (ft_freesplit(split, 0));
		i++;
	}
	if (i != 2)
		return (ft_freesplit(split, 0));
	return (ft_addlink(split, links));
}
