/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:32:11 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/10 00:31:47 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*goto_first_rgb(char *s, t_flag *flag, int is_f)
{
	while (*s == 'C' || *s == 'F' || ft_isspace(*s))
		++s;
	if (is_f && flag->dup_floor == FLOOR_CHANGED)
		handle_errors(MAP_DUP_ERR);
	if (!is_f && flag->dup_ceil == CEIL_CHANGED)
		handle_errors(MAP_DUP_ERR);
	if (is_f)
		flag->dup_floor = FLOOR_CHANGED;
	else
		flag->dup_ceil = CEIL_CHANGED;
	return (s);
}

int	str_to_rgb(char *s, t_flag *flag, int is_f)
{
	char	**rgb_arr;
	int		rgb;
	int		tmp;
	int		i;

	i = -1;
	rgb = 0;
	s = goto_first_rgb(s, flag, is_f);
	check_rgb(s);
	rgb_arr = ft_split(s, ',');
	while (rgb_arr[++i])
	{
		if (!ft_isdigit_str(rgb_arr[i]))
			handle_errors(RGB_ERR);
		tmp = ft_atoi(rgb_arr[i]);
		if (tmp > 255 || tmp < 0)
			handle_errors(RGB_OUT_OF_BOUNDS);
		rgb |= tmp << 8 * (2 - i);
	}
	i = -1;
	while (rgb_arr[++i])
		free(rgb_arr[i]);
	free(rgb_arr);
	return (rgb);
}

char	*str_to_path(char *s, char *side)
{
	char	*path;

	if (side != NULL)
		handle_errors(MAP_DUP_ERR);
	while ((ft_isalpha(*s) || ft_isspace(*s)) && *s != '.')
		++s;
	path = ft_strtrim(s, " \n");
	return (path);
}

char	**ft_lst2tab(t_list *head, int *len, int *wd)
{
	char	**tab;
	int		max;
	int		i;

	i = -1;
	*len = ft_lstsize(head);
	tab = (char **)malloc(sizeof(char *) * (*len + 1));
	if (!tab)
		handle_errors(MALLOC_ERR);
	while (++i < *len)
	{
		tab[i] = (char *)head->content;
		max = ft_strlen(tab[i]);
		if (max > *wd)
			*wd = max;
		head = head->next;
	}
	tab[i] = NULL;
	return (tab);
}
