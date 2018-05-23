/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:37:57 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/09 17:38:47 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_allocrow(char **tbl, char *str, char del)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i] == del)
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == del)
		{
			c++;
			while (str[i] == del)
				i++;
		}
	}
	if (!(str[i - 1] == del))
		c++;
	if (!(tbl = (char**)malloc(sizeof(*tbl) * (c + 1))))
		return (NULL);
	tbl[c] = NULL;
	return (tbl);
}

static char	**ft_alloccol(char **tbl, char *str, char del)
{
	int i;
	int c;
	int k;

	i = 0;
	k = 0;
	c = 0;
	while (str[i] == del)
		i++;
	while (str[i] != '\0')
	{
		i++;
		k++;
		if (str[i] == del || str[i] == '\0')
		{
			if (!(tbl[c] = (char*)malloc(sizeof(**tbl) * (k + 1))))
				return (NULL);
			while (str[i] == del)
				i++;
			k = 0;
			c++;
		}
	}
	return (tbl);
}

static char	**ft_filltbl(char **tbl, char *str, char del)
{
	int i;
	int c;
	int j;

	i = 0;
	c = 0;
	j = 0;
	while (str[i] == del)
		i++;
	while (str[i] != '\0')
	{
		tbl[c][j] = str[i];
		i++;
		j++;
		if (str[i] == del || str[i] == '\0')
		{
			tbl[c][j] = '\0';
			c++;
			j = 0;
			while (str[i] == del)
				i++;
		}
	}
	return (tbl);
}

char		**ft_strsplit(char const *s, char c)
{
	char **split;

	if (!s || !c || s[0] == '\0')
		return (NULL);
	split = NULL;
	if (!(split = ft_allocrow(split, (char *)s, c)))
		return (NULL);
	if (!(split = ft_alloccol(split, (char *)s, c)))
		return (NULL);
	split = ft_filltbl(split, (char *)s, c);
	return (split);
}
