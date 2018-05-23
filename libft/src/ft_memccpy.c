/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:21:41 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/25 15:33:56 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = 0;
	while (n)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)c)
			return (dst + i + 1);
		n--;
		i++;
	}
	return (NULL);
}
