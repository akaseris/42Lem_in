/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 12:54:45 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/25 15:41:56 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dlen;
	size_t slen;

	i = 0;
	while (dst[i] != '\0')
		i++;
	dlen = i;
	i = 0;
	while (src[i] != '\0')
		i++;
	slen = i;
	if (size == 0)
		return (slen);
	i = 0;
	while (src[i] != '\0' && ((dlen + i) < (size - 1)))
	{
		dst[dlen + i] = (char)src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (slen + ((dlen < size) ? dlen : size));
}
