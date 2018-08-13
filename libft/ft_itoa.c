/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:46:30 by tshata            #+#    #+#             */
/*   Updated: 2018/06/07 12:55:19 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int value)
{
	int	len;

	len = 0;
	if (value < 0)
		len++;
	while (value)
	{
		len++;
		value /= 10;
	}
	return (len);
}

static char	*ft_intmin(void)
{
	char	*str;

	str = ft_strnew(ft_intlen(-2147483648));
	ft_strcpy(str, "-2147483648");
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		j;

	if (n == -2147483648)
		return (ft_intmin());
	str = ft_strnew(ft_intlen(n) + 1);
	j = ft_intlen(n) - 1;
	if (str)
	{
		if (n < 0)
		{
			str = ft_strnew(ft_intlen(n));
			str[0] = '-';
			n *= -1;
		}
		if (n == 0)
			*str = '0';
		while (n > 0)
		{
			str[j] = (n % 10) + '0';
			n /= 10;
			j--;
		}
	}
	return (str);
}
