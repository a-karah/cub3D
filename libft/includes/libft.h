/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:48 by akarahan          #+#    #+#             */
/*   Updated: 2022/05/08 22:35:27 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"
# include "ft_printf.h"

# define C_PI 3.1415926535

/* Libc functions */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *dest, const void *src, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isspace(int c);
long	ft_atol(const char *nptr);

/* Additional functions */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Bonus functions */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Extra Functions */
int		ft_count_words(char const *s, char sep);
int		ft_max_int(int x, int y);
float	ft_max_float(float x, float y);
int		ft_max_2d_arr(int **tab, int x_lim, int y_lim);
int		ft_min_int(int x, int y);
float	ft_min_float(float x, float y);
int		ft_min_2d_arr(int **tab, int x_lim, int y_lim);
int		ft_abs_int(int n);
float	ft_abs_float(float n);
void	ft_arriteri(int **tab, void (*f)(int *, int), int factor);
void	ft_swap(int *a, int *b);
void	ft_qsort(int *arr, int lo, int hi);
void	ft_printarr(int *arr, int elem);
float	ft_deg2rad(float deg);
float	ft_rad2deg(float rad);
int		mod_deg(int deg);
float	fl_mod_deg(float deg);

typedef struct s_vf2d
{
	float	x;
	float	y;
}				t_vf2d;

typedef struct s_vi2d
{
	int	x;
	int	y;
}				t_vi2d;

t_vf2d	*vf2d_new(float x, float y);
t_vi2d	*vi2d_new(int x, int y);

#endif
