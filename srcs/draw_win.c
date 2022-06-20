/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:18:23 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/13 13:07:24 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_screen(t_player *pl)
{
	t_mlx	*mlx;

	mlx = pl->mlx;
	draw_loop(pl);
	if (IS_MAC == 90)
		mlx_hook(mlx->win, 2, 1L << 0, key_hook, pl);
	else
		mlx_key_hook(mlx->win, key_hook, pl);
	mlx_mouse_hook(mlx->win, mouse_scroll, pl);
	mlx_hook(mlx->win, ON_DESTROY, 1L << 2, ft_close, pl);
	mlx_loop(mlx->mlx);
}

void	draw_minimap(t_player *pl, int i, int j)
{
	t_point	a;
	t_point	b;

	a.x = i * pl->data->zoom + pl->data->shift_x;
	a.y = j * pl->data->zoom + pl->data->shift_y;
	b.x = (i + 1) * pl->data->zoom + pl->data->shift_x;
	b.y = (j + 1) * pl->data->zoom + pl->data->shift_y;
	if (pl->data->map[j][i] == '1')
		draw_rect(&pl->mlx->img, a, b, create_trgb(50, 255, 255, 255));
	if (pl->data->map[j][i] == '0')
		draw_rect(&pl->mlx->img, a, b, create_trgb(50, 0, 0, 0));
	b.x = (i + 1) * pl->data->zoom + pl->data->shift_x;
	b.y = j * pl->data->zoom + pl->data->shift_y;
	if (pl->data->map[j][i] != ' ')
		draw_line(&pl->mlx->img, a, b, create_trgb(50, 150, 150, 150));
	b.x = a.x;
	b.y = (j + 1) * pl->data->zoom + pl->data->shift_y;
	if (pl->data->map[j][i] != ' ')
		draw_line(&pl->mlx->img, a, b, create_trgb(50, 150, 150, 150));
}

void	draw_line(t_img *img, t_point a, t_point b, int clr)
{
	float	max;
	float	dx;
	float	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	max = ft_max_float(ft_abs_float(dx), ft_abs_float(dy));
	dx /= max;
	dy /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (is_within(a.y, a.x, HEIGHT, WIDTH))
			pixel_put(img, a.x, a.y, clr);
		a.x += dx;
		a.y += dy;
	}
}

void	draw_rect(t_img *img, t_point a, t_point b, int clr)
{
	float	max;
	float	tmp;
	float	dx;
	float	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	max = ft_max_float(ft_abs_float(dx), ft_abs_float(dy));
	dx /= max;
	dy /= max;
	tmp = a.x;
	while ((int)(a.y - b.y))
	{
		a.x = tmp;
		while ((int)(a.x - b.x))
		{
			if (is_within(a.y, a.x, HEIGHT, WIDTH))
				pixel_put(img, a.x, a.y, clr);
			a.x += dx;
		}
		a.y += dy;
	}
}

void	draw_loop(t_player *pl)
{
	t_ray	*rays;
	int		i;
	int		j;
	int		num_rays;

	j = -1;
	num_rays = WIDTH;
	draw_background(pl);
	rays = find_rays(pl, num_rays);
	while (++j < pl->data->map_h)
	{
		i = -1;
		pl->data->map_w = (int)ft_strlen(pl->data->map[j]);
		while (++i < pl->data->map_w)
			draw_minimap(pl, i, j);
	}
	i = -1;
	while (++i < num_rays)
		draw_line(&pl->mlx->img, *pl->pos, rays[i].pos, 0x0059C2FF);
	free(rays);
	mlx_put_image_to_window(pl->mlx->mlx, pl->mlx->win, pl->mlx->img.img, 0, 0);
}
