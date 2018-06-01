/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inp_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:57:18 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/01 19:54:57 by akaseris         ###   ########.fr       */
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

int		ft_valrooms(t_rooms *rooms)
{
	int s;
	int e;

	if (!rooms || rooms->pos != -1 || !rooms->next)
		return (0);
	s = 0;
	e = 0;
	rooms = rooms->next;
	while (rooms)
	{
		if (rooms->pos == 0)
			s++;
		if (rooms->pos == 1)
			e++;
		rooms = rooms->next;
	}
	if (s != 1 || e != 1)
		return (0);
	return (1);
}

int		ft_countroom(char *s, t_rooms *rooms)
{
	int c;

	if (!rooms || !rooms->next)
		return (0);
	c = 0;
	rooms = rooms->next;
	while (rooms)
	{
		if (ft_strcmp(s, rooms->name) == 0)
			c++;
		rooms = rooms->next;
	}
	return (c);
}
