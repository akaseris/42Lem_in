/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:54:46 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/01 21:48:46 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_getlink(t_list **slst, int fd)
{
	t_list *tmp;

	tmp = *slst;
	while (tmp)
	{
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, 0);
	tmp->content_size = fd;
	tmp->content = ft_strnew(0);
	ft_lstadd(slst, tmp);
	return (tmp);
}

static int		ft_line(char **line, char **content, char **str)
{
	char *s;
	char *tmp;

	free(*str);
	tmp = *line;
	if ((s = ft_strchr(*line, '\n')))
	{
		*s = '\0';
		s++;
		*line = ft_strdup(*line);
		*content = ft_strdup(s);
		free(tmp);
		return (2);
	}
	else if (ft_strlen(*content) > 0)
	{
		**content = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*slst;
	t_list			*tmp;
	char			*str;
	int				s;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	tmp = ft_getlink(&slst, fd);
	if (!(str = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while (!ft_strchr(str, '\n'))
	{
		s = read(fd, str, BUFF_SIZE);
		if (s < 0)
			return (-1);
		str[s] = '\0';
		*line = ft_strjoin(tmp->content, str);
		if (s == 0)
			return (ft_line(line, (char **)&(tmp->content), &str));
		free(tmp->content);
		tmp->content = *line;
	}
	return (ft_line(line, (char **)&(tmp->content), &str));
}
