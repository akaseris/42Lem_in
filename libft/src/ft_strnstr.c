/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:24:27 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/25 15:44:05 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t d;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len--)
	{
		d = 0;
		while (haystack[i + d] == needle[d] && d <= len)
		{
			d++;
			if (needle[d] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
