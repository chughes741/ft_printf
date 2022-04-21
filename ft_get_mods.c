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
	(void)mods;
	(void)format;
	return ;
}

static void ft_get_precision(modifiers *mods, const char *format)
{
	(void)mods;
	(void)format;
	return ;
}

modifiers	*ft_get_mods(const char *format)
{
	modifiers	*mods;
	char		*fp;

	fp = (char *)format;
	mods = ft_calloc(1, sizeof(modifiers));
	if (mods == NULL)
		return (NULL);
	mods->skip = 1;
	ft_get_flags(mods, fp);
	mods->width = -1;
	mods->precision = -1;
	if (ft_isdigit((int)*fp))
		ft_get_width(mods, fp);
	if (*fp == '.' && mods->width >= 0)
		ft_get_precision(mods, fp);
	mods->specifier = (char)*fp; 
	return (mods);
}
