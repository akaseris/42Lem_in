/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:34:36 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/25 15:43:40 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (len--)
	{
		if (src[i] == '\0')
		{
			dst[i + len] = '\0';
			continue;
		}
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
