/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:36:38 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/25 15:36:58 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str1;
	const char	*str2;

	str1 = (char*)dst;
	str2 = (const char*)src;
	if ((unsigned long)dst < (unsigned long)src)
	{
		while (len--)
			*str1++ = *str2++;
	}
	else
	{
		while (len--)
			str1[len] = str2[len];
	}
	return (dst);
}
