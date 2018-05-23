/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:12:33 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/25 15:42:20 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (s && f)
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		str = (char *)malloc(sizeof(char) * (i + 1));
		if (str == NULL)
			return (NULL);
		str[i] = '\0';
		while (*s != '\0')
			*str++ = f(*s++);
		return (str - i);
	}
	return (NULL);
}
