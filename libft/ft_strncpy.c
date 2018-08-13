/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:29:52 by tshata            #+#    #+#             */
/*   Updated: 2018/06/05 08:49:03 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (src[i])
			dest[i] = src[i];
		else
		{
			while (i < len)
			{
				dest[i] = '\0';
				i++;
			}
		}
		i++;
	}
	return (dest);
}
