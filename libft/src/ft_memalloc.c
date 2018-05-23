/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:16:34 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/25 15:33:35 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (size == 0)
		return (NULL);
	if ((s = malloc(size)))
	{
		ft_memset(s, 0, size);
		return (s);
	}
	return (NULL);
}
