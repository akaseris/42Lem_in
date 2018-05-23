/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unb1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:52:07 by akaseris          #+#    #+#             */
/*   Updated: 2018/03/05 17:57:23 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_ulonglong(t_print *sprint, va_list ap)
{
	unsigned long long	nb;
	char				*str;

	nb = va_arg(ap, unsigned long long int);
	sprint->nb = nb;
	if (sprint->type == 'o')
		str = ft_utoa_base(nb, 8);
	else if (sprint->type == 'x' || sprint->type == 'X')
		str = ft_utoa_base(nb, 16);
	else
		str = ft_utoa_base(nb, 10);
	str = (sprint->type == 'x') ? ft_strtolower(str) : str;
	str = ft_applyprecision(sprint, str);
	str = ft_applywidth(sprint, str);
	str = ft_applyflags(sprint, str);
	sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, str);
	free(str);
}

void		ft_ulong(t_print *sprint, va_list ap)
{
	unsigned long	nb;
	char			*str;

	nb = va_arg(ap, unsigned long int);
	sprint->nb = nb;
	if (sprint->type == 'o')
		str = ft_utoa_base(nb, 8);
	else if (sprint->type == 'x' || sprint->type == 'X')
		str = ft_utoa_base(nb, 16);
	else
		str = ft_utoa_base(nb, 10);
	str = (sprint->type == 'x') ? ft_strtolower(str) : str;
	str = ft_applyprecision(sprint, str);
	str = ft_applywidth(sprint, str);
	str = ft_applyflags(sprint, str);
	sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, str);
	free(str);
}

void		ft_uchar(t_print *sprint, va_list ap)
{
	unsigned char	nb;
	char			*str;

	nb = (unsigned char)va_arg(ap, unsigned int);
	sprint->nb = nb;
	if (sprint->type == 'o')
		str = ft_utoa_base(nb, 8);
	else if (sprint->type == 'x' || sprint->type == 'X')
		str = ft_utoa_base(nb, 16);
	else
		str = ft_utoa_base(nb, 10);
	str = (sprint->type == 'x') ? ft_strtolower(str) : str;
	str = ft_applyprecision(sprint, str);
	str = ft_applywidth(sprint, str);
	str = ft_applyflags(sprint, str);
	sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, str);
	free(str);
}

void		ft_ushort(t_print *sprint, va_list ap)
{
	unsigned short	nb;
	char			*str;

	nb = (unsigned short)va_arg(ap, unsigned int);
	sprint->nb = nb;
	if (sprint->type == 'o')
		str = ft_utoa_base(nb, 8);
	else if (sprint->type == 'x' || sprint->type == 'X')
		str = ft_utoa_base(nb, 16);
	else
		str = ft_utoa_base(nb, 10);
	str = (sprint->type == 'x') ? ft_strtolower(str) : str;
	str = ft_applyprecision(sprint, str);
	str = ft_applywidth(sprint, str);
	str = ft_applyflags(sprint, str);
	sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, str);
	free(str);
}
