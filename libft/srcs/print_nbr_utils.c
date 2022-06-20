/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:40:26 by akarahan          #+#    #+#             */
/*   Updated: 2022/01/29 13:41:59 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbrlen(long n, int radix)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n)
	{
		n /= radix;
		++i;
	}
	return (i);
}

void	calculate_printlen(t_printf *tab, int n_len)
{
	tab->print_len = n_len;
	if (tab->flags & FL_DOT)
	{
		if (tab->precis > n_len)
			tab->print_len = tab->precis;
	}
	if (tab->width)
	{
		if (tab->width > n_len)
			tab->print_len = tab->width;
	}
	if (tab->flags & FL_SPACE || (tab->flags & SIGN && tab->flags & FL_DOT))
		++tab->print_len;
	if (tab->flags & SIGN && !(tab->flags & FL_DOT) && !(tab->flags & FL_MINUS))
		--tab->print_len;
	if ((tab->flags & FL_HASH || tab->type == 'p') && !(tab->flags & IS_NULL))
		tab->print_len -= 2;
}

void	put_sign(t_printf *tab)
{
	if (tab->flags & SIGN)
		tab->ret_len += write(1, "-", 1);
	else if (tab->flags & FL_PLUS)
		tab->ret_len += write(1, "+", 1);
	--tab->print_len;
}

void	put_space(t_printf *tab, int n_len)
{
	char	pad;

	pad = ' ';
	if (!(tab->flags & FL_DOT) && (tab->flags & FL_ZERO))
		pad = '0';
	if (pad == '0' && tab->flags & SIGN)
	{
		put_sign(tab);
		tab->flags &= ~SIGN;
	}
	while (tab->print_len > tab->precis && tab->print_len > n_len)
	{
		tab->ret_len += write(1, &pad, 1);
		--tab->print_len;
	}
}

void	put_zeros(t_printf *tab, int n_len)
{
	while (tab->print_len > n_len && tab->print_len > tab->width - n_len - 1)
	{
		tab->ret_len += write(1, "0", 1);
		--tab->print_len;
	}
}
