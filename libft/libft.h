/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:55:05 by aribesni          #+#    #+#             */
/*   Updated: 2020/07/01 15:07:21 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# include <stdio.h>
# include <stdarg.h>

typedef struct		s_list
{
	va_list			pointer;
	int				size;
	int				prec;
	int				wid;
	int				space;
	int				ret;
	int				tmp;
	int				tmp2;
	char			charac;
	char			conv;
	char			*string;
	long int		integer;
	long int		neg;
	long int		u_integer;
	void			*p_integer;
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putendl(char *s);
void				ft_putnbr(int nb);
void				ft_strclr(char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putnbr_base(int nb, char *base);
void				ft_putnbr_base_u(long int nb, char *base);
void				ft_bzero(void *string, size_t n);
void				ft_flags(const char *str, int **i);
void				ft_reset(t_list *elem);
void				ft_display(int k, const char *str, t_list *elem);
void				ft_ret(int k, const char *str, t_list *elem);
void				ft_rest(int j, int **z, const char *str, t_list *elem);
void				ft_zero(int l, const char *str, t_list *elem);
void				ft_assign(int j, int **z, const char *str, t_list *elem);
void				ft_dot_bis(int i, const char *str, t_list *elem);
void				ft_wildcard(int j, int k, const char *str, t_list *elem);
void				*ft_memset(void *pointer, int value, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_uitoa_base(long int value, char *base);
void				ft_lstadd_front(t_list **alst, t_list *new_lst);
void				ft_lstadd_back(t_list **alst, t_list *new_lst);
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void*));
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(const char *str, const char *set);
char				*ft_strdup(const char *s1);
char				*ft_strnew(size_t size);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_substr(const char *str, unsigned int start, size_t len);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_itoa(int n);
char				**ft_split(const char *str, char c);
char				*ft_strmapi(const char *str, char (*f)(unsigned int, char));
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char *s1, char *s2);
int					ft_strnequ(char *s1, char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_lstsize(t_list *new_lst);
int					ft_print_c(t_list *elem, const char *str, int *z, char c);
int					ft_print_s(t_list *elem, const char *str, int *z, char c);
int					ft_print_i_u(t_list *elem, const char *str, int *z, char c);
int					ft_print_p(t_list *elem, const char *str, int *z, char c);
int					ft_printf(const char *str, ...);
int					ft_dot_s(int i, int **z, const char *str, t_list *elem);
int					get_next_line(int fd, char **line);
size_t				ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t				ft_strlcat(char *dest, const char *src, size_t destsize);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void*),
								void (*del)(void*));

#endif
