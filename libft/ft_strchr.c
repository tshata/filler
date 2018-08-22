/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:58:29 by tshata            #+#    #+#             */
/*   Updated: 2018/06/22 12:28:42 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	con_c;
	int				i;
	int				len;

	i = 0;
	con_c = (unsigned char)c;
	if (c == '\0')
	{
		len = ft_strlen(s);
		return ((char *)s + len);
	}
	while (s[i] != '\0')
	{
		if (s[i] == con_c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
