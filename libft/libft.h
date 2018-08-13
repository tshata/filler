/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:31:04 by tshata            #+#    #+#             */
/*   Updated: 2018/08/13 16:21:48 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 32
typedef	struct		s_list
{
	void			*content;
	int			content_size;
	struct s_list	*next;
}					t_list;

long long			ft_sqr(long long value);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, int n);
char				*ft_strncpy(char *dest, const char *src, int len);
char				*ft_strnew(int size);
char				*ft_strnstr(const char *h, const char *n, int len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, int len);
char				*ft_strtrim(char const *s);
int					get_next_line(const int fd, char **line);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int d);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, int n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, int n);
int					ft_strnequ(char const *s1, char const *s2, int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int				ft_strlcat(char *dest, const char *src, int destsize);
int				ft_strlen(const char *str);
t_list				*ft_lstnew(void const *content, int content_size);
void				*ft_memalloc(int size);
void				*ft_memccpy(void *dest, const void *src, int c, int n);
void				*ft_memchr(const void *s, int c, int n);
void				*ft_memcpy(void *dest, const void *src, int n);
void				*ft_memmove(void *dest, const void *src, int len);
void				*ft_memset(void *b, int c, int len);
void				ft_bzero(void *s, int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, int));
void				ft_lstdelone(t_list **alst, void (*del)(void *, int));
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putchar_fd(const char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif
