/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:43:34 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/08 16:48:32 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_int(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

float	ft_max_float(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

int	ft_max_2d_arr(int **tab, int x_lim, int y_lim)
{
	int	x;
	int	y;
	int	max;

	y = 0;
	max = tab[0][0];
	while (y < y_lim)
	{
		x = 0;
		while (x < x_lim)
		{
			if (max < tab[y][x])
				max = tab[y][x];
			++x;
		}
		++y;
	}
	return (max);
}
