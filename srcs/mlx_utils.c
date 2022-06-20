/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:21:55 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/13 13:32:19 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_background(t_player *pl)
{
	t_point	start;
	t_point	mid;
	t_point	end;

	start.x = 0;
	start.y = 0;
	mid.x = WIDTH - 1;
	mid.y = HEIGHT / 2;
	end.x = WIDTH - 1;
	end.y = HEIGHT - 1;
	draw_rect(&pl->mlx->img, start, mid, pl->data->ceil_clr);
	mid.x = 0;
	draw_rect(&pl->mlx->img, mid, end, pl->data->floor_clr);
}
