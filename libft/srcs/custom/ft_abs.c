/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:43:15 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/08 16:43:16 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

float	ft_abs_float(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}
