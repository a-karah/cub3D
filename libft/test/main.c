/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:42:24 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/18 19:59:53 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include "../includes/get_next_line.h"

void	open_files(int *fd1, int *fd2, int *fd3)
{
	*fd1 = open("./test/alice1.txt", O_RDONLY);
	*fd2 = open("./test/alice2.txt", O_RDONLY);
	*fd3 = open("./test/alice3.txt", O_RDONLY);
}

void	close_files(int fd1, int fd2, int fd3)
{
	close(fd1);
	close(fd2);
	close(fd3);
}

void	get_line_and_print(int fd1, int fd2, int fd3)
{
	char	*line;
	int		i;

	i = 0;
	while (++i < 22)
	{
		line = get_next_line(fd1);
		ft_printf("fd_1 %2d| %s", i, line);
		if (!line)
			ft_printf("\n");
		free(line);
		line = get_next_line(fd2);
		ft_printf("fd_2 %2d| %s", i, line);
		if (!line)
			ft_printf("\n");
		free(line);
		line = get_next_line(fd3);
		ft_printf("fd_3 %2d| %s", i, line);
		if (!line)
			ft_printf("\n");
		free(line);
	}
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;

	open_files(&fd1, &fd2, &fd3);
	get_line_and_print(fd1, fd2, fd3);
	close_files(fd1, fd2, fd3);
	return (0);
}
