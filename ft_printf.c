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

	VA functions:
		va_start()	- opens the list
		va_arg()	- access next item in the list
		va_end()	- close the list

	%[flags][width][.precision][length]specifier
*/

int	ft_printf(const char *form, ...)
{
	va_list		args;
	modifiers	*mods;
	int			count;
	char		*format;

	format = (char *)form;
	count = 0;
	va_start(args, form);
	while (*format)
	{
		if (*format == '%')
		{
			mods = ft_get_mods(format);
			ft_print_arg(mods, va_arg(args, void *), &count);
			free(mods);
			while (format && !ft_strchr("%cspdiuxX", *format))
				format++;
		}
		ft_putchar_fd(*format, 1);
		format++;
		count++;
	}
	va_end(args);
	return (count);
}
