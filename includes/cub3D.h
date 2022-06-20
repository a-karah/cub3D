/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:33:37 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/13 13:42:25 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "../minilibx_opengl/mlx.h"
# include "../libft/includes/libft.h"

# define WIDTH 1024
# define HEIGHT 780
# define MINIMAP_W 300

# ifdef __APPLE__

enum e_keys {
	IS_MAC = 90,
	ESC = 53,
	LEFT = 123,
	RIGHT = 124,
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2
};

# endif

# ifdef __linux__

enum e_keys {
	IS_MAC = 91,
	ESC = 65307,
	LEFT = 65361,
	RIGHT = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
};

# endif

enum e_err
{
	FILE_ERR,
	MALLOC_ERR,
	RGB_ERR,
	RGB_OUT_OF_BOUNDS,
	RGB_TOO_MANY,
	RGB_TOO_FEW,
	MAP_DUP_ERR,
	MAP_EXCESS_CHAR,
	MAP_NOT_CLOSED,
	EXT_ERR,
	MAP_ERR
};

enum e_general
{
	ON_DESTROY = 17,
	ON_MOUSEMOVE = 6,
	BLUE = 0x000000FF,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3
};

enum e_flag
{
	WALL_BEFORE_EMPTY_NOT_EXIST,
	EMPTY_AFTER_WALL_EXIST,
	WALL_AFTER_EMPTY_EXIST,
	FLOOR_NOT_CHANGED,
	FLOOR_CHANGED,
	CEIL_NOT_CHANGED,
	CEIL_CHANGED
};

typedef struct s_flag
{
	int	empty_line;
	int	dup_ceil;
	int	dup_floor;
}				t_flag;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_clr;
	int		ceil_clr;
	char	**map;
	t_list	*head;
	int		map_h;
	int		map_w;
	int		max_w;
	int		zoom;
	int		shift_x;
	int		shift_y;
}				t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_xpm
{
	t_img	tx_img;
	char	*path;
	int		img_w;
	int		img_h;
}				t_xpm;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_mlx;

typedef struct s_point
{
	float	x;
	float	y;
	int		i;
	int		j;
	float	angle;
}				t_point;

typedef struct s_ray
{
	t_point	pos;
	float	step_x;
	float	step_y;
	float	side_x;
	float	side_y;
	float	dir_x;
	float	dir_y;
	float	dist;
	int		dx;
	int		dy;
	float	shade;
	int		side;
}				t_ray;

typedef struct s_tex
{
	int		x;
	int		y;
	float	pos;
	float	step;
	int		clr;
}				t_tex;

typedef struct s_player
{
	t_map	*data;
	t_mlx	*mlx;
	t_point	*pos;
	t_point	*dir;
	t_xpm	tex_arr[4];
	int		tex_flag;
	int		rend_dist;
	float	fov;
}				t_player;

/* handle_errors.c */
void			check_extension(char *path);
void			handle_errors(int err);

/* parse_map.c */
t_map			*parse_map(char *fname);

/* utils.c */
int				ft_isdigit_str(char *s);
int				ft_contains_only(char	*s, char *set);
int				ft_set_occurence(char *s, char *set);
int				is_within(int y, int x, int ht, int wd);

/* color_utils.c */
int				create_trgb(unsigned char t, unsigned char r, unsigned char g,
					unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

/* parse_utils.c */
int				str_to_rgb(char *s, t_flag *flag, int is_floor);
char			*str_to_path(char *s, char *side);
char			**ft_lst2tab(t_list *head, int *len, int *wd);
char			*goto_first_rgb(char *s, t_flag *flag, int is_f);

/* init.c */
t_map			*init_map(void);
t_mlx			*init_mlx(void);
void			init_player(t_player *pl);
void			init_flag(t_flag *flag);

/* free_all.c */
void			free_all(t_player *pl);
void			free_content(void *content);

/* check_map.c */
void			check_rgb(char *s);
void			check_map(t_map *data);

/* draw_win.c */
void			draw_loop(t_player *p);
void			draw_screen(t_player *p);
void			draw_line(t_img *img, t_point a, t_point b, int clr);
void			draw_rect(t_img *img, t_point a, t_point b, int clr);

/* mlx_utils.c */
void			pixel_put(t_img *img, int x, int y, int color);
void			draw_background(t_player *pl);
int				get_pixel(t_img *img, int x, int y);

/* mlx_hooks.c */
int				key_hook(int keycode, t_player *p);
int				mouse_scroll(int keycode, int x, int y, t_player *pl);
int				ft_close(t_player *p);
int				mouse_hook(int x, int y, t_player *pl);

/* player.c */
t_point			*find_pos(char **map);
t_point			*find_dir(char **map, t_point *pos);

/* draw_utils.c */
float			ft_dist(float x, float y);
float			tfm(int nb, t_map *dt, int x);
int				dtfm(float nb, t_map *dt, int x);
void			idx2tile(t_map *data, t_point *pt);
void			tile2idx(t_map *data, t_point *pt);

/* raycasting.c */
void			raycasting(t_ray *ray, t_map *dt);
void			draw_slice(t_player *pl, t_ray *ray, int x, int step);
t_ray			*find_rays(t_player *pl, int num_rays);
void			draw_tex(t_player *pl, t_ray *ray, int x);

/* texture_utils.c */
void			load_xpm(t_xpm *tex_arr, t_mlx *mlx, int *tex_flag);
float			tex_x_len(t_player *pl, t_ray *ray);
int				apply_shading(t_player *pl, t_ray *ray, t_tex tex);

/* key_utils.c */
void			move_forward_backward(t_player *pl, int sign);
void			move_left_right(t_player *pl, int sign);
void			rotate(t_player *pl, int sign);

#endif
