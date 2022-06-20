/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:35:30 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/13 13:32:07 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_isdigit_str(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && !ft_isspace(*s))
			return (0);
		++s;
	}
	return (1);
}

int	ft_contains_only(char	*s, char *set)
{
	while (*s)
	{
		while (!ft_isspace(*s) && !ft_strchr(set, *s))
			return (0);
		++s;
	}
	return (1);
}

int	ft_set_occurence(char *s, char *set)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (ft_strchr(set, *s))
			++i;
		++s;
	}
	return (i);
}

int	is_within(int y, int x, int ht, int wd)
{
	return (x > -1 && y > -1 && x < wd && y < ht);
}
