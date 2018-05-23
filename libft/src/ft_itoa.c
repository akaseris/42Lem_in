/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:00:43 by akaseris          #+#    #+#             */
/*   Updated: 2018/02/14 20:16:57 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long int nb)
{
	int		alloc;

	alloc = (nb < 0) ? 2 : 1;
	nb = (nb < 0) ? -nb : nb;
	while (nb > 9)
	{
		alloc++;
		nb = nb / 10;
	}
	return (alloc);
}

char		*ft_itoa(long int nb)
{
	char		*buf;
	int			alloc;

	alloc = count_digits(nb);
	nb = (nb < 0) ? -nb : nb;
	if (!(buf = (char *)malloc(sizeof(char) * alloc + 1)))
		return (NULL);
	buf[alloc--] = '\0';
	while (nb > 9)
	{
		buf[alloc--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	buf[alloc--] = nb + '0';
	if (alloc == 0)
		buf[alloc] = '-';
	return (buf);
}
