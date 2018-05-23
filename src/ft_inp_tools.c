/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inp_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:26:37 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/23 17:43:12 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_over(char *s)
{
	int				i;
	long long int	nb;
	char			*tmp;

	i = (ft_strchr("+-", s[0])) ? 1 : 0;
	if (!ft_isdigit(s[1]))
		return (1);
	while (s[i] == '0')
		i++;
	if (s[i] == '\0')
		return (1);
	nb = ft_atoli(s + i);
	tmp = ft_itoa_base(nb, 10);
	nb = (s[0] == '-') ? -nb : nb;
	if (ft_strlen(s + i) != ft_strlen(tmp) || nb < -2147483648
		|| nb > 2147483647)
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

int		ft_checknum(char *s)
{
	int i;

	i = 1;
	if ((!ft_strchr("+-", s[0]) && !ft_isdigit(s[0])) ||
		(ft_strchr("+-", s[0]) && !ft_isdigit(s[1])) || !ft_over(s))
		return (-1);
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] != '\0')
		return (-1);
	i = ft_atoi(s);
	return ((i < 0) ? -1 : i);
}

int		ft_addroom(t_rooms **rooms, char **name, int *coord, int sten)
{
	t_rooms *nrm;
	t_rooms *tmp;

	if (!*rooms)
		return (0);
	if (!(nrm = (t_rooms *)malloc(sizeof(*nrm))))
		return (0);
	nrm->name = ft_strdup(*name);
	if (!(nrm->name))
		return (0);
	nrm->x = coord[0];
	nrm->y = coord[1];
	if (sten == 1 || sten == 2)
		nrm->pos = sten - 1;
	else
		nrm->pos = 2;
	tmp = *rooms;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nrm;
	nrm->next = NULL;
}

int		ft_checkroom(char *s, t_rooms **rooms, t_links **links, int sten)
{
	int		i;
	int		*coord;
	char	*name;
	char	**split;

	if (*links)
		return (0);
	i = 0;
	split = ft_strsplit(s, ' ');
	if (!(coord = (int *)malloc(sizeof(*coord) * 2)))
		return (0);
	while (split[i])
	{
		if (i == 0)
			name = ft_strdup(s[i]);
		if (i == 1)
			coord[0] = ft_checknum(s[i]);
		if (i == 2)
			coord[1] = ft_checknum(s[i]);
		i++;
	}
	if (i != 3 || x == -1 || y == -1 || !name)
		return (0);
	return (ft_addroom(rooms, &name, coord, sten));
}

int		ft_checklink(char *s, t_links **links)
{

}
