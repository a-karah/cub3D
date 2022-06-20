/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:39:54 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/18 20:39:54 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	checks for a lowercase character.
**	
**	@param	c		character to check
**	@return	int		1 if character is in lower case, 0 otherwise
*/
int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}
