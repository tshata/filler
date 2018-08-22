/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:56:57 by tshata            #+#    #+#             */
/*   Updated: 2018/08/22 16:44:59 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s);
	str = ft_memalloc(i + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	ft_strcpy(str, s);
	return (str);
}
