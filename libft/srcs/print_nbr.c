/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:38:29 by akarahan          #+#    #+#             */
/*   Updated: 2022/01/30 12:06:10 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_nbr(t_printf *tab, long nbr, int radix)
{
	unsigned int	pow;

	pow = 1;
	while (nbr / pow / radix)
		pow *= radix;
	if (tab->flags & FL_HASH && tab->type == 'X' && nbr)
		tab->ret_len += write(1, "0X", 2);
	else if (tab->flags & FL_HASH && tab->type == 'x' && nbr)
		tab->ret_len += write(1, "0x", 2);
	while (pow)
	{
		if (tab->type == 'X')
			tab->ret_len += write(1, &HEXC[nbr / pow], 1);
		else
			tab->ret_len += write(1, &HEX[nbr / pow], 1);
		nbr %= pow;
		pow /= radix;
	}
}

void	print_nbr(t_printf *tab, int radix, int is_signed)
{
	long	nbr;
	int		n_len;

	if (is_signed)
		nbr = va_arg(tab->args, int);
	else
		nbr = va_arg(tab->args, unsigned int);
	n_len = nbrlen(nbr, radix);
	if (nbr < 0)
	{
		nbr = -nbr;
		tab->flags |= SIGN;
	}
	calculate_printlen(tab, n_len);
	if (!(tab->flags & FL_MINUS) && !(tab->flags & FL_DOT))
		put_space(tab, n_len);
	if (tab->flags & SIGN || tab->flags & FL_PLUS)
		put_sign(tab);
	if (tab->flags & FL_DOT)
		put_zeros(tab, n_len);
	put_nbr(tab, nbr, radix);
	if (tab->flags & FL_DOT && tab->width)
		tab->print_len += n_len;
	if (tab->flags & FL_MINUS)
		put_space(tab, n_len);
}

static void	put_ptr(t_printf *tab, uintptr_t nbr)
{
	uintptr_t	pow;

	pow = 1;
	if (nbr == 0)
	{
		tab->ret_len += write(1, "0x0", 3);
		return ;
	}
	while (nbr / pow / 16)
		pow *= 16;
	tab->ret_len += write(1, "0x", 2);
	while (pow)
	{
		tab->ret_len += write(1, &HEX[nbr / pow], 1);
		nbr %= pow;
		pow /= 16;
	}
}

void	print_ptr(t_printf *tab)
{
	uintptr_t	nbr;
	int			n_len;

	nbr = (uintptr_t)va_arg(tab->args, void *);
	if (!nbr)
	{
		n_len = 3;
		tab->flags |= IS_NULL;
	}
	else
		n_len = nbrlen(nbr, 16);
	calculate_printlen(tab, n_len);
	if (!(tab->flags & FL_MINUS))
		put_space(tab, n_len);
	if (tab->flags & SIGN || tab->flags & FL_PLUS)
		put_sign(tab);
	if (tab->flags & FL_DOT)
		put_zeros(tab, n_len);
	put_ptr(tab, nbr);
	if (tab->flags & FL_MINUS && !((long)nbr < 0))
		put_space(tab, n_len);
}
