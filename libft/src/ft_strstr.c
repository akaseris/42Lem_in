/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 21:05:15 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/23 17:51:10 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int d;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		d = 0;
		while (haystack[i + d] == needle[d])
		{
			d++;
			if (needle[d] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
