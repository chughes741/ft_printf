/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:57:54 by chughes           #+#    #+#             */
/*   Updated: 2022/05/01 09:57:58 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itox(int nbr)
{
	int		i;
	char	hexBase[] = "0123456789abcdef";
	char	*rtn;

	rtn = ft_calloc(9, sizeof(char));
	if (rtn == NULL)
		return (NULL);
	i = -1;
	while (++i < 8)
		rtn[i] = hexBase[((nbr >> (28 - (i * 4))) & 0xF)];
	return (rtn);
}
