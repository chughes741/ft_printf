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

static void	ft_space_to_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
	{
		str[i] = '0';
		i++;
	}
	return ;
}

static char	*ft_set_width(char *str, int width)
{
	if (ft_strlen(str) >= (unsigned long)width)
		return (str);
	width -= ft_strlen(str);
	while ((width--) > 0)
		str = ft_str_append(" ", str);
	return (str);
}

static void	ft_left_justify(char *str)
{
	int	i;
	int	j;

	if (str[0] != ' ')
		return ;
	i = 0;
	j = 0;
	while (str[j] == ' ')
		j++;
	while (str[j])
	{
		str[i] = str[j];
		str[j] = ' ';
		i++;
		j++;
	}
	return ;
}

static void	ft_strupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] ^= 1 << 5;
		i++;
	}
}

static int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

static char	*ft_format(t_mod *mod, char *str)
{
	if (mod->width >= 0 && mod->width >= mod->precision)
		str = ft_set_width(str, mod->width);
	else if (mod->precision >= 0 && mod->precision > mod->width)
		str = ft_set_width(str, mod->precision);
	if (mod->hash || mod->specifier == 'p')
		str = ft_str_append("0x", str);
	if (mod->specifier == 'X')
		ft_strupper(str);
	if (mod->plus)
		str = ft_str_append("+", str);
	if (mod->dash)
		ft_left_justify(str);
	if (mod->space && str[0] != ' ')
		str = ft_str_append(" ", str);
	if (mod->zero)
		ft_space_to_zero(str);
	return (str);
}

void	ft_print_arg(t_mod *mod, va_list args, int *count)
{
	char	*output;

	output = NULL;
	if (mod->specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	if (mod->specifier == 's')
		output = ft_strdup(va_arg(args, char *));
	if (mod->specifier == 'd' || mod->specifier == 'i')
		output = ft_itoa(va_arg(args, int));
	if (mod->specifier == 'u')
		output = ft_utoa(va_arg(args, unsigned int));
	if (mod->specifier == 'x' || mod->specifier == 'X')
		output = ft_itox(va_arg(args, unsigned int));
	if (mod->specifier == 'p')
		output = ft_ptoa((va_arg(args, uintptr_t)));
	if (output == NULL)
		return ;
	output = ft_format(mod, output);
	ft_putstr_fd(output, 1);
	*count += ft_strlen(output);
	free(output);
	return ;
}
