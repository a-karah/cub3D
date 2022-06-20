/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:43:25 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/08 16:51:09 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min_int(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

float	ft_min_float(float x, float y)
{
	if (x < y)
		return (x);
	return (y);
}

int	ft_min_2d_arr(int **tab, int x_lim, int y_lim)
{
	int	x;
	int	y;
	int	min;

	y = 0;
	min = tab[0][0];
	while (y < y_lim)
	{
		x = 0;
		while (x < x_lim)
		{
			if (min > tab[y][x])
				min = tab[y][x];
			++x;
		}
		++y;
	}
	return (min);
}
