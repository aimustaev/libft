/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:58:20 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 10:58:51 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_numb_char(int n)
{
	int				i;
	long			mn;
	int				nb;
	char			*str;

	i = 0;
	nb = n;
	mn = 1;
	while (nb > 0)
	{
		nb /= 10;
		if (nb > 0)
			mn *= 10;
		i++;
	}
	str = (char*)ft_memalloc(sizeof(char) * (i));
	while (mn > 0)
	{
		*(str++) = n / mn + '0';
		n %= mn;
		mn /= 10;
	}
	*(str) = 0;
	return (str - i);
}

char				*ft_itoa(int n)
{
	int				i;
	char			*str;

	i = 1;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		i = -1;
	str = ft_numb_char(n * i);
	if (i == -1)
		str = ft_strjoin(ft_strdup("-"), (char const *)str);
	str[ft_strlen(str)+1] = 0;
	return (str);
}
