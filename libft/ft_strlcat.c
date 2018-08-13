/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:01:16 by tshata            #+#    #+#             */
/*   Updated: 2018/06/22 11:45:57 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, int dest_size)
{
	int	i;
	int	destlen;
	int	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen((char *)(src));
	if (dest_size < destlen)
		return (dest_size + srclen);
	i = 0;
	while (src[i] != '\0' && (destlen + i + 1) < dest_size)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
