/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:22:14 by chughes           #+#    #+#             */
/*   Updated: 2022/04/17 15:22:25 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct mod_list
{
	unsigned int	dash : 1;
	unsigned int	plus : 1;
	unsigned int	space : 1;
	unsigned int	hash : 1;
	unsigned int	zero : 1;
	int				width;
	int				precision;
	char			specifier;
	int				skip;
}					modifiers;

int			ft_printf(const char *format, ...);
modifiers	*get_mods(const char *format);
void		print_arg(modifiers *mods, va_list *arg);

#endif
