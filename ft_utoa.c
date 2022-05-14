


#include "ft_printf.h"

char	*ft_utoa(unsigned nbr)
{
	int		i;
	char	*temp;
	char	*rtn;

	temp = ft_calloc(11, sizeof(int));
	if (temp == NULL)
		return (NULL);
	i = 10;
	while (--i >= 0)
	{
		temp[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	i = 0;
	while (temp[i++] == '0')
	rtn = ft_substr(temp, i, (ft_strlen(temp) - i));
	free(temp);
	return (rtn);
}