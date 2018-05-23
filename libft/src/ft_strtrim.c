/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:42:31 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/25 15:45:40 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (!s)
		return (0);
	i = ft_strlen(s) - 1;
	j = 0;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && s[j])
		j++;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && j < i)
		i--;
	k = i - j + 1;
	str = ft_strsub(s, j, k);
	return (str);
}
