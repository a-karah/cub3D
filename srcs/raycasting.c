/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:12:41 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/13 13:09:19 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	prepare_ray(t_ray *rc, t_map *dt, t_point pos)
{
	rc->dist = 0;
	rc->step_x = ft_dist(rc->dir_x, rc->dir_y);
	rc->step_y = ft_dist(rc->dir_y, rc->dir_x);
	if (rc->dir_x < 0)
	{
		rc->dx = -1;
		rc->side_x = (pos.x - tfm(rc->pos.i, dt, 1)) * rc->step_x;
	}
	else
	{
		rc->dx = 1;
		rc->side_x = (tfm(rc->pos.i + 1, dt, 1) - pos.x) * rc->step_x;
	}
	if (rc->dir_y < 0)
	{
		rc->dy = -1;
		rc->side_y = (pos.y - tfm(rc->pos.j, dt, 0)) * rc->step_y;
	}
	else
	{
		rc->dy = 1;
		rc->side_y = (tfm(rc->pos.j + 1, dt, 0) - pos.y) * rc->step_y;
	}
}

void	raycasting(t_ray *ray, t_map *dt)
{
	while (ray->dist < 10000 && dt->map[ray->pos.j][ray->pos.i] == '0')
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side = WE;
			if (ray->dx > 0)
				ray->side = EA;
			ray->pos.i += ray->dx;
			ray->dist = ray->side_x;
			ray->shade = 0.5;
			ray->side_x = ray->side_x + (ray->step_x * dt->zoom);
		}
		else
		{
			ray->side = NO;
			if (ray->dy > 0)
				ray->side = SO;
			ray->pos.j += ray->dy;
			ray->dist = ray->side_y;
			ray->shade = 1;
			ray->side_y = ray->side_y + (ray->step_y * dt->zoom);
		}
	}
	ray->pos.x = ray->pos.x + ray->dir_x * ray->dist;
	ray->pos.y = ray->pos.y + ray->dir_y * ray->dist;
}

void	draw_slice(t_player *pl, t_ray *ray, int x, int step)
{
	float	line_ht;
	t_point	start;
	t_point	end;
	int		i;

	i = x - 1;
	line_ht = (int)(pl->data->zoom * HEIGHT / (ray->dist
				* cos(ft_deg2rad(ray->pos.angle - pl->dir->angle))));
	start.y = HEIGHT / 2 - line_ht / 2;
	if (start.y < 0)
		start.y = 0;
	end.y = line_ht / 2 + HEIGHT / 2;
	if (end.y >= HEIGHT)
		end.y = HEIGHT - 1;
	while (++i < x + step)
	{
		start.x = i;
		end.x = i;
		draw_line(&pl->mlx->img, start, end, BLUE
			* (1.0 - ray->dist / pl->rend_dist) * ray->shade);
	}
}

void	draw_tex(t_player *pl, t_ray *ray, int x)
{
	float	line_ht;
	t_point	start;
	t_point	end;
	t_tex	tex;

	line_ht = (int)(pl->data->zoom * HEIGHT / (ray->dist
				* cos(ft_deg2rad(ray->pos.angle - pl->dir->angle))));
	start.y = HEIGHT / 2 - line_ht / 2;
	if (start.y < 0)
		start.y = 0;
	end.y = line_ht / 2 + HEIGHT / 2;
	if (end.y >= HEIGHT)
		end.y = HEIGHT - 1;
	tex.x = tex_x_len(pl, ray);
	tex.step = 1.0 * pl->tex_arr[ray->side].img_h / line_ht;
	tex.pos = (start.y - HEIGHT / 2 + line_ht / 2) * tex.step;
	while (start.y < end.y)
	{
		tex.y = (int) tex.pos & (pl->tex_arr[ray->side].img_h - 1);
		tex.clr = get_pixel(&pl->tex_arr[ray->side].tx_img, tex.x, tex.y);
		pixel_put(&pl->mlx->img, x, start.y, apply_shading(pl, ray, tex));
		tex.pos += tex.step;
		++start.y;
	}
}

t_ray	*find_rays(t_player *pl, int num_rays)
{
	t_ray	*rays;
	float	deg;
	int		x;
	int		r;

	x = 0;
	r = -1;
	deg = fl_mod_deg(pl->dir->angle - (pl->fov / 2));
	rays = (t_ray *)malloc(sizeof(t_ray) * num_rays);
	while (++r < num_rays)
	{
		rays[r].pos = *pl->pos;
		rays[r].dir_x = cos(ft_deg2rad(deg));
		rays[r].dir_y = sin(ft_deg2rad(deg));
		rays[r].pos.angle = deg;
		prepare_ray(&rays[r], pl->data, *pl->pos);
		raycasting(&rays[r], pl->data);
		if (pl->tex_arr[rays[r].side].tx_img.addr == NULL)
			draw_slice(pl, &rays[r], x, WIDTH / num_rays);
		else
			draw_tex(pl, &rays[r], x);
		deg += fl_mod_deg((pl->fov / num_rays));
		x += WIDTH / num_rays;
	}
	return (rays);
}
