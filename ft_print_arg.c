/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:55:14 by chughes           #+#    #+#             */
/*   Updated: 2022/04/21 13:55:18 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_char(void *arg, int *count)
{
	ft_putchar_fd((char)arg, 1);
	count += 1;
	return ;
}

static void	put_str(modifiers *mod, void *arg, int *count)
{
	(void)mod;
	(void)count;
	ft_putstr_fd((char *)arg, 1);
	return ;
}

static void put_ptr(void *arg, int *count)
{
	char	*str;

	*count += 10;
	write(1, "0x", 2);
	str = ft_itox((int)arg);
	ft_putstr_fd(str, 1);
	return ;
}

static void put_int(modifiers *mod, void *arg, int *count)
{
	(void)count;
	char	*str;

	if (mod->plus == 1)
		write(1, "+", 1);
	str = ft_itoa((int)arg);
	ft_putstr_fd(str, 1);
	return ;
}

static void put_uint(modifiers *mod, void *arg, int *count)
{
	(void)mod;
	(void)count;
	char	*str;

	str = ft_itoa((int)arg);
	ft_putstr_fd(str, 1);
	return ;
}

static void put_hex(modifiers *mod, void *arg, int *count)
{
	(void)count;
	char	*str;

	if (mod->hash == 1)
	{
		write(1, "0", 1);
		write(1, &mod->specifier, 1);
	}
	str = ft_itox((int)arg);
	ft_putstr_fd(str, 1);
	return ;
}

void	ft_print_arg(modifiers *mod, void *arg, int *count)
{
	if(mod->specifier == 'c')
		put_char(arg, count);
	if(mod->specifier == 's')
		put_str(mod, arg, count);
	if(mod->specifier == 'p')
		put_ptr(arg, count);
	if(mod->specifier == 'd' || mod->specifier == 'i')
		put_int(mod, arg, count);
	if(mod->specifier == 'u')
		put_uint(mod, arg, count);
	if(mod->specifier == 'x' || mod->specifier == 'X')
		put_hex(mod, arg, count);
	return ;
}
