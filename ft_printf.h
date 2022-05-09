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

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include <stdio.h>

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

typedef union argument
{
	char			c_arg;
	int				i_arg;
	unsigned int	u_arg;
} arg_union;

int			ft_printf(const char *form, ...); // Returns # of c printed
modifiers	*ft_get_mods(const char *format);
void		ft_print_arg(modifiers *mods, void *arg, int *count); // Returns # of c printed
char		*ft_itox(int nbr);

#endif
