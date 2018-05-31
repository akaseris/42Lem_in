/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:17:22 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/31 20:03:45 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_freerooms(t_rooms **rms)
{
	t_rooms *tmp;

	while (*rms)
	{
		tmp = (*rms)->next;
		ft_strdel(&(*rms)->name);
		ft_strdel(&(*rms)->path);
		free((*rms)->links);
		free(*rms);
		*rms = tmp;
	}
}

int		ft_freesplit(char **split, int ret)
{
	int i;

	i = 0;
	while (split[i])
	{
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
	return (ret);
}

void	ft_freelinks(t_links **lnk)
{
	t_links *tmp;

	while (*lnk)
	{
		tmp = (*lnk)->next;
		ft_strdel(&(*lnk)->r1);
		ft_strdel(&(*lnk)->r2);
		free(*lnk);
		*lnk = tmp;
	}
}
