/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:38:13 by akarahan          #+#    #+#             */
/*   Updated: 2022/01/30 12:03:56 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

# define HEX "0123456789abcdef"
# define HEXC "0123456789ABCDEF"

enum {
	FL_HASH = (1 << 0),
	FL_SPACE = (1 << 1),
	FL_PLUS = (1 << 2),
	FL_MINUS = (1 << 3),
	FL_ZERO = (1 << 4),
	FL_DOT = (1 << 5),
	LEN_HH = (1 << 6),
	LEN_H = (1 << 7),
	LEN_LL = (1 << 8),
	LEN_L = (1 << 9),
	SIGN = (1 << 10),
	IS_NULL = (1 << 11)
};

typedef struct s_printf
{
	va_list		args;
	const char	*ptr;
	short		flags;
	char		type;
	int			ret_len;
	int			width;
	int			precis;
	int			print_len;
}	t_printf;

int		ft_printf(const char *fmt, ...);

void	print_nbr(t_printf *tab, int radix, int is_signed);
void	print_ptr(t_printf *tab);
void	print_char(t_printf *tab);
void	print_str(t_printf *tab);

/* Print_nbr utils */
int		nbrlen(long n, int radix);
void	calculate_printlen(t_printf *tab, int n_len);
void	put_sign(t_printf *tab);
void	put_space(t_printf *tab, int n_len);
void	put_zeros(t_printf *tab, int n_len);

#endif
