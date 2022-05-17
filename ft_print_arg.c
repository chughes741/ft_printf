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
	char	*temp;

	if (ft_strlen(str) >= (unsigned long)width)
		return (str);
	width -= ft_strlen(str);
	while ((width--) > 0)
	{
		temp = ft_strjoin(" ", str);
		free(str);
		str = temp;
	}
	return (str);
}

static void	ft_set_precision(char *str, int precision) // TODO check if needed
{
	while (str[precision])
	{
		str[precision] = '0';
		precision++;
	}
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

static char	*ft_format(t_mod *mod, char *str) // TODO strjoin memleak
{
	if (mod->precision >= 0)
		ft_set_precision(str, mod->precision);
	if (mod->width >= 0)
		str = ft_set_width(str, mod->width);
	if (mod->hash || mod->specifier == 'p')
		str = ft_strjoin("0x", str);
	if (mod->specifier == 'X')
		ft_strupper(str);
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

void	ft_print_arg(t_mod *mod, va_list args, int *count) // TODO
{
	char	*output;

	output = NULL;
	if (mod->specifier == 'c')
		ft_putchar_fd(va_arg(args, int), 1); // TODO count mismatch
	if (mod->specifier == 's')
		output = ft_strdup(va_arg(args, char *));
	if (mod->specifier == 'd' || mod->specifier == 'i')
		output = ft_itoa(va_arg(args, int));
	if (mod->specifier == 'u')
		output = ft_utoa(va_arg(args, unsigned int));
	if (mod->specifier == 'x' || mod->specifier == 'X')
		output = ft_itox(va_arg(args, unsigned int));
	if (mod->specifier == 'p') // TODO fix pointer print
		output = ft_ltox((va_arg(args, unsigned long)));
	if (output == NULL)
		return ;
	output = ft_format(mod, output);
	ft_putstr_fd(output, 1);
	*count += ft_strlen(output);
	free(output);
	return ;
}
