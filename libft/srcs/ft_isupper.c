/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:40:29 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/18 20:41:01 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	checks for an uppercase letter.
**	
**	@param	c		character to check
**	@return	int		1 if character is in upper case, 0 otherwise
*/
int	ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}
