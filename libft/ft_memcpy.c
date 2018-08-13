/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:55:11 by tshata            #+#    #+#             */
/*   Updated: 2018/06/22 12:31:44 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	int	i;
	char	*ptr;
	char	*ptr1;

	ptr = (char *)dest;
	ptr1 = (char *)src;
	i = 0;
	while (i < n)
	{
		ptr[i] = ptr1[i];
		i++;
	}
	return (dest);
}
