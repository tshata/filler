/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 13:52:18 by tshata            #+#    #+#             */
/*   Updated: 2018/06/05 13:34:59 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;
	size_t	j;

	if ((s && f))
	{
		i = 0;
		j = ft_strlen((char *)(s));
		str = ft_strnew(j);
		if (str != NULL)
		{
			while (s[i])
			{
				str[i] = (*f)(s[i]);
				i++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (NULL);
}
