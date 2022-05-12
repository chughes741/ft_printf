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

static void ft_space_to_zero(char *str)
{
	while (str++ && *str == ' ')
		*str = '0';
	return ;
}

static char	*ft_set_width(char *str, int width) // TODO join memleak
{
	if (ft_strlen(str) >= (unsigned long)width)
		return (str);
	width -= ft_strlen(str);
	while((width--) > 0)
		str = ft_strjoin(" ", str);
	return (str);
}

static void ft_set_precision(char *str, int precision) // TODO positional value
{
	while (str[precision++])
		str[precision] = '0';
}

static void	ft_left_justify(char *str)
{
	char	*temp;

	temp = ft_strtrim(str, " ");
	ft_memset(str, ' ', ft_strlen(str) * sizeof(char));
	ft_strlcpy(str, temp, ft_strlen(temp));
	free(temp);
	return ;
}

static char	*ft_format(modifiers *mod, char *str)
{ // TODO fix leaks when strjoin is called
	if (mod->precision >= 0)
		ft_set_precision(str, mod->precision);
	if (mod->width >= 0)
		str = ft_set_width(str, mod->width);
	if (mod->hash || mod->specifier == 'p')
		str = ft_strjoin("0x", str);
	if (mod->plus)
		str = ft_strjoin("+", str);
	if (mod->dash)
		ft_left_justify(str);
	if (mod->space && str[0] != ' ')
		str = ft_strjoin(" ", str);
	if (mod->zero)
		ft_space_to_zero(str);
	return (str);
}

void	ft_print_arg(modifiers *mod, void *arg, int *count)
{
	char	*output;
	if(mod->specifier == 'c' || mod->specifier == 's')
		output = ft_strdup((char *)arg);
	if(mod->specifier == 'd' || mod->specifier == 'i' || \
	mod->specifier == 'u')
		output = ft_itoa(*((int *)arg)); // TODO modify itoa for unsigned
	if(mod->specifier == 'x' || mod->specifier == 'X' || \
	mod->specifier == 'p')
		output = ft_itox(*((int *)arg)); // TODO fix 0's in itox
	if (output == NULL)
		return ;
	output = ft_format(mod, output);
	ft_putstr_fd(output, 1);
	*count += ft_strlen(output);
	free(output);
	return ;
}
