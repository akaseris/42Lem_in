/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:46:25 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/31 19:42:38 by akaseris         ###   ########.fr       */
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
	char			*path;
	int				pos;
	int				full;
	int				check;
	int				x;
	int				y;
	struct s_rooms	*next;
	struct s_rooms	**links;
}				t_rooms;

typedef struct	s_links
{
	char			*r1;
	char			*r2;
	struct s_links	*next;
}				t_links;

int				ft_getinp(t_rooms **rooms, t_links **links);
int				ft_checkroom(char *s, t_rooms **rooms, t_links **links, int *sten);
int				ft_over(char *s);
int				ft_checknum(char *s);
int				ft_checklink(char *s, t_rooms **rooms, t_links **links);
int				ft_valrooms(t_rooms *rooms);
int				ft_countrooms(char *s, t_rooms *rooms);
int				ft_createmap(t_rooms **rooms, t_links **links);
void			ft_findroom(char *s, t_rooms **crm, t_rooms **rooms);
int				ft_strlnk(t_rooms *room, t_links *links, char **s);
int				ft_findpaths(t_rooms **rooms);
void			ft_findends(t_rooms **start, t_rooms **rooms, int ind);
int				ft_addarr(t_list **arr, t_rooms **rm);
int				ft_freearr(t_list **lst, int ret);
void			ft_lstfreeone(t_list **lst);
int				ft_move(t_rooms **rooms);
void			ft_freerooms(t_rooms **rms);
void			ft_freelinks(t_links **lnk);
int				ft_freesplit(char **split, int ret);

#endif
