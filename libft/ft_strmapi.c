/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:44:43 by tshata            #+#    #+#             */
/*   Updated: 2018/06/05 13:35:32 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	j;
	int		index;
	char	*str;

	if ((s && f))
	{
		i = 0;
		index = 0;
		j = ft_strlen((char *)(s));
		str = ft_strnew(j);
		if (str != NULL)
		{
			while (s[i])
			{
				str[i] = (*f)(index++, s[i]);
				i++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (NULL);
}
