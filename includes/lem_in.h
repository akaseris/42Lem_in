/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:46:25 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/23 14:30:39 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN

# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct	s_rooms
{
	char			*name;
	int				pos;
	int				x;
	int				y;
	struct s_rooms	*next;
}				t_rooms;

typedef struct	s_links
{
	char			r1;
	char			r2;
	struct s_rooms	*next;
}				t_links;

typedef struct	s_map
{
	char			*name;
	int				full;
	int				pos;
	int				x;
	int				y;
	struct s_map	**next;
}				t_map;

int				ft_getinp(void);

#endif
