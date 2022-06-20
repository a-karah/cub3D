/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:37:57 by akarahan          #+#    #+#             */
/*   Updated: 2022/01/29 13:37:59 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	clear_specifier(t_printf *tab)
{
	tab->flags = 0;
	tab->width = 0;
	tab->precis = 0;
	tab->print_len = 0;
}

static void	parse_specifier(t_printf *tab)
{
	while (!ft_strchr("cspdiuxX%", *tab->ptr))
	{
		if (*tab->ptr == '#' && ++tab->ptr)
			tab->flags |= FL_HASH;
		while (*tab->ptr == '0' && ++tab->ptr)
			tab->flags |= FL_ZERO;
		if (*tab->ptr == '-' && ++tab->ptr)
			tab->flags |= FL_MINUS;
		if (*tab->ptr == ' ' && ++tab->ptr)
			tab->flags |= FL_SPACE;
		if (*tab->ptr == '+' && ++tab->ptr)
			tab->flags |= FL_PLUS;
		if ('1' <= *tab->ptr && *tab->ptr <= '9')
			tab->width = ft_atoi(tab->ptr);
		if (*tab->ptr == '.' && ++tab->ptr)
		{
			tab->flags |= FL_DOT;
			tab->precis = ft_atoi(tab->ptr);
		}
		while (ft_isdigit(*tab->ptr))
			++tab->ptr;
	}
	tab->type = *tab->ptr;
}

static void	print_specifier(t_printf *tab)
{
	parse_specifier(tab);
	if (tab->type == 'd' || tab->type == 'i')
		print_nbr(tab, 10, 1);
	if (tab->type == 'u')
		print_nbr(tab, 10, 0);
	if (tab->type == 'x' || tab->type == 'X')
		print_nbr(tab, 16, 0);
	if (tab->type == 'p')
		print_ptr(tab);
	if (tab->type == 'c')
		print_char(tab);
	if (tab->type == 's')
		print_str(tab);
	if (tab->type == '%')
		tab->ret_len += write(1, "%", 1);
	clear_specifier(tab);
}

static int	print_format(const char *fmt, t_printf *tab)
{
	tab->ptr = fmt;
	while (*tab->ptr)
	{
		if (*tab->ptr == '%' && *(++tab->ptr))
			print_specifier(tab);
		else
			tab->ret_len += write(1, tab->ptr, 1);
		++tab->ptr;
	}
	return (tab->ret_len);
}

int	ft_printf(const char *fmt, ...)
{
	int			ret_len;
	t_printf	*tab;

	tab = (t_printf *)malloc(sizeof(*tab));
	if (!tab)
		return (-1);
	va_start(tab->args, fmt);
	tab->flags = 0;
	tab->width = 0;
	tab->precis = 0;
	tab->ret_len = 0;
	tab->print_len = 0;
	tab->ptr = NULL;
	ret_len = print_format(fmt, tab);
	va_end(tab->args);
	free(tab);
	return (ret_len);
}
