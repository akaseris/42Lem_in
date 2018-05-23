/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:08:44 by akaseris          #+#    #+#             */
/*   Updated: 2018/03/06 17:08:48 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strunicode(wchar_t *s)
{
	int		i;
	char	*str;
	char	*tmp;
	char	*del;

	if (!s || !(str = ft_strnew(0)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		del = str;
		tmp = ft_convertunicode(s[i]);
		str = ft_strjoin(str, tmp);
		free(del);
		free(tmp);
		i++;
	}
	return (str);
}
