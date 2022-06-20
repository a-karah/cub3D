/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:08:40 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/10 00:28:00 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_choose(t_list **head, t_map *map, char *line, t_flag *flag)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		map->no = str_to_path(line, map->no);
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		map->so = str_to_path(line, map->so);
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		map->we = str_to_path(line, map->we);
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		map->ea = str_to_path(line, map->ea);
	else if (ft_strchr(line, 'F'))
		map->floor_clr = str_to_rgb(line, flag, 1);
	else if (ft_strchr(line, 'C'))
		map->ceil_clr = str_to_rgb(line, flag, 0);
	else if (ft_lstsize(*head) > 0 && *line == '\n')
		flag->empty_line = EMPTY_AFTER_WALL_EXIST;
	else if (*line != '\n' && *line != 0)
	{
		if (flag->empty_line == EMPTY_AFTER_WALL_EXIST)
			flag->empty_line = WALL_AFTER_EMPTY_EXIST;
		ft_lstadd_back(head, ft_lstnew(ft_strtrim(line, "\n")));
	}	
}

int	find_zoom(t_map *data)
{
	float	zoom;

	zoom = 0;
	while (zoom * data->max_w < MINIMAP_W)
		zoom += 0.1;
	return ((int)zoom);
}

t_map	*parse_map(char *fname)
{
	t_map	*data;
	char	*line;
	int		fd;
	t_flag	flag;

	data = init_map();
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		handle_errors(FILE_ERR);
	line = get_next_line(fd);
	init_flag(&flag);
	while (line)
	{
		ft_choose(&data->head, data, line, &flag);
		free(line);
		if (flag.empty_line == WALL_AFTER_EMPTY_EXIST)
			handle_errors(MAP_NOT_CLOSED);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	data->map = ft_lst2tab(data->head, &data->map_h, &data->max_w);
	check_map(data);
	data->zoom = find_zoom(data);
	return (data);
}
