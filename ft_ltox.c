/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:57:54 by chughes           #+#    #+#             */
/*   Updated: 2022/05/17 09:57:58 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltox(unsigned long nbr)
{
	int		i;
	char	hex_base[] = "0123456789abcdef";
	char	*temp;
	char	*rtn;

	temp = ft_calloc(17, sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = -1;
	while (++i < 8)
		temp[i] = hex_base[((nbr >> (60 - (i * 4))) & 0xF)];
	i = 0;
	while (temp[i++] == '0')
	rtn = ft_substr(temp, i, (ft_strlen(temp) - i));
	free(temp);
	return (rtn);
}
