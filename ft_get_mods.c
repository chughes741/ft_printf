/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:26:34 by chughes           #+#    #+#             */
/*   Updated: 2022/04/21 11:26:37 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %[flags][width][.precision]specifier

static char	*ft_get_flags(modifiers *mods, char *format)
{
	while (ft_strchr("-+ #0", *format))
	{
		if (*format == '-')
			mods->dash = 1;
		if (*format == '+')
			mods->plus = 1;
		if (*format == ' ')
			mods->space = 1;
		if (*format == '#')
			mods->hash = 1;
		if (*format == '0')
			mods->zero = 1;
		format++;
	}
	return (format);
}

static char	*ft_get_num(char *format, int *num)
{
	int count;

	count = 0;
	if (*format == '.')
		format++;
	while (format[count] && format[count] >= '0' && format[count] <= '9')
		count++;
	*num = ft_atoi(format);
	return (&format[count]);
}

modifiers	*ft_get_mods(const char *format)
{
	modifiers	*mods;
	char		*fp;

	fp = (char *)(format + 1);
	mods = ft_calloc(1, sizeof(modifiers));
	if (mods == NULL)
		return (NULL);
	fp = ft_get_flags(mods, fp);
	mods->width = -1;
	mods->precision = -1;
	if (ft_isdigit((int)*fp))
		fp = ft_get_num(fp, &mods->width);
	if (*fp == '.')
		fp = ft_get_num(fp, &mods->precision);
	mods->specifier = (char)*fp;
	return (mods);
}
