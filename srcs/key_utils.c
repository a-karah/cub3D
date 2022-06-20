/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:25:53 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/13 13:42:35 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move_forward_backward(t_player *pl, int sign)
{
	t_point	tmp;

	tmp.x = pl->pos->x + sign * pl->dir->x * 3;
	tmp.y = pl->pos->y + sign * pl->dir->y * 3;
	tile2idx(pl->data, &tmp);
	if (pl->data->map[tmp.j][tmp.i] != '1')
	{
		pl->pos->x = tmp.x;
		pl->pos->y = tmp.y;
		tile2idx(pl->data, pl->pos);
	}
}

void	move_left_right(t_player *pl, int sign)
{
	t_point	tmp;

	tmp.angle = fl_mod_deg(pl->dir->angle + 90);
	tmp.x = pl->pos->x + sign * cos(ft_deg2rad(tmp.angle)) * 3;
	tmp.y = pl->pos->y + sign * sin(ft_deg2rad(tmp.angle)) * 3;
	tile2idx(pl->data, &tmp);
	if (pl->data->map[tmp.j][tmp.i] != '1')
	{
		pl->pos->x = tmp.x;
		pl->pos->y = tmp.y;
		tile2idx(pl->data, pl->pos);
	}
}

void	rotate(t_player *pl, int sign)
{
	pl->dir->angle = fl_mod_deg(pl->dir->angle + sign * 2);
	pl->dir->x = cos(ft_deg2rad(pl->dir->angle));
	pl->dir->y = sin(ft_deg2rad(pl->dir->angle));
}
