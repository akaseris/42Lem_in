/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 09:23:32 by akaseris          #+#    #+#             */
/*   Updated: 2017/11/26 22:47:52 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advancedsortwordtab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i + 1] != 0)
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
