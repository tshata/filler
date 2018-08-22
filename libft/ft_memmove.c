/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:55:52 by tshata            #+#    #+#             */
/*   Updated: 2018/06/21 13:37:26 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*c_dest;
	char	*c_src;

	if (!dest && !src)
		return (NULL);
	c_dest = (char *)dest;
	c_src = (char *)src;
	if (dest >= src)
		while (len--)
			c_dest[len] = c_src[len];
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
