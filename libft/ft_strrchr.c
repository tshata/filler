/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:58:39 by tshata            #+#    #+#             */
/*   Updated: 2018/06/18 15:52:52 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;
	char	*str;

	j = ft_strlen((char *)s);
	str = (char *)s;
	while (j >= 0)
	{
		if (str[j] == '\0' && c == '\0')
		{
			return (str + j);
		}
		if (str[j] == (char)c)
		{
			return (str + j);
		}
		j--;
	}
	return (NULL);
}
