/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:50:10 by okerniak          #+#    #+#             */
/*   Updated: 2017/02/02 18:37:17 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define M(x) x < 0 ? -x : x

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct		s_flagi
{
	int				hash;
	int				point;
	char			*tipe_long;
	int				minus;
	int				plus;
	int				spase;
	int				nul;
	int				width;
	int				accuracy;
	char			tipe;
}					t_flagi;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *destination,
		const void *source, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *out, const void *in, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *memptr, int val, size_t num);
void				ft_putchar(char c);
void				ft_putnbr(int num);
void				ft_putstr(char const *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
		const char *little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char	*s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char*));
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
size_t				ft_putchar_fd(const uint32_t symbol, const int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int num, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isascii(int c);
char				*ft_strcut(char const *s, int start, int end);
size_t				ft_lennbr(int a);
char				*ft_strrevers(char *str);
int					ft_strsimvoli(const char *str, const char *simv);
char				*ft_strkillchar(char *str, char c);
void				ft_putstr_wchar(wchar_t const *str);
wchar_t				*ft_strdup_wchar(const wchar_t *s1);
wchar_t				*ft_strjoin_wchar(wchar_t const *s1, wchar_t const *s2);
size_t				ft_strlen_wchar(const wchar_t *str);
char				*ft_itoa_base(long long nbr, int base);
void				ft_putnbrfloat(float nbr);
int					ft_printf(const char *str, ...);
char				*ft_itoa_base_unsigned(unsigned long long n, int base);
char				*ft_itoa_base(long long n, int base);
void				*create_string(t_flagi *flagi, va_list p, int *count);
char				*ft_useflagi(char *str, t_flagi *flagi);
wchar_t				*create_string_wchar(t_flagi *flagi, va_list p);
size_t				ft_strlen_wchar(const wchar_t *str);
size_t				ft_len_wchar(const wchar_t *str);
int					len_simvol_show(t_flagi *flagi, void *str);

#endif
