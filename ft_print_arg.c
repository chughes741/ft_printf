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

static int	put_nbr(modifiers *mod, void *arg)
{
	(void)mod;
	(void)arg;
	return (0);
}

static int	put_str(modifiers *mod, void *arg)
{
	(void)mod;
	(void)arg;
	return (0);
}

static int	put_hex(modifiers *mod, void *arg)
{
	(void)mod;
	(void)arg;
	return (0);
}

int	ft_print_arg(modifiers *mod, void *arg)
{ // TODO add count
	int	count;

	count = 0;
	if(mod->specifier == 'i' || mod->specifier == 'd' || mod->specifier == 'u')
		count += put_nbr(mod, arg); // TODO conversion, account for u
	if(mod->specifier == 'c' || mod->specifier == 's')
		count += put_str (mod, arg);
	if(mod->specifier == 'x' || mod->specifier == 'X')
		count += put_hex(mod, arg);
	// Add print for pointers
	return (count);
}
