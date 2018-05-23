/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:42:54 by akaseris          #+#    #+#             */
/*   Updated: 2018/02/14 17:37:47 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_width(t_print *sprint, char *str, va_list ap)
{
	int i;

	if (*sprint->size != '\0' || sprint->prc != -1)
		return (NULL);
	if (*str == '*')
	{
		i = va_arg(ap, int);
		if (i < 0)
			sprint->flags = ft_strjoinfree(sprint->flags, sprint->flags, "-");
		i = (i < 0) ? -i : i;
		sprint->m_width = i;
	}
	else
	{
		sprint->m_width = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
		str--;
	}
	return (str);
}

static char	*ft_prc(t_print *sprint, char *str, va_list ap)
{
	int i;

	if (*sprint->size != '\0')
		return (NULL);
	if (*(str + 1) == '*')
	{
		i = va_arg(ap, int);
		sprint->prc = (i < 0) ? -1 : i;
		str++;
	}
	else
	{
		sprint->prc = ft_atoi(++str);
		while (ft_isdigit(*str))
			str++;
		str--;
	}
	return (str);
}

char		*ft_assign(char *str, t_print *sprint, va_list ap)
{
	char *s1;

	while (*str && ft_strchr("#0-+ 123456789.hljz*", *str) != NULL)
	{
		s1 = ft_strndup(str, 1);
		if (ft_strchr("#0-+ ", *str) != NULL)
			sprint->flags = ft_strjoinfree(sprint->flags, sprint->flags, s1);
		else if (ft_isdigit(*str) || *str == '*')
		{
			if (!(str = ft_width(sprint, str, ap)))
				return (NULL);
		}
		else if (*str == '.')
		{
			if (!(str = ft_prc(sprint, str, ap)))
				return (NULL);
		}
		else if (ft_strchr("hljz", *str) != NULL)
			sprint->size = ft_strjoinfree(sprint->size, sprint->size, s1);
		str++;
		free(s1);
	}
	sprint->type = (*str) ? *str++ : '\0';
	return (str);
}
