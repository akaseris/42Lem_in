/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:22:02 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/25 15:43:02 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	j;
	char			*str;

	if (s && f)
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		str = (char *)malloc(sizeof(char) * (i + 1));
		if (str == NULL)
			return (NULL);
		str[i] = '\0';
		j = 0;
		while (*s != '\0')
			*str++ = f(j++, *s++);
		return (str - i);
	}
	return (NULL);
}
