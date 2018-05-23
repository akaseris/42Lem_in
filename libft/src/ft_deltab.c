/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:38:19 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/04 17:33:25 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deltab(char **tab)
{
	int y;

	y = 0;
	if (tab)
	{
		while (tab[y])
		{
			free(tab[y]);
			tab[y] = NULL;
			y++;
		}
		free(tab);
		tab = NULL;
	}
}
