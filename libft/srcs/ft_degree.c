/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 22:09:05 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/13 13:30:49 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_deg2rad(float deg)
{
	return (deg * C_PI / 180);
}

float	ft_rad2deg(float rad)
{
	return (rad * 180 / C_PI);
}

int	mod_deg(int deg)
{
	return (deg % 360);
}

float	fl_mod_deg(float deg)
{
	if ((int) deg > 360 || (int) deg < -360)
		return ((int) deg % 360);
	return (deg);
}
