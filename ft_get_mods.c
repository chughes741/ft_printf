/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:26:34 by chughes           #+#    #+#             */
/*   Updated: 2022/04/21 11:26:37 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %[flags][width][.precision]specifier

static void	ft_get_flags(modifiers *mods, const char *format)
{
	while (ft_strchr("-+ #0", *format))
	{
		mods->skip += 1;
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
	return ;
}

static void	ft_get_width(modifiers *mods, const char *format)
{
	return ;
}

static void ft_get_precision(modifiers *mods, const char *format)
{
	return ;
}

modifiers	*ft_get_mods(const char *format)
{
	modifiers	*mods;

	mods = ft_calloc(1, sizeof(modifiers));
	if (mods == NULL)
		return (NULL);
	ft_get_flags(mods, format);
	mods->width = -1;
	mods->precision = -1;
	if (ft_isdigit((int)*format))
		ft_get_width(mods, format);
	if (*format == '.' && mods->width >= 0)
		ft_get_precision(mods, format);
	mods->specifier = (char)*format; 
	return (mods);
}
