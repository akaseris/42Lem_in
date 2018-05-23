/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:08:34 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/09 15:56:27 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int r;
	int i;
	int minus;

	r = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		minus = ((str[i] == '-') ? -1 : 1);
		i++;
	}
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * minus);
}
