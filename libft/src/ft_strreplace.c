/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:36:23 by akaseris          #+#    #+#             */
/*   Updated: 2018/02/13 16:43:31 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char n, char o, int len)
{
	int i;

	if (len <= 0)
		return (str);
	i = 0;
	while (len > 0)
	{
		if (str[i] == o)
			str[i] = n;
		i++;
		len--;
	}
	return (str);
}
