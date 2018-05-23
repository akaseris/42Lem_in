/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:37:49 by akaseris          #+#    #+#             */
/*   Updated: 2018/03/11 16:37:52 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmove(char *str, char blnk)
{
	int i;
	int k;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == blnk)
		{
			k = i;
			while (k > 0)
			{
				str[k] = str[k - 1];
				k--;
			}
			str[0] = blnk;
		}
		i++;
	}
	return (str);
}
