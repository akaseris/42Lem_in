/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:23:08 by akaseris          #+#    #+#             */
/*   Updated: 2018/02/14 15:49:12 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nulchar(t_print *sprint, char c, char *str)
{
	char *nul;

	if (!c)
	{
		if (ft_strchr(sprint->flags, '-') == NULL)
			nul = ft_strjoin(ft_itoa(ft_strlen(sprint->buf)), ",\0");
		else
			nul = ft_strjoin(ft_itoa(ft_strlen(sprint->buf) - ft_strlen(str))
					, ",\0");
		sprint->nulls = ft_strjoinfree(sprint->nulls, sprint->nulls, nul);
		free(nul);
	}
}

void		ft_string(t_print *sprint, va_list ap)
{
	char	fill;
	char	*str;
	char	*s;
	int		len;

	str = va_arg(ap, char*);
	str = (str == NULL) ? "(null)" : str;
	str = ft_strdup(str);
	if (sprint->prc != -1 && (int)ft_strlen(str) > sprint->prc)
		str[sprint->prc] = '\0';
	if (sprint->m_width - (int)ft_strlen(str) > 0)
	{
		fill = (ft_strchr(sprint->flags, '0')
				&& ft_strchr(sprint->flags, '-') == NULL) ? '0' : ' ';
		len = sprint->m_width - ft_strlen(str);
		len = (len <= 0) ? 0 : len;
		s = ft_strnew(len);
		ft_strreplace(s, fill, '\0', len);
		if (ft_strchr(sprint->flags, '-'))
			str = ft_strjoinfree(str, str, s);
		else
			str = ft_strjoinfree(str, s, str);
	}
	sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, str);
	free(str);
}

void		ft_char(t_print *sprint, va_list ap)
{
	char *str;
	char c;
	char fill;

	c = (char)va_arg(ap, int);
	if (sprint->m_width != 0)
	{
		fill = (ft_strchr(sprint->flags, '0')
				&& ft_strchr(sprint->flags, '-') == NULL) ? '0' : ' ';
		str = ft_strnew(sprint->m_width);
		if (ft_strchr(sprint->flags, '-'))
			str[0] = c;
		else
			str[sprint->m_width - 1] = c;
		sprint->m_width = (!c) ? sprint->m_width - 1 : sprint->m_width;
		ft_strreplace(str, fill, '\0', sprint->m_width);
	}
	else
	{
		str = ft_strnew(1);
		str[0] = c;
	}
	sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, str);
	ft_nulchar(sprint, c, str);
	free(str);
}

void		ft_wchar_t(t_print *sprint, va_list ap)
{
	char	fill;
	wchar_t	*wst;
	char	*str;
	char	*s;
	int		len;

	wst = va_arg(ap, wchar_t*);
	len = (ft_checkunicode(wst)) ? sprint->prc - (sprint->prc % 3)
						: sprint->prc;
	str = (wst == NULL) ? ft_strdup("(null)") : ft_strunicode(wst);
	if (sprint->prc != -1 && (int)ft_strlen(str) > sprint->prc)
		str[len] = '\0';
	if (sprint->m_width - (int)ft_strlen(str) > 0)
	{
		fill = (ft_strchr(sprint->flags, '0')
				&& ft_strchr(sprint->flags, '-') == NULL) ? '0' : ' ';
		len = sprint->m_width - ft_strlen(str);
		len = (len <= 0) ? 0 : len;
		s = ft_strnew(len);
		ft_strreplace(s, fill, '\0', len);
		str = (ft_strchr(sprint->flags, '-')) ? ft_strjoinfree(str, str, s)
				: ft_strjoinfree(str, s, str);
	}
	sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, str);
	free(str);
}

void		ft_wint_t(t_print *sprint, va_list ap)
{
	char	fill;
	char	*str;
	char	*s;
	char	c;
	int		len;

	str = ft_convertunicode(va_arg(ap, wchar_t));
	c = str[0];
	if (sprint->prc != -1 && (int)ft_strlen(str) >= sprint->prc)
		str[sprint->prc] = '\0';
	if (sprint->m_width - (int)ft_strlen(str) > 0)
	{
		fill = (ft_strchr(sprint->flags, '0')
				&& ft_strchr(sprint->flags, '-') == NULL) ? '0' : ' ';
		len = sprint->m_width - ft_strlen(str) - 1;
		len = (len <= 0) ? 0 : len;
		s = ft_strnew(len);
		ft_strreplace(s, fill, '\0', len);
		str = (ft_strchr(sprint->flags, '-')) ? ft_strjoinfree(str, str, s)
				: ft_strjoinfree(str, s, str);
	}
	sprint->buf = ft_strjoinfree(sprint->buf, sprint->buf, str);
	ft_nulchar(sprint, c, str);
	free(str);
}
