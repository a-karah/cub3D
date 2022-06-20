/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:11:14 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/18 20:44:45 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	checks  for  white-space  characters.  In the "C" and "POSIX"
**			locales, these are: space, form-feed ('\\f'), newline ('\\n'),
**			carriage return ('\\r'),  horizontal  tab  ('\\t'),  and
**			vertical tab ('\\v').
**	
**	@param	c		character to check
**	@return	int		1 if character is white-space, 0 otherwise
*/
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}
