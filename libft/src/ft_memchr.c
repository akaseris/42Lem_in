/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:16:08 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/25 15:34:17 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (!n)
		return (NULL);
	str = (unsigned char *)s;
	c = (unsigned char)c;
	i = 0;
	while (str[i] != c && (i < n - 1))
		i++;
	if (str[i] == c)
		return (str + i);
	return (NULL);
}
