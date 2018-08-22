/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:00:36 by tshata            #+#    #+#             */
/*   Updated: 2018/06/05 13:36:48 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2));
	if (!str)
		return (NULL);
	ft_strcpy(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	return (str);
}
