/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:27:27 by akaseris          #+#    #+#             */
/*   Updated: 2018/02/14 17:37:58 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	char		*tmp;
	char		*dup;
	char		*del;
	t_print		*sprint;

	sprint = NULL;
	if (!(sprint = ft_allocate(sprint)))
		return (-1);
	dup = ft_strdup(str);
	del = dup;
	va_start(ap, str);
	while ((tmp = ft_strchr(dup, '%')))
	{
		*tmp++ = '\0';
		sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, dup);
		if (!(dup = ft_assign(tmp, sprint, ap)))
			return (-1);
		ft_process(sprint, ap);
		sprint = ft_allocate(sprint);
	}
	sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, dup);
	free(del);
	return (ft_printbuf(sprint));
}
