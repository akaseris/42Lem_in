/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:29:32 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/15 20:55:23 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define BUFF_SIZE 1

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_print
{
	char				*buf;
	char				type;
	char				*flags;
	char				*size;
	int					m_width;
	int					prc;
	int					minus;
	int					valid;
	unsigned long long	nb;
	char				*nulls;
}				t_print;

int				get_next_line(const int fd, char **line);

void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(
					const char *haystack, const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strndup(const char *s1, size_t n);
int				ft_atoi(const char *str);
long long int	ft_atoli(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *str, char c);
char			*ft_itoa(long int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_isprime(int nb);
int				ft_sqrt(int nb);
void			ft_sortwordtab(char **tab);
void			ft_advancedsortwordtab(char **tab, int (*cmp)(char *, char *));
void			ft_swap(int *a, int *b);
void			ft_printwordstables(char **tab);
char			*ft_strreplace(char *str, char n, char o, int len);
char			*ft_itoa_base(intmax_t val, int base);
char			*ft_strtolower(char *str);
char			*ft_strtoupper(char *str);
char			*ft_utoa_base(uintmax_t val, int base);
char			*ft_convertunicode(wchar_t c);
char			*ft_strunicode(wchar_t *s);
char			*ft_strmove(char *str, char blnk);
int				ft_checkunicode(wchar_t *str);
char			*ft_strjoinfree(char *ret, char *s1, char *s2);
char			*ft_ftoa(double nb, int prc);
void			ft_deltab(char **tab);

int				ft_printf(const char *str, ...);
char			*ft_assign(char *str, t_print *sprint, va_list ap);
void			ft_process(t_print *sprint, va_list ap);
void			ft_string(t_print *sprint, va_list ap);
void			ft_char(t_print *sprint, va_list ap);
void			ft_handledi(t_print *sprint, va_list ap);
void			ft_handleoux(t_print *sprint, va_list ap);
void			ft_handlef(t_print *sprint, va_list ap);
void			ft_int(t_print *sprint, va_list ap);
void			ft_long(t_print *sprint, va_list ap);
void			ft_longlong(t_print *sprint, va_list ap);
void			ft_intmax_t(t_print *sprint, va_list ap);
void			ft_schar(t_print *sprint, va_list ap);
void			ft_short(t_print *sprint, va_list ap);
void			ft_size_t(t_print *sprint, va_list ap);
void			ft_ulonglong(t_print *sprint, va_list ap);
void			ft_ulong(t_print *sprint, va_list ap);
void			ft_uchar(t_print *sprint, va_list ap);
void			ft_ushort(t_print *sprint, va_list ap);
void			ft_uintmax_t(t_print *sprint, va_list ap);
void			ft_usize_t(t_print *sprint, va_list ap);
void			ft_uint(t_print *sprint, va_list ap);
void			ft_pointer(t_print *sprint, va_list ap);
void			ft_wchar_t(t_print *sprint, va_list ap);
void			ft_wint_t(t_print *sprint, va_list ap);
char			*ft_applywidth(t_print *sprint, char *str);
char			*ft_applyprecision(t_print *sprint, char *str);
char			*ft_applyflags(t_print *sprint, char *str);
int				ft_printbuf(t_print *sprint);
void			ft_initvalues(t_print *sprint);
void			ft_freestruct(t_print *sprint, char *nulls);
t_print			*ft_allocate(t_print *oprint);

#endif
