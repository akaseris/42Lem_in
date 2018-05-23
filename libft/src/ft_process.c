/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:46:00 by akaseris          #+#    #+#             */
/*   Updated: 2018/03/04 20:15:21 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printnumber(t_print *sprint, va_list ap)
{
	if (sprint->type == 'd' || sprint->type == 'i')
		ft_handledi(sprint, ap);
	else if (ft_strchr("pouxX", sprint->type))
		ft_handleoux(sprint, ap);
	else if (ft_strchr("fF", sprint->type))
		ft_handlef(sprint, ap);
}

static void	ft_printalpha(t_print *sprint, va_list ap)
{
	if (sprint->type == 's')
	{
		if (ft_strchr(sprint->size, 'l') == NULL)
			ft_string(sprint, ap);
		else
			ft_wchar_t(sprint, ap);
	}
	else if (sprint->type == 'c')
	{
		if (ft_strchr(sprint->size, 'l') == NULL)
			ft_char(sprint, ap);
		else
			ft_wint_t(sprint, ap);
	}
}

static void	ft_printpercentage(t_print *sprint)
{
	char *str;
	char fill;

	if (sprint->m_width != 0)
	{
		fill = (ft_strchr(sprint->flags, '0')
			&& ft_strchr(sprint->flags, '-') == NULL) ? '0' : ' ';
		str = ft_strnew(sprint->m_width);
		if (ft_strchr(sprint->flags, '-'))
			str[0] = '%';
		else
			str[sprint->m_width - 1] = '%';
		ft_strreplace(str, fill, '\0', sprint->m_width);
		sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, str);
	}
	else
		sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, "%");
}

void		ft_process(t_print *sprint, va_list ap)
{
	char *tmp;

	if (ft_strchr("SDOUC", sprint->type) != NULL && sprint->type != '\0')
	{
		sprint->size = ft_strjoinfree(sprint->size, sprint->size, "l");
		sprint->type = sprint->type + 32;
	}
	if (ft_strchr("dipouxXfF", sprint->type) != NULL && sprint->type != '\0')
		ft_printnumber(sprint, ap);
	else if (sprint->type == 's' || sprint->type == 'c')
		ft_printalpha(sprint, ap);
	else if (sprint->type == '%')
		ft_printpercentage(sprint);
	else if (sprint->type)
	{
		sprint->valid = 0;
		tmp = ft_strnew(1);
		tmp[0] = sprint->type;
		tmp = ft_applywidth(sprint, tmp);
		sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, tmp);
		free(tmp);
	}
}
