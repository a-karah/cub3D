/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:40:51 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/13 13:14:11 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_rgb(char *s)
{
	char	*trim;
	char	*tmp;
	int		i;

	i = 0;
	trim = ft_strtrim(s, " \n\t");
	tmp = trim;
	while (*trim)
	{
		if (!ft_isdigit(*trim))
			handle_errors(RGB_ERR);
		while (ft_isdigit(*trim))
			++trim;
		++i;
		if (!ft_isdigit(*trim) && *trim != ',' && *trim != 0)
			handle_errors(RGB_ERR);
		if (*trim)
			++trim;
	}
	free(tmp);
	if (i > 3)
		handle_errors(RGB_TOO_MANY);
	else if (i < 3)
		handle_errors(RGB_TOO_FEW);
}

int	walls_choose(t_map *data, char *set, int x, int y)
{
	char	**map;
	int		ht;
	int		wd;

	map = data->map;
	ht = data->map_h;
	wd = data->map_w;
	if (is_within(y - 1, x - 1, ht, wd) && !ft_strchr(set, map[y - 1][x - 1]))
		return (1);
	if (is_within(y, x - 1, ht, wd) && !ft_strchr(set, map[y][x - 1]))
		return (1);
	if (is_within(y + 1, x - 1, ht, wd) && !ft_strchr(set, map[y + 1][x - 1]))
		return (1);
	if (is_within(y - 1, x, ht, wd) && !ft_strchr(set, map[y - 1][x]))
		return (1);
	if (is_within(y + 1, x, ht, wd) && !ft_strchr(set, map[y + 1][x]))
		return (1);
	if (is_within(y - 1, x + 1, ht, wd) && !ft_strchr(set, map[y - 1][x + 1]))
		return (1);
	if (is_within(y, x + 1, ht, wd) && !ft_strchr(set, map[y][x + 1]))
		return (1);
	if (is_within(y + 1, x + 1, ht, wd) && !ft_strchr(set, map[y + 1][x + 1]))
		return (1);
	return (0);
}

int	check_sides(char *s, int wd)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		++i;
	return (s[i] != '1' || s[wd - 1] != '1');
}

void	check_walls(t_map *data, char *set)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		data->map_w = ft_strlen(data->map[y]);
		if (check_sides(data->map[y], data->map_w))
			handle_errors(MAP_NOT_CLOSED);
		while (data->map[y][++x])
		{
			if (y == 0 && !ft_strchr(" 1\n", data->map[y][x]))
				handle_errors(MAP_NOT_CLOSED);
			if (y == data->map_h - 1
				&& !ft_strchr(" 1\n", data->map[data->map_h - 1][x]))
				handle_errors(MAP_NOT_CLOSED);
			if (data->map[y][x] == '0' && walls_choose(data, set, x, y))
				handle_errors(MAP_NOT_CLOSED);
		}
	}
}

void	check_map(t_map *data)
{
	char	*set;
	int		dup;
	int		y;

	y = -1;
	dup = 0;
	set = "01NSEW";
	check_walls(data, set);
	while (data->map[++y])
	{
		if (!ft_contains_only(data->map[y], set))
			handle_errors(MAP_ERR);
		dup += ft_set_occurence(data->map[y], "NWES");
	}
	if (dup != 1)
		handle_errors(MAP_ERR);
}
