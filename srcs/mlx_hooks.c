/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:57:36 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/13 13:08:13 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	is_key(int key)
{
	return (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY
		|| key == LEFT || key == RIGHT
		|| key == SCROLL_UP || key == SCROLL_DOWN);
}

int	key_hook(int keycode, t_player *pl)
{
	if (keycode == ESC)
		ft_close(pl);
	if (keycode == LEFT)
		rotate(pl, -1);
	if (keycode == RIGHT)
		rotate(pl, 1);
	if (keycode == W_KEY)
		move_forward_backward(pl, 1);
	if (keycode == S_KEY)
		move_forward_backward(pl, -1);
	if (keycode == A_KEY)
		move_left_right(pl, -1);
	if (keycode == D_KEY)
		move_left_right(pl, 1);
	if (is_key(keycode))
	{
		ft_bzero(pl->mlx->img.addr, WIDTH * HEIGHT * (pl->mlx->img.bpp / 8));
		draw_loop(pl);
	}
	return (0);
}

int	mouse_hook(int x, int y, t_player *pl)
{
	int		dx;
	int		dy;
	float	rot;

	dx = WIDTH / 2 - x;
	dy = HEIGHT / 2 - y;
	dx /= WIDTH;
	dy /= HEIGHT;
	rot = dy * 60;
	pl->dir->angle = fl_mod_deg(rot);
	pl->dir->x = cos(ft_deg2rad(rot));
	pl->dir->y = sin(ft_deg2rad(rot));
	return (0);
}

int	mouse_scroll(int keycode, int x, int y, t_player *pl)
{
	(void)x;
	(void)y;
	if (keycode == SCROLL_UP)
	{
		pl->dir->angle = fl_mod_deg(pl->dir->angle - 2);
		pl->dir->x = cos(ft_deg2rad(pl->dir->angle));
		pl->dir->y = sin(ft_deg2rad(pl->dir->angle));
	}
	if (keycode == SCROLL_DOWN)
	{
		pl->dir->angle = fl_mod_deg(pl->dir->angle + 2);
		pl->dir->x = cos(ft_deg2rad(pl->dir->angle));
		pl->dir->y = sin(ft_deg2rad(pl->dir->angle));
	}
	if (is_key(keycode))
	{
		ft_bzero(pl->mlx->img.addr, WIDTH * HEIGHT * (pl->mlx->img.bpp / 8));
		draw_loop(pl);
	}
	return (0);
}

int	ft_close(t_player *pl)
{
	mlx_destroy_image(pl->mlx->mlx, pl->mlx->img.img);
	mlx_destroy_window(pl->mlx->mlx, pl->mlx->win);
	free_all(pl);
	exit(0);
	return (0);
}
