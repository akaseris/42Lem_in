/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:25:47 by akaseris          #+#    #+#             */
/*   Updated: 2018/02/05 16:21:26 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s = (char*)malloc(sizeof(*s1) * (i + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s[i] = (char)s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
