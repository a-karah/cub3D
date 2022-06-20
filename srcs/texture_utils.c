/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:45:10 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/09 23:27:23 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	load_xpm(t_xpm *tex_arr, t_mlx *mlx, int *tex_flag)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		tex_arr[i].tx_img.img = mlx_xpm_file_to_image(mlx->mlx, tex_arr[i].path,
				&tex_arr[i].img_w, &tex_arr[i].img_h);
		++*tex_flag;
	}
	i = -1;
	while (++i < 4)
	{
		if (tex_arr[i].tx_img.img)
				tex_arr[i].tx_img.addr = mlx_get_data_addr(
					tex_arr[i].tx_img.img,
					&tex_arr[i].tx_img.bpp,
					&tex_arr[i].tx_img.line_len,
					&tex_arr[i].tx_img.endian);
		else
			tex_arr[i].tx_img.addr = NULL;
	}
}

float	tex_x_len(t_player *pl, t_ray *ray)
{
	t_point	tile;
	float	diff;
	float	tex_x;

	tile.x = tfm(ray->pos.i, pl->data, 1);
	tile.y = tfm(ray->pos.j, pl->data, 0);
	if (ray->side == NO || ray->side == SO)
		diff = ray->pos.x - tile.x;
	else
		diff = ray->pos.y - tile.y;
	diff /= pl->data->zoom;
	tex_x = diff * pl->tex_arr[ray->side].img_w;
	return (tex_x);
}

int	apply_shading(t_player *pl, t_ray *ray, t_tex tex)
{
	int	r;
	int	g;
	int	b;

	r = get_r(tex.clr) * (1.0 - ray->dist / pl->rend_dist);
	g = get_g(tex.clr) * (1.0 - ray->dist / pl->rend_dist);
	b = get_b(tex.clr) * (1.0 - ray->dist / pl->rend_dist);
	return (create_trgb(0, r, g, b));
}
