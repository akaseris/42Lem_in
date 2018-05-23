/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:20:59 by akaseris          #+#    #+#             */
/*   Updated: 2018/02/05 16:31:27 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t		i;
	char		*s;

	i = 0;
	while (s1[i] != '\0')
		i++;
	n = (i > n) ? n : i;
	s = (char*)malloc(sizeof(*s1) * (n + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && n-- > 0)
	{
		s[i] = (char)s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
