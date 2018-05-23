/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 17:55:41 by akaseris          #+#    #+#             */
/*   Updated: 2018/03/09 17:55:43 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_adjustwidth(t_print *sprint)
{
	if (ft_strchr(sprint->flags, '#') && ft_strchr("pxX", sprint->type))
		sprint->m_width = sprint->m_width - 2;
	if (ft_strchr(sprint->flags, '#') && sprint->type == 'o')
		sprint->m_width = sprint->m_width - 1;
	if (ft_strchr(sprint->flags, '+') && sprint->minus == 0 && sprint->valid)
		sprint->m_width = sprint->m_width - 1;
	if (sprint->minus == 1 || (sprint->nb == 0
		&& ft_strchr("di", sprint->type) && ft_strchr(sprint->flags, ' ')))
		sprint->m_width = sprint->m_width - 1;
}

char		*ft_applywidth(t_print *sprint, char *str)
{
	int		gap;
	char	*tmp;
	char	fill;

	fill = ' ';
	if (ft_strchr(sprint->flags, '0') && ft_strchr(sprint->flags, '-') == NULL
			&& (sprint->prc == -1 || sprint->valid == 0))
		fill = '0';
	ft_adjustwidth(sprint);
	if ((gap = sprint->m_width - (int)ft_strlen(str)) > 0)
	{
		tmp = ft_strnew(gap);
		ft_strreplace(tmp, fill, '\0', gap);
		str = (ft_strchr(sprint->flags, '-'))
				? ft_strjoinfree(str, str, tmp) : ft_strjoinfree(str, tmp, str);
		free(tmp);
	}
	return (str);
}

char		*ft_applyprecision(t_print *sprint, char *str)
{
	int		gap;
	char	*tmp;

	if ((gap = sprint->prc - (int)ft_strlen(str)) > 0)
	{
		tmp = ft_strnew(gap);
		ft_strreplace(tmp, '0', '\0', gap);
		str = ft_strjoinfree(str, tmp, str);
		free(tmp);
	}
	return (str);
}

char		*ft_applyflags(t_print *sprint, char *str)
{
	if (sprint->nb == 0 && sprint->prc == 0 && !(sprint->type == 'o'
		&& ft_strchr(sprint->flags, '#')))
		str = ft_applywidth(sprint, ft_strnew(0));
	if (ft_strchr(sprint->flags, '#') && ft_strchr("pxX", sprint->type)
		&& (sprint->nb != 0 || sprint->type == 'p'))
		str = ft_strjoinfree(str, "0X", str);
	if (ft_strchr(sprint->flags, '#') && sprint->type == 'o' && sprint->nb
		&& (sprint->prc - (int)ft_strlen(ft_itoa(sprint->nb)) < 0))
		str = ft_strjoinfree(str, "0", str);
	str = (ft_strchr("xp", sprint->type)) ? ft_strtolower(str) : str;
	if (ft_strchr(sprint->flags, '+') && sprint->minus == 0
			&& ft_strchr("di", sprint->type))
		str = ft_strjoinfree(str, "+", str);
	else if (ft_strchr(sprint->flags, ' ') && str[0] != ' '
				&& sprint->minus == 0 && ft_strchr("di", sprint->type))
		str = ft_strjoinfree(str, " ", str);
	else if (sprint->minus == 1)
		str = ft_strjoinfree(str, "-", str);
	if (ft_strchr(sprint->flags, '-') == NULL)
		str = ft_strmove(str, ' ');
	return (str);
}
