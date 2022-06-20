/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:16:29 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/05 19:05:16 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printarr(int *arr, int elem)
{
	int	i;

	i = 0;
	while (i < elem)
	{
		ft_printf("%d ", arr[i++]);
		if (i == elem)
			ft_putchar_fd('\n', STDOUT);
	}
}
