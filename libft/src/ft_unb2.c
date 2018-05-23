/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unb2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:51:58 by akaseris          #+#    #+#             */
/*   Updated: 2018/02/13 19:51:59 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_uintmax_t(t_print *sprint, va_list ap)
{
	intmax_t	nb;
	char		*str;

	nb = va_arg(ap, intmax_t);
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

void		ft_usize_t(t_print *sprint, va_list ap)
{
	size_t		nb;
	char		*str;

	nb = (size_t)va_arg(ap, long int);
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

void		ft_uint(t_print *sprint, va_list ap)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(ap, unsigned int);
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

void		ft_pointer(t_print *sprint, va_list ap)
{
	unsigned long	nb;
	char			*str;

	nb = (unsigned long)va_arg(ap, void*);
	sprint->nb = nb;
	str = ft_utoa_base(nb, 16);
	str = ft_strtolower(str);
	sprint->flags = ft_strjoinfree(sprint->flags, sprint->flags, "#");
	str = ft_applyprecision(sprint, str);
	str = ft_applywidth(sprint, str);
	str = ft_applyflags(sprint, str);
	sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, str);
	free(str);
}
