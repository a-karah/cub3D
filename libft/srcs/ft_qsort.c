/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:09:44 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/09 13:08:04 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(int *arr, int lo, int hi)
{
	int	piv;
	int	i;
	int	j;

	piv = arr[(hi + lo) / 2];
	i = lo - 1;
	j = hi + 1;
	while (1)
	{
		while (arr[++i] < piv)
			;
		while (arr[--j] > piv)
			;
		if (i >= j)
			return (j);
		ft_swap(&arr[i], &arr[j]);
	}
}

void	ft_qsort(int *arr, int lo, int hi)
{
	int	p;

	if (lo > -1 && hi > -1 && lo < hi)
	{
		p = partition(arr, lo, hi);
		ft_qsort(arr, lo, p);
		ft_qsort(arr, p + 1, hi);
	}
}
