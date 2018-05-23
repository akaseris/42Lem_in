/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:05:36 by exam              #+#    #+#             */
/*   Updated: 2018/04/19 16:06:11 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_addchar(char *str, int nb)
{
	char	*tmp;
	int		i;

	tmp = str;
	i = 0;
	while (str[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(*str) * (i + 2));
	i = 0;
	str[i] = (nb > 9) ? nb + 55 : nb + 48;
	while (tmp[i] != '\0')
	{
		str[i + 1] = tmp[i];
		i++;
	}
	str[i + 1] = '\0';
	free(tmp);
	return (str);
}

char		*ft_itoa_base(intmax_t val, int base)
{
	int		minus;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	minus = (val < 0) ? 1 : 0;
	val = (val < 0) ? -val : val;
	str = (char*)malloc(sizeof(*str) * 1);
	str[0] = '\0';
	while (val / base > 0)
	{
		str = ft_addchar(str, val % base);
		val = val / base;
	}
	str = ft_addchar(str, val);
	str = (minus == 1 && base == 10) ? ft_addchar(str, -3) : str;
	return (str);
}
