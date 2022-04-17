/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:22:32 by chughes           #+#    #+#             */
/*   Updated: 2022/04/17 15:22:35 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
	Needs to handle c, s, p, d, i, u, x, X, and % 
	No buffer management
	Bonuses: 
		'-'	left justify
		'0'	field is padded with 0's instead of spaces
		'.'	precision, x.y, x is total number, y is total to the right
		'+'	sign of number is always displayed
		' '	blank space instead of sign
		'#'	adds hex prefixes, like 0x
*/

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	va_end(args);
	return (0);
}
