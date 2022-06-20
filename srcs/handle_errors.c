/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:12:43 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/09 23:46:50 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		handle_errors(EXT_ERR);
	if (ft_strncmp(path + len - 4, ".cub", 4))
		handle_errors(EXT_ERR);
}

void	handle_errors(int err)
{
	ft_putendl_fd("Error", STDERR);
	if (err == FILE_ERR)
		perror("File does not open: ");
	else if (err == MALLOC_ERR)
		perror("Malloc failed: ");
	else if (err == RGB_ERR)
		ft_putendl_fd("RGB is not digit", STDERR);
	else if (err == RGB_OUT_OF_BOUNDS)
		ft_putendl_fd("RGB is out of range", STDERR);
	else if (err == RGB_TOO_MANY)
		ft_putendl_fd("RGB too many numbers given", STDERR);
	else if (err == RGB_TOO_FEW)
		ft_putendl_fd("RGB too few numbers given", STDERR);
	else if (err == MAP_DUP_ERR)
		ft_putendl_fd("Map have duplicated utility", STDERR);
	else if (err == MAP_NOT_CLOSED)
		ft_putendl_fd("Map is not closed", STDERR);
	else if (err == EXT_ERR)
		ft_putendl_fd("Map extension is not .cub", STDERR);
	else if (err == MAP_ERR)
		ft_putendl_fd("Map error", STDERR);
	else
		perror(NULL);
	exit(1);
}
