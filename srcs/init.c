/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:34:10 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/10 00:14:47 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_map	*init_map(void)
{
	t_map	*data;

	data = (t_map *)malloc(sizeof(t_map));
	data->head = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->map_h = 0;
	data->map_w = 0;
	data->max_w = INT_MIN;
	data->ceil_clr = 0x004f8fba;
	data->floor_clr = 0x00468232;
	data->shift_x = 0;
	data->shift_y = 0;
	data->zoom = 0;
	return (data);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		handle_errors(MALLOC_ERR);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "cub3D");
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.line_len, &mlx->img.endian);
	return (mlx);
}

void	init_xpm(t_player *pl)
{
	pl->tex_flag = 0;
	pl->tex_arr[NO].path = pl->data->no;
	pl->tex_arr[SO].path = pl->data->so;
	pl->tex_arr[WE].path = pl->data->we;
	pl->tex_arr[EA].path = pl->data->ea;
	load_xpm(pl->tex_arr, pl->mlx, &pl->tex_flag);
}

void	init_player(t_player *pl)
{
	pl->pos = find_pos(pl->data->map);
	idx2tile(pl->data, pl->pos);
	pl->dir = find_dir(pl->data->map, pl->pos);
	pl->dir->i = pl->pos->i;
	pl->dir->j = pl->pos->j;
	pl->rend_dist = pl->data->max_w * pl->data->zoom;
	pl->fov = 60;
	init_xpm(pl);
}

void	init_flag(t_flag *flag)
{
	flag->empty_line = WALL_BEFORE_EMPTY_NOT_EXIST;
	flag->dup_floor = FLOOR_NOT_CHANGED;
	flag->dup_ceil = CEIL_NOT_CHANGED;
}
