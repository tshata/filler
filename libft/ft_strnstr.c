/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:13:20 by tshata            #+#    #+#             */
/*   Updated: 2018/06/18 15:59:00 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (haystack[i] == '\0' && needle[i] == '\0')
		return ((char *)haystack);
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while ((i + j < n) && (needle[j] == haystack[i + j]))
		{
			if (needle[++j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
