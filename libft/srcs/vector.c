/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:02:44 by akarahan          #+#    #+#             */
/*   Updated: 2022/05/02 18:05:24 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vf2d	*vf2d_new(float x, float y)
{
	t_vf2d	*ptr;

	ptr = (t_vf2d *)malloc(sizeof(t_vf2d));
	if (ptr)
		return (NULL);
	ptr->x = x;
	ptr->y = y;
	return (ptr);
}

t_vi2d	*vi2d_new(int x, int y)
{
	t_vi2d	*ptr;

	ptr = (t_vi2d *)malloc(sizeof(t_vi2d));
	if (ptr)
		return (NULL);
	ptr->x = x;
	ptr->y = y;
	return (ptr);
}
