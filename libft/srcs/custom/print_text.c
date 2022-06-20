/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:38:35 by akarahan          #+#    #+#             */
/*   Updated: 2022/01/29 13:46:14 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_printf *tab)
{
	unsigned char	c;

	c = va_arg(tab->args, int);
	if (tab->flags & FL_MINUS)
		tab->ret_len += write(1, &c, 1);
	while (tab->width > 1)
	{
		tab->ret_len += write(1, " ", 1);
		--tab->width;
	}
	if (!(tab->flags & FL_MINUS))
		tab->ret_len += write(1, &c, 1);
}

static void	put_str(t_printf *tab, const char *s)
{
	if (!s)
		tab->ret_len += write(1, "(null)", tab->print_len);
	else
		tab->ret_len += write(1, s, tab->print_len);
}

static void	put_sspace(t_printf *tab)
{
	while (tab->width > tab->print_len)
	{
		tab->ret_len += write(1, " ", 1);
		--tab->width;
	}
}

void	print_str(t_printf *tab)
{
	const char	*s;
	int			i;

	i = 0;
	s = va_arg(tab->args, char *);
	if (!s)
		i = 6;
	else
	{
		while (s[i])
			i++;
	}
	if ((tab->flags & FL_DOT) && tab->precis < i)
		i = tab->precis;
	tab->print_len = i;
	if (!(tab->flags & FL_MINUS))
		put_sspace(tab);
	put_str(tab, s);
	if (tab->flags & FL_MINUS)
		put_sspace(tab);
}
